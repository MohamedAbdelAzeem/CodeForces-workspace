/* https://codeforces.com/problemset/problem/155/B */

/* sorting using lamda expression */

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

		int n;
	cin >> n;
	int num_counts = 1;
	vector<pair<int, int>> vect(n);
	for (int i = 0; i < n; i++) {

		cin >> vect[i].first;
		cin >> vect[i].second;
	}

  //true means 'a' comes first in the array .
	sort(vect.begin(), vect.end(), [](const pair<int, int>  a, const pair<int, int> b) {

		if (a.second > b.second)
		{
			return true;
		}
		else if (a.second == b.second)
		{
			if (a.first > b.first)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}


		});

	int index = 0;
	int score = 0; 
	while (num_counts > 0 && index < n )
	{
		score += vect[index].first;
		num_counts += vect[index].second;

		index++;
		num_counts--;
	}

	cout << score;
	

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

	
