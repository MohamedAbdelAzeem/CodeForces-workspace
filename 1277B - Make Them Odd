
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

#endif // !ONLINE_JUDGE

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		set<int> s;
		vector<int> vect;
		int count=0;
		int x;
		cin >> x;

		for (int i = 0; i < x; i++)
		{
			int y;
			cin >> y;
			if (y % 2 == 0)
			{
				//inserting negative numbers make the set in descending order
				s.insert(-y);
		
			}	
		}
		
		for (auto itr = s.begin(); itr != s.end(); itr++)
		{
			int x = *itr;
			count++;
			//inserting negative numbers bigger than the exsiting make the loop continue
			if (x / 2 % 2 == 0)
				s.insert(x / 2);
		}
		
		cout << count << endl;

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

