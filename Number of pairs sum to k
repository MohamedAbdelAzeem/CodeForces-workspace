
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <chrono>
#include <map>
#include <unordered_map>

//#define TIME_TEST  
using namespace std::chrono;
using namespace std;

int my_binarySearch(vector<int> arr, int size, int p, int* index);
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



	long n;

	cin >> n;

	long k;
	cin >> k;
	vector<int> my_vect(n);
	//counting number of occurances in the vector in a map 
	//key is the element
	// value is number of occurances 
	unordered_map<int, int> num_occurance;
	for (int i = 0; i < n; i++)
	{
		cin >> my_vect[i];
		num_occurance[my_vect[i]]++;
	}


	long counter = 0;;
	for (int i = 0; i < my_vect.size(); i++)
	{
		if (my_vect[i] == k - my_vect[i])
		{
			//is the element can make pair with itself ?
			//count all occurance of this element except the current 
			counter += (num_occurance[my_vect[i]] - 1);
		}
		else
		{
			//add num of occurances of matching element  to the counter 
			counter += (num_occurance[k - my_vect[i]]);
		}
	}
	//we counted all pairs twice (1,2) and (2,1)
	// divide by 2
	cout << counter/2;

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

