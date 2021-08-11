/*  bitmask application    */


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

	//print all subsets that sum to k

	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> vect(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vect[i];
	}

	int mask = 0;
	int ans = 0;
	for (int i = 0; i < (2 << n) ; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if ((i >> j) & 1)
			{
				sum += vect[j];
			}
		}
		if (sum == k)
		{
			ans++;

			int mask = i;
			for (int j = 0; j < n; j++) cout << mask % 2 << " ", mask /= 2;
			cout << " " << sum << endl;
		}
	}
	cout << ans;









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

	
