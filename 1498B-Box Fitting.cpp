/*  https://codeforces.com/problemset/problem/1498/B    */

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
	while (n--)
	{
        int n, w;
        int box_width;
        cin >> n >> box_width;

        multiset<int> st;
        for (int i = 0; i < n; i++) {
            cin >> w;
            st.insert(w);
        }

        int height = 1, space_left = box_width;
        //debug to understand
        while (!st.empty()) {
            auto it = st.upper_bound(space_left);
            if (it != st.begin()) {
                it--;  
                // we decrement to get the second large number of the largest doesnt fit 
                int val = *it;
                space_left -= val;
                st.erase(it);
            }
            else {   //if space_left == 0  upper_bound returns the number larger than 0 which is the smallest number in the set
                space_left = box_width;
                height++;
            }
        }

        cout << height << endl;
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

