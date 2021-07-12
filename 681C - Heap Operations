/*https://codeforces.com/problemset/problem/681/C*/
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

	string y;
	getline(cin, y);

	int min = 0;
	priority_queue<int> pq;
	queue<pair<string, int>> ans;

	const string INSERT = "insert";
	const string REMOVE = "removeMin";
	const string GETMIN = "getMin";

	const long NO_X = 2e9;

	for(int i = 0 ; i < n ; i++)
	{
		string x;
		cin >> x;
	
		if (x == INSERT)
		{
			int num;
			cin >> num;
			pq.push(-num);
			ans.push(make_pair(INSERT, num ));
		}
		else if (x == REMOVE)
		{
			if (!pq.empty())
			{
				pq.pop();
				ans.push(make_pair(REMOVE, NO_X));
			
			}
			else
			{
				//Queue is empty so we 
				ans.push(make_pair(INSERT, 0  ));
				ans.push(make_pair(REMOVE, NO_X));
			}
		}
		else if (x == GETMIN)
		{
			int num;
			cin >> num;
			while (!pq.empty() && -pq.top() < num)
			{
				
				pq.pop();
				ans.push(make_pair(REMOVE, NO_X));
			}

			if (pq.empty() || -pq.top() > num)
			{
				pq.push(-num);
				ans.push(make_pair(INSERT, num));
			}
			ans.push(make_pair(GETMIN, num));
		}
	}


	cout << ans.size() << endl;
	while (!ans.empty())
	{
		auto x = ans.front();
		cout << x.first;
		if (x.second != NO_X)
		{
			cout << " " << x.second;
		}
		cout << endl;
 		ans.pop();
	}


#ifdef TIME_TEST
	// Get ending timepoint
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << endl;
	cout << "Time taken "
		<< duration.count() << " microseconds" << endl;
#endif // TIME_TEST



	return 0;
}

