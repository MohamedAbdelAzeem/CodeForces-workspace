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

#ifdef __GNUC__
#define __rdtsc  __builtin_ia32_rdtsc
#else
#include <intrin.h>
#endif


typedef unsigned long long  uint64;
typedef unsigned char byte;				   
#define BIT_IS_SET(REG,BIT) bool( REG & (1ull<<BIT) )
#define SET_BIT(REG,BIT) (REG|=(1ull<<BIT))
/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG = (REG<<num) | (REG >> ((sizeof(REG) * 8)-num)) )



const int Permutaion_choice_1[57] =
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



const int Permutaion_choice_2[48] =
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

const int Initial_permutation[64] =
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

const int Final_permutation[64] =
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

const int expansion_table[48] =
{
	32,1,2,3,4,5,4,5,
	6,7,8,9,8,9,10,11,
	12,13,12,13,14,15,16,17,
	16,17,18,19,20,21,20,21,
	22,23,24,25,24,25,26,27,
	28,29,28,29,30,31,32,1
};

const int permutation_table[32] =
{
	16,7,20,21,29,12,28,17,
	1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25
};

int substition_boxes[8][64] = { {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13},{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };





const int Shift_Bits[16] =
{
	1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

uint64 permutation(uint64 in,  int size_in, int size_out, const int* per)
{
	uint64 out = 0;
	for (int i = 0; i < size_out; i++)
	{
	//	uint64 bit_value = in & (1ull << (size_in - per[i]));
		//if (bit_value) out |= 1ull << (size_out - i - 1);

		out |= (in >> (size_in - per[size_out - 1 - i]) & 1) << i;

	}
	return out;
}


uint64 rotate_l(uint64 in, int n)
{
	uint64 b0 = BIT_IS_SET(in, 27);
	uint64 b1 = BIT_IS_SET(in, 26);
	in = in << 1;
	in |= b0;
	if (n == 2)
	{
		in = in << 1;
		in |= b1;
	}
	return (in & (0x000000000fffffff));
}
uint64 array_of_keys[16];
void generate_keys(uint64 key)
{

	uint64 	key_p1 = permutation(key, 64, 56, Permutaion_choice_1);
	//printf("Key permutaion 1 ,  %016llX\n", key_p1);

	uint64 left = key_p1 >> 28;
	uint64 right = key_p1 & 0x000000000fffffff;

	//for iterative generating keys
	for (int i = 0; i < 16; i++)
	{
		uint64 key_res = 0;
		//rotate left and right
		left = rotate_l(left, Shift_Bits[i]);
		right = rotate_l(right, Shift_Bits[i]);

		//combine right and left
		uint64 key_sf = left;
		key_sf = key_sf << 28;
		key_sf |= right;
		//applying pc2 on the key and store keys
		uint64 roundKey = permutation(key_sf, 56, 48, Permutaion_choice_2);
		array_of_keys[i] = roundKey;
	}

}


uint64 hex_to_u64(string data)
{
	uint64 val = 0;
	for (int i = 0; i < 16; i++)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			val |= (uint64)(data[i] - '0') << ((15 - i) << 2);
		}
		else if (data[i] >= 'A' && data[i] <= 'F')
		{
			val |= (uint64)(data[i] - 'A' + 10) << ((15 - i) << 2);
		}
		else if (data[i] >= 'a' && data[i] <= 'f')
		{
			val |= (uint64)(data[i] - 'a' + 10) << ((15 - i) << 2);
		}
	}
	return val;
}
uint64 sbox(uint64 in)
{
	uint64 out = 0;
	for (int i = 0; i < 8; i++)
	{

		uint64 idx = (in >> (7 - i) * 6) & 0x3f;
		idx = idx >> 1 & 15 | (idx & 1) << 4 | idx & 0x20;
		out |= (uint64)substition_boxes[i][idx] << (7 - i) * 4;
	

	}
	return out;
}
uint64 input_rounds(uint64 input_initP , int op)
{
	uint64 input_left = input_initP >> 32;
	uint64 input_right = input_initP & 0x00000000ffffffff;

	for (int Round_Number = 0; Round_Number < 16; Round_Number++)
	{
		uint64 Round_Key = array_of_keys[abs(op - Round_Number)];
		uint64 input_exp = permutation(input_right, 32, 48, expansion_table);
		uint64 input_perm = permutation(sbox(input_exp ^ Round_Key), 32, 32, permutation_table);
		uint64 input_xor2 = input_perm ^ input_left;
		if (Round_Number != 15)
		{

			//swap
			uint64 temp = input_right; 
			input_right = input_xor2;
			input_left = temp;

		}
		else
		{
			input_left = input_xor2;
	
		}

	}
	uint64 cipher = (input_left << 32) | input_right;
	
	uint64 final_cipher = permutation(cipher, 64, 64, Final_permutation);


	return final_cipher;

}

uint64 des(uint64 input, const int op)
{
	

	uint64 input_initP = 0;
	uint64 result = 0;
	if (op == 1)
	{




		input_initP = permutation(input, 64, 64, Initial_permutation);
		
		result  = input_rounds(input_initP, 0 );

		

	}
	else if(op == 2)
	{
		input_initP = permutation(input, 64, 64, Initial_permutation);
		result = input_rounds(input_initP, 15 );
	}
	else
	{
		return 0;
	}

	return 	  result;
}




int main(int argc, char** argv)
{
	
	string key = argv[3];
	string input = argv[2];
	string op = argv[1];

	generate_keys(hex_to_u64(key));

	uint64  input64 = hex_to_u64(input);;


 /************************************************/

	long long t1 = 0;
	long long t2 = 0;
	if (op[0] == 'e')
	{

		 t1 = __rdtsc();

	   /***************************************************/
		uint64 final = des(input64, 1); 

	   /***************************************************/


		 t2 = __rdtsc();
	


		printf("cipher: %016llX\n", final);


	}
	else if (op[0] =='d')
	{
		t1 = __rdtsc();

		
		/***************************************************/
		uint64 final = des(input64, 2);

		/***************************************************/


		t2 = __rdtsc();



		printf("Plain: %016llX\n", final);
	}



	printf("Cycles: %lld\n", t2 - t1);

}


/************************************************************************************/

