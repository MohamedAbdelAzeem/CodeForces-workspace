/* https://codeforces.com/problemset/problem/1506/E */

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


	int t;
	cin >> t;
	while (t--)
	{
		int  n; 
		cin >> n; 
		vector<int> q(n);
		vector<int> max(n);
		vector<int> min(n);
		
		set<int> num;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x; 
			q[i]=x ;
		}
		
		for (int i = 1; i <= n; i++)
		{	
			num.insert(i);
		}
		//max permutaion
		for (int i = 0; i < n; i++)
		{

			auto it = num.find(q[i]);
			if (it != num.end()) //num is found
			{
				max[i] = q[i];
				num.erase(it);

			}
			else
			{
				//auto it1  = lower_bound(nun.begin(), num.end(), q[i]); got time limit exceded
				auto it1 = num.lower_bound(q[i]);
				it1--;
				max[i] = *it1;
				num.erase(it1);

			}
		}



		for (int i = 1; i <= n; i++)
		{
			num.insert(i);
		}
		for (int i = 0; i < n; i++)
		{

			auto it = num.find(q[i]);
			if (it != num.end()) //num is found
			{
				min[i] = q[i];
				num.erase(it);

			}
			else
			{
				
				min[i] = *num.begin();
				num.erase(num.begin());
			}
		}


		for (int i = 0; i < n; i++)
		{
			cout << min[i] << " ";
		}
		cout << endl;

		for (int j = 0; j < n; j++)
		{ 
			cout << max[j] <<  " " ;
		}
	

		cout << endl;
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

	
