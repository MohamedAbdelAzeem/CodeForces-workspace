/* https://codeforces.com/contest/584/problem/A    */
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

#define IO 	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

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

		long int x, y, n, i, t;
	while (cin >> n >> t) {
		if (n == 1 && t == 10)  //any single digit integer is not divsible by 10 
			cout << "-1\n";
		else if (n >= 2 && t == 10) // any integer is divisble by 10 if first digit is 0  ex: 1110 / 10 == 1111
		{
			for (i = 1; i < n; i++) {
				cout << "1";
			}
			cout << "0\n";
		}
		else   //any integer more than 1 digits is divisble by x if all digits is x  ex 777 / 7 = 111
		{
			for (i = 1; i <= n; i++) {
				cout << t;
			}
			cout << endl;
		}
	} 
	
	
	



#ifdef TIME_TEST
	// Get ending timepoint
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << endl;
	cout << "Time taken "
		<< duration.count()/1000.0 << " milliseconds" << endl;	
#endif // TIME_TEST



	return 0;
}

	
