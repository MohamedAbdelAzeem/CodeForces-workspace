/*   https://codeforces.com/contest/352/problem/A    */
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
	map<int, int> mp;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		++mp[x];
	}


	//number must be divisble by the two divisors of 90 -> 9 * 10 together
	if (mp[0] == 0)
	{
		//number must be divisble by 10 --> so it must end with zero
		//number of zeros is equal zero number is not divible by 10  -> I cant construct the number
		cout << -1;
	}
	else if (mp[5] < 9)
	{
		//if number of 5'S  if (5*N) < 9 then (5*N) % 9 != 0 -> I cant construct the number
		//there is at least one zero and 0%90 = 0  
		cout << 0; 
	}
	else
	{
		//largest number divisble by 9  and smaller than mp[5]
		//I need to print number of 5'S that divisble by 9
		//if (5*n)%9 == 0  so n must be n%9 ==0 
		// i need n that is divible by 9
		int cunt = mp[5] - mp[5] % 9;

		cout << string(cunt, '5') + string(mp[0], '0');
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

	
