/*    using recursion to generate lucky numbers         */
/* https://codeforces.com/problemset/problem/122/A */

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

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

vector<ll> vect;
int calc_size(ll x)
{
	int cnt = 0;
	while (x > 0)
	{
		cnt++;
		x /= 10;
	}
	return cnt;
}

ll maxi = 2000;

void backtrack(ll num, int cnt4, int cnt7)
{
	if (num > maxi) return;
	if (num >= 1 && (calc_size(num) == cnt4 + cnt7)) {
		vect.push_back(num);

	}
	backtrack(num * 10 + 4, cnt4 + 1, cnt7);
	backtrack(num * 10 + 7, cnt4, cnt7 + 1);
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

		int num;
	cin >> num;
	backtrack(0, 0, 0); //constant time 

	for (auto i : vect)
	{
		if (num % i == 0)
		{
			cout << "YES";
			return  0;
		}
	}

	cout << "NO";



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

	
