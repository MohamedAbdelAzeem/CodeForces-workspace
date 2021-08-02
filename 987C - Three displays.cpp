/* https://codeforces.com/problemset/problem/987/C  */

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


	int n; 
	cin >> n;

	vector<int> s;
	vector<int> c;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		c.push_back(x);
	}




	int result = 1e9;
	for (int j = 0; j < n; j++)
	{
		int cost_i = 1e9;
		int cost_k = 1e9;
		for (int i = j - 1; i >= 0; i--)
		{
			if (s[i] < s[j])
			{
				cost_i = min(c[i], cost_i);
			}

		}

		for (int k = j + 1; k < n; k++)
		{
			if ( s[j] < s[k])
			{

				cost_k = min(c[k], cost_k);
			}

		}
		result = min(result, cost_i + c[j] + cost_k);
	}

	if (result == 1e9)
	{
		cout << -1;
	}
	else
	{
		cout << result;

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

