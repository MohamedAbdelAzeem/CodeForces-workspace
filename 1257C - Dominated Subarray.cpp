/*   https://codeforces.com/contest/1257/problem/C   */

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

		int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<int,int> mp;
		vector<int> vect(n);

		for (int i = 0; i < n; i++)
		{
			cin >> vect[i];
			auto it = mp.find(vect[i]);
			if (it == mp.end())
			{
				mp[vect[i]] = i;
			}
			
		}

		if (n == 1)
		{
			cout << -1 << endl;
			continue;
		}

		int size = n + 1;
		for (int i = 0; i < n; i++)
		{
			if (i > mp[vect[i]] )
			{
				size = min(size, i - mp[vect[i]] + 1);
				mp[vect[i]] = i;
			}
		}
		if (size == n+1)
		{
			cout << -1 << endl;
		}
		else
		cout << size << endl;


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

	
