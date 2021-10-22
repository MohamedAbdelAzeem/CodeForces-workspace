	#define _CRT_SECURE_NO_WARNINGS
	#include <iostream>
	#include <vector>
	#include <string>
	#include <queue>
	#include <stack>
	#include <chrono>
	#include <map>
	#include <unordered_map>
	#include <math.h>
	#include <set>
	#include <algorithm>
	#include <iostream>
	#include <fstream>

	#define IO std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	typedef long long int ll;

	#define  endl  '\n'

	//#define TIME_TEST  
	using namespace std::chrono;
	using namespace std;


	int get_size(int* s)
	{
		int size = 0;
		for (int i = 0; s[i] != '\0'; i++)
		{
			size++;
		}
		return size;
	}


	void swap(int* xp, int* yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	int count_digits(int n)
	{
		int count = 0;
		do {
			n /= 10;
			++count;
		} while (n != 0);
		return count;
	}




void caesar_Encrypt(const char* unsecured_data_ptr, char* secured_data_ptr, int key)
{
	for (int i = 0; unsecured_data_ptr[i] != '\0'; ++i)
	{
		secured_data_ptr[i] = unsecured_data_ptr[i];
	}
	char ch;
	for (int i = 0; secured_data_ptr[i] != '\0'; ++i) {
		ch = secured_data_ptr[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;
			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}
			secured_data_ptr[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;
			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}
			secured_data_ptr[i] = ch;
		}
	}

}


void caesar_Decrypt( char* unsecured_data_ptr,const  char* secured_data_ptr, int key)
{
	for (int i = 0; unsecured_data_ptr[i] != '\0'; ++i)
	{
		unsecured_data_ptr[i] = secured_data_ptr[i];
	}
	for (int i = 0; unsecured_data_ptr[i] != '\0'; ++i) {
		char ch;
		ch = unsecured_data_ptr[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch - key;
			if (ch < 'a') {
				ch = ch + 'z' - 'a' + 1;
			}
			unsecured_data_ptr[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch - key;
			if (ch < 'A') {
				ch = ch + 'Z' - 'A' + 1;
			}
			unsecured_data_ptr[i] = ch;
		}
	}
}




int main()
{
#ifdef TIME_TEST
	// Get starting timepoint
	auto start = high_resolution_clock::now();
#endif // TIME_TEST
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE*/

	IO

	   

	char message[100] = "axzd";

	char secured_message[100] = {};
	int key = 4;
	char ch;

	caesar_Encrypt(message, secured_message, key);

	cout << "message after encryption:" << endl;
	for (int i = 0; secured_message[i] != '\0'; ++i)
	{
		cout << secured_message[i];
	}

	cout << endl;
	char decrypted_message[100];
	//symmetric cipher model so key is shared between the sender and the recipient
	caesar_Decrypt(decrypted_message, secured_message, key);
	cout << "message after decryption:" << endl;
	for (int i = 0; decrypted_message[i] != '\0'; ++i)
	{
		cout << decrypted_message[i];
	}





/************************************************************************/
#ifdef TIME_TEST	
	// Get ending timepoint
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << endl;
	cout << "Time taken "
		<< duration.count() / 1000.0 << " milliseconds" << endl;
#endif // TIME_TEST



	return 0;
}
