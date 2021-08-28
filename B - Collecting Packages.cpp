/*   https://codeforces.com/contest/1294/problem/B  */
/* lamda expression */
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
		vector<pair<int, int>> vect(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vect[i].first; // x 
			cin >> vect[i].second; // y
		}
 
		sort(vect.begin(), vect.end(), [](const pair<int, int>  a, const pair<int, int> b) {
 
			if (a.second + a.first < b.first + b.second )
			{
				return true;
			}
			else
			{
				return  false;
			}
		});
 
		pair<int, int> current = { 0,0 };
		string ans = "";
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if ((current.first < vect[i].first && current.second <= vect[i].second) 
			    ||( current.second < vect[i].second && current.first <= vect[i].first) )
			{
			
				if (current.first < vect[i].first )
				{
					int diff = vect[i].first - current.first;
					while(diff--) ans += 'R';
				}
				if (current.second < vect[i].second  )
				{
					int diff = vect[i].second - current.second;
					while (diff--) ans += 'U';
				}
				current = vect[i];
			}
			else
			{
				cout  << "NO" << endl;
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << "YES" << endl;
			cout << ans << endl;
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
 
