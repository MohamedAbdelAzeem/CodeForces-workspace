#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>


using namespace std;

#define endl '\n'

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);

#endif // !ONLINE_JUDGE

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    long long  n;
	cin >> n;
	while (n--)
	{
		int k;
		cin >> k;
		vector<int> my_vector(k);
		for (int i = 0; i < k; i++)
		{ 
			cin >> my_vector[i];
		}

		sort(my_vector.begin(), my_vector.end());
		bool ok = true;
		for (int i = 0; i < k - 1; i++)
		{
			ok &= (my_vector[i+1] - my_vector[i] <= 1);

		}

		if (ok)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	

	return 0;
}
