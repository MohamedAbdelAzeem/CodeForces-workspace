#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>


using namespace std;



int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);

#endif // !ONLINE_JUDGE

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; 
	cin >> n;

	set<int> my_set;


	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		my_set.insert(x);
	}

	if (my_set.size() <= 1)
	{
		cout << "NO" << '\n';
	}
	else
	{
		auto it = my_set.begin();
		it++;
		cout << *it << '\n';
	}

	return 0;
}
