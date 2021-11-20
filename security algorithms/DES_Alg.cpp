	/*
	Author: mohamed Abdelazeem
	C++ program to implement Data Encryption Standard (DES)
*/

#include <iostream>
#include <string>  
#include <vector>
#include <sstream>
#include <bitset>
#include <map>
#include <cmath>
using namespace std;

typedef unsigned long int  uint64;

void Des_Encrypt(string Input_Plain_Text_Str, string Input_Key_Str, string& Outout_Cipher_Text_Str);
void Des_Decrypt(string Input_Cipher_Text_Str, string Input_Key_Str, string& Outout_Plain_Text_Str);
string permutaion(string Input_Str, vector<int>& Permutaion_table);
string hex_str_to_bin_str(const string& hex);
const char* hex_char_to_bin(char c);
void split(const string str, string& Right_Half, string& Left_Half);
string Generate_Round_Key(string& Input_Key_Str_Bin, int Round_Number);
void shift_Left(string& str, int shift_Amount);
string Cipher_Xor(string str1, string str2);
string substitute(string plaintext);

char convert_bin2hex(string bits);
string getHex(string rowresult);

vector<int> Permutaion_choice_1 =
{
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
};

vector<int> Shift_Bits =
{
	1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

vector<int> Permutaion_choice_2 =
{
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
};

vector<int> Initial_permutation =
{
	58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17,9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7
};

vector<int> Final_permutation =
{
	40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33,1,41,9,49,17,57,25
};

vector<int> expansion_table =
{
	32,1,2,3,4,5,4,5,
	6,7,8,9,8,9,10,11,
	12,13,12,13,14,15,16,17,
	16,17,18,19,20,21,20,21,
	22,23,24,25,24,25,26,27,
	28,29,28,29,30,31,32,1
};

vector<int> permutation_table =
{
	16,7,20,21,29,12,28,17,
	1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25
};

int substition_boxes[8][4][16] =
{ {
	14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
	0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
	4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
	15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
},
{
	15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
	3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
	0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
	13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
},
{
	10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
	13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
	13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
	1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
},
{
	7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
	13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
	10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
	3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
},
{
	2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
	14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
	4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
	11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
},
{
	12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
	10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
	9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
	4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
},
{
	4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
	13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
	1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
	6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
},
{
	13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
	1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
	7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
	2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
} };

int main(int argc, char** argv)
{

	/* Encrypt variables */
	string Input_Plain_Text_Str;
	string Outout_Cipher_Text_Str;
	/* Decrypt variables */
	string Input_Cipher_Text_Str;
	string Output_Plain_Text_Str;
	/* Key variables */
	string Input_Key_Str;
	/* Operation variable  */
	string Operation;

	/* input Operation */
	Operation = argv[1];




	//cout << Operation << endl;


	/* Check Operation */
	if (Operation == "encrypt")
	{
		/* Input plaintext */
		Input_Plain_Text_Str = argv[2];

		/* Input Key */
		Input_Key_Str = argv[3];
		//cout << Input_Plain_Text_Str << endl;
		//cout << Input_Key_Str << endl;
		Des_Encrypt(Input_Plain_Text_Str, Input_Key_Str, Outout_Cipher_Text_Str);
		cout << "chiper: " << Outout_Cipher_Text_Str;
	}
	else if (Operation == "decrypt")
	{
		/* Input plaintext */
		Input_Cipher_Text_Str = argv[2];

		/* Input Key */
		Input_Key_Str = argv[3];
		//cout << Input_Cipher_Text_Str << endl;
		//cout << Input_Key_Str << endl;
		Des_Decrypt(Input_Cipher_Text_Str, Input_Key_Str, Output_Plain_Text_Str);
		//cout << "Final output " << Output_Plain_Text_Str;
		cout <<"plain: " << Output_Plain_Text_Str;
	}



}


/************************************************************************************/


void Des_Encrypt(string Input_Plain_Text_Str_64, string Input_Key_Str_64, string& Outout_Cipher_Text_Str)
{

	string Round_Key;
	string Round_Key_Hex;
	/* Input format to binary format */
	string Input_Plain_Text_Str_Bin = hex_str_to_bin_str(Input_Plain_Text_Str_64);
	string Input_Key_Str_Bin = hex_str_to_bin_str(Input_Key_Str_64);

	/* Key generation : */
	 /* Permuted choice 1  */
	/* Convert 64 bit key to 56 bit key  */
	string Key_56 = permutaion(Input_Key_Str_Bin, Permutaion_choice_1);


	/* Plaintext initial permutaion  */
	string Plain_Text = permutaion(Input_Plain_Text_Str_Bin, Initial_permutation);

	//cout << Plain_Text << endl;

	string Plain_Text_Right_Half;
	string Plain_Text_Left_Half;

	split(Plain_Text, Plain_Text_Right_Half, Plain_Text_Left_Half);

	//cout << Plain_Text_Right_Half << endl;

	/* Des implements 16 similar rounds  */
	for (int Round_Number = 0; Round_Number < 16; Round_Number++)
	{
		/* Generate Round Key */
		Round_Key = Generate_Round_Key(Key_56, Round_Number);

		//cout << Round_Key << endl;
		//Round_Key_Hex = getHex(Round_Key);
		//cout << Round_Key << " Round Number" << Round_Number << endl;
		//cout << Round_Key_Hex << " Round Number" << Round_Number   << endl;


		 //cout << getHex(Plain_Text_Left_Half)<< " " << getHex(Plain_Text_Right_Half) << " Round Number " << Round_Number << endl;


		/* Function F */
		string Plain_Text_48 = permutaion(Plain_Text_Right_Half, expansion_table);
		/* Xor */
		string Plain_text_xor_Round_key = Cipher_Xor(Plain_Text_48, Round_Key);

		string Plain_substitute = substitute(Plain_text_xor_Round_key);

		string Plain_function_output = permutaion(Plain_substitute, permutation_table);


		string mixer_output = Cipher_Xor(Plain_function_output, Plain_Text_Left_Half);


		if (Round_Number != 15)
		{
			string temp = Plain_Text_Right_Half;
			Plain_Text_Right_Half = mixer_output;
			Plain_Text_Left_Half = temp;
		}
		else
		{
			Plain_Text_Left_Half = mixer_output;
		}

	}

	string chiper_text_combined = Plain_Text_Left_Half + Plain_Text_Right_Half;
	//	cout << "After combining " << getHex(chiper_text_combined) << endl;


	string Final_cipher_text = permutaion(chiper_text_combined, Final_permutation);

	Outout_Cipher_Text_Str = getHex(Final_cipher_text);
}


string substitute(string plaintext)
{
	string result = "";
	map<char, bool> my_map;
	my_map['1'] = 1;
	my_map['0'] = 0;

	map<bool, char> btoc;
	btoc[1] = '1';
	btoc[0] = '0';
	for (int index = 0; index < 8; index++)
	{
		int row_index = 2 * my_map[plaintext[index * 6]] + my_map[plaintext[index * 6 + 5]];
		int col_index = 8 * my_map[plaintext[index * 6 + 1]] + 4 * my_map[plaintext[index * 6 + 2]] + 2 * my_map[plaintext[index * 6 + 3]] + my_map[plaintext[index * 6 + 4]];

		//cout << row_index << " " << col_index << endl;

		int table_value = substition_boxes[index][row_index][col_index];

		//cout << table_value << endl;

		result += btoc[table_value / 8];
		table_value = table_value % 8;

		result += btoc[table_value / 4];
		table_value = table_value % 4;

		result += btoc[table_value / 2];
		table_value = table_value % 2;

		result += btoc[table_value];


	}
	return result;
}


string Cipher_Xor(string str1, string str2) {
	string result = "";
	map<char, bool> my_map;
	my_map['1'] = 1;
	my_map['0'] = 0;
	int string_size = str1.size();
	for (rsize_t index = 0; index < string_size; index++)
	{
		bool x = my_map[str1[index]] ^ my_map[str2[index]];
		if (x)
		{
			result += '1';
		}
		else
		{
			result += '0';
		}
	}
	return result;
}


string Generate_Round_Key(string& Input_Key_Str_Bin, int Round_Number)
{


	//cout << Key_56 << endl;

	string Key_Right_Half;
	string Key_Left_Half;

	/* Splitting */
	split(Input_Key_Str_Bin, Key_Right_Half, Key_Left_Half);

	//cout << Input_Key_Str_Bin << endl;
	//cout << Key_Right_Half << endl;
	//cout << Key_Left_Half << endl;

	/* Shift left process  */
	int shift_Amount = Shift_Bits[Round_Number];

	shift_Left(Key_Right_Half, shift_Amount);
	shift_Left(Key_Left_Half, shift_Amount);

	//cout << Key_Right_Half << endl;
	//cout << Key_Left_Half << endl;

	/* combination */
	string Shifted_Key_56 = Key_Left_Half + Key_Right_Half;

	/* prepare for nexr round */
	Input_Key_Str_Bin = Shifted_Key_56;
	//cout << Shifted_Key_56 << endl;
	/* permutatiom choice 2 */
	string Key_48 = permutaion(Shifted_Key_56, Permutaion_choice_2);

	return Key_48;

}

void shift_Left(string& str, int shift_Amount)
{
	int str_size = str.size();
	string shifted_str = "";
	for (int shift_round = 0; shift_round < shift_Amount; shift_round++)
	{
		char most_sig_char = str[0];
		for (int index = 1; index < str_size; index++)
		{
			shifted_str += str[index];
		}
		shifted_str += most_sig_char;
		str = shifted_str;
		shifted_str = "";
	}

}
void Des_Decrypt(string Input_Cipher_Text_Str, string Input_Key_Str, string& Output_Plain_Text_Str)
{
	string Round_Key;
	string Round_Key_Hex;
	/* Input format to binary format */
	string Input_Plain_Text_Str_Bin = hex_str_to_bin_str(Input_Cipher_Text_Str);
	string Input_Key_Str_Bin = hex_str_to_bin_str(Input_Key_Str);

	/* Key generation : */
	 /* Permuted choice 1  */
	/* Convert 64 bit key to 56 bit key  */
	string Key_56 = permutaion(Input_Key_Str_Bin, Permutaion_choice_1);


	/* Plaintext initial permutaion  */
	string Plain_Text = permutaion(Input_Plain_Text_Str_Bin, Initial_permutation);

	//cout << Plain_Text << endl;

	string Plain_Text_Right_Half;
	string Plain_Text_Left_Half;

	split(Plain_Text, Plain_Text_Right_Half, Plain_Text_Left_Half);

	//cout << Plain_Text_Right_Half << endl;
	vector<string> array_of_keys;
	for (int index = 0; index < 16; index++)
	{
		/* Generate Round Key */
		string key = Generate_Round_Key(Key_56, index);

		array_of_keys.push_back(key);
	}
	//cout << getHex(Plain_Text_Left_Half) << " " << getHex(Plain_Text_Right_Half) << endl;
	/* Des implements 16 similar rounds  */
	for (int Round_Number = 0; Round_Number < 16; Round_Number++)
	{
		/* Generate Round Key */
		Round_Key = array_of_keys[15 - Round_Number];

		//cout << Round_Key << endl;
		Round_Key_Hex = getHex(Round_Key);
		//cout << Round_Key << " Round Number" << Round_Number << endl;
		//cout << Round_Key_Hex << " Round Number" << Round_Number   << endl;



		/* Function F */
		string Plain_Text_48 = permutaion(Plain_Text_Right_Half, expansion_table);
		/* Xor */
		string Plain_text_xor_Round_key = Cipher_Xor(Plain_Text_48, Round_Key);

		string Plain_substitute = substitute(Plain_text_xor_Round_key);

		string Plain_function_output = permutaion(Plain_substitute, permutation_table);


		string mixer_output = Cipher_Xor(Plain_function_output, Plain_Text_Left_Half);


		if (Round_Number != 15)
		{
			string temp = Plain_Text_Right_Half;
			Plain_Text_Right_Half = mixer_output;
			Plain_Text_Left_Half = temp;
		}
		else
		{
			Plain_Text_Left_Half = mixer_output;
		}


		//cout << getHex(Plain_Text_Left_Half) << " " << getHex(Plain_Text_Right_Half) << " " << Round_Key_Hex << " Round Number " << Round_Number << endl;

	}

	string chiper_text_combined = Plain_Text_Left_Half + Plain_Text_Right_Half;
	//	cout << "After combining " << getHex(chiper_text_combined) << endl;


	string Final_cipher_text = permutaion(chiper_text_combined, Final_permutation);

	Output_Plain_Text_Str = getHex(Final_cipher_text);
}






const char* hex_char_to_bin(char c)
{
	/* Hexdecimals are uppercase always  */
	switch (toupper(c))
	{
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	}
	return 0;
}

string hex_str_to_bin_str(const string& hex)
{
	// TODO use a loop from <algorithm> or smth
	string binary_Str;
	for (unsigned Str_Index = 0; Str_Index != hex.length(); ++Str_Index)
	{
		binary_Str += hex_char_to_bin(hex[Str_Index]);
	}

	return binary_Str;
}


string permutaion(string Input_Str, vector<int>& Permutaion_table)
{
	string permuted = "";

	unsigned int table_size = Permutaion_table.size();
	//cout << table_size << endl;
	for (unsigned int table_index = 0; table_index < table_size; table_index++)
	{
		int char_index = Permutaion_table[table_index] - 1;
		permuted += Input_Str[char_index];
	}
	return permuted;
}



void split(const string str, string& Right_Half, string& Left_Half)
{
	for (size_t index = 0; index < str.size(); index++)
	{
		if (index < str.size() / 2)
		{
			Left_Half += str[index];
		}
		else
		{
			Right_Half += str[index];
		}
	}
}

const char lookuparrbin2hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

char convert_bin2hex(string bits)
{
	unsigned int result = 0;
	unsigned int shifter0 = 0;
	unsigned int shifter1 = 1;

	for (int n = 0; n < bits.length(); n++)
	{
		result <<= 1; //shift result to the left by 1
		if (bits[n] == '1') result = (result | shifter1);
		else result = (result | shifter0);
	}
	return lookuparrbin2hex[result];
}


string getHex(string rowresult)
{
	std::string endresult = "";
	for (int i = 0; i < rowresult.length(); i = i + 4)
	{
		endresult += convert_bin2hex(rowresult.substr(i, 4));
	}
	return endresult;
}
