
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



int is_stable(string s , stack<char>& stackRef)
{

	int ret = 0;

	for (int i = 0 ; i < s.size(); i++)
	{

		char c = s[i];
		if (c == '{')
			stackRef.push(c);
		else if (!stackRef.empty() && stackRef.top() == '{')
			//c = } and there is a matching at the top of the stack
			stackRef.pop();
		else {
			//c = } and there is no matching at the top of the stack
			ret++;
			stackRef.push('{');
		}
	}
	ret += stackRef.size() / 2;
	return ret;
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

#endif // !ONLINE_JUDGE

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);


	int test_counter = 0;
	while (1)
	{
		test_counter++;
		string  x;
		cin >> x;
		if (x[0] == '-')
			break;

		stack<char> my_stack;
		int result = is_stable(x, my_stack);

		cout << test_counter << ". " << result << '\n';

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

