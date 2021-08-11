/*  bitmask application    */
/*  https://codeforces.com/problemset/problem/114/B  */
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
	int m;
	cin >> m;

	vector<string> v(n);

	map<string, int> idx;
	bool bad[20][20] = {} ; 


	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		idx[v[i]] = i;//make an index for every person
	}
	
	//the idea of this matrix that if i gave it 2 indices it tells
	// me if the pair is valid or not 
	for (int j = 0; j < m; j++)
	{
		string a, b;
		cin >> a >> b;
		/*
		*  it puts 1 at the pair from the 2 sides
			0 0 1 0 			 
			0 0 0 0
			1 0 0 0
			0 0 0 0
		*/
		bad[idx[a]][idx[b]] = true;
		bad[idx[b]][idx[a]] = true;
	}
	
	vector<string> ans;
	//1<<n == 2 ^ n 
	for (int msk = 1; msk < (1 << n); msk++)
	{
		vector<string> subset;
		for (int i = 0; i < n; i++)
		{
			if ((msk & (1 << i)))
			{
				subset.push_back(v[i]);
			}
		}

		//comparing pairs 
		bool No = false;
		for (auto x : subset)
		{
			for (auto y : subset)
			{
				if (bad[idx[x]][idx[y]])
				{
					No = true;
					break;
				}
			
			}	
			if (No)
				break;

		}

		if (!No)
		{
			//subset is valid
			if (ans.size() < subset.size())
			{
				ans = subset;
			}
		}
	
	}

	cout << ans.size() << endl ;
	sort(ans.begin(), ans.end());
	for (auto x : ans)
	{
		cout << x << endl;
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

	
