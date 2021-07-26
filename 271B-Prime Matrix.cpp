
/*   https://codeforces.com/problemset/problem/271/B    */

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

typedef long long int ll;

#define  endl  '\n'

//#define TIME_TEST  
using namespace std::chrono;
using namespace std;



vector<int> primes;




int isPrimeNumber(int n) {
	bool isPrime = true;

	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
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

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_rows;
	cin >> num_rows;
	int num_col; 
	cin >> num_col;


	//generate prime numbers
	bool isPrime;
	for (int n = 2; n < 1e5 + 5; n++)
	{
		// isPrime will be true for prime numbers
		isPrime = isPrimeNumber(n);

		if (isPrime == true)
			primes.push_back(n);
	}

	vector<vector<int>> prime_diff(num_rows);
	
	
	
	int min_row = 1e9;
	for (int i = 0; i < num_rows; i++)
	{
		int sum_row = 0;
		for (int j = 0; j < num_col; j++)
		{
			int x;
			cin >> x;
			auto nearestPrime = lower_bound(primes.begin(), primes.end() , x ); //return iterator to the nearest prime number
			prime_diff[i].push_back(*nearestPrime - x);
			sum_row += *nearestPrime - x;
		}
		
		min_row = min(min_row, sum_row);
	}

	int min_col = 1e9;
	for (int i = 0; i < num_col; i++)
	{
		int sum_col = 0;
		for (int j = 0; j < num_rows; j++)
		{
			sum_col += prime_diff[j][i];
		}

		min_col = min(min_col, sum_col);
	}


	cout << min(min_col, min_row);



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

