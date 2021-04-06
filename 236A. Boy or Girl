
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
 
	string input_str;
	cin >> input_str;

	int str_size = input_str.size();
	vector<char> str(123	);


	for (int i = 0; i < input_str.size(); i++)
	{
		str[input_str[i]] = 1;
	}

	int counter = 0;
	for (int i = 0; i < str.size() ; i++)
	{
		if (str[i] == 1)
		{
			counter++;
		}
	}

	if (counter % 2 == 0)
	{
		cout << "CHAT WITH HER!";
	}
	else
	{
		cout << "IGNORE HIM!";
	}



	return 0;
}
