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


class TreeNode {
private:
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(int x )
	{
		data = x;
		left = NULL;
		right = NULL;
	}

	int getData()
	{
		return data;
	}

	TreeNode* getleft()
	{
		return left;
	}

	TreeNode* getright()
	{
		return right;
	}

	void setData(int x)
	{
		data = x;
	}

	void setLeft(TreeNode* ptr)
	{
		left = ptr; 
	}
	void setRight(TreeNode* ptr)
	{
		right = ptr;
	}
};

class Tree {
private:
	TreeNode* rootPtr;
	int TreeHeight;

public:
	Tree()
	{
		rootPtr = NULL;
		TreeHeight = 0;
	}
	
	bool IsEmpty()
	{
		return rootPtr == NULL;
	}

	TreeNode* getRootPtr()
	{
		return rootPtr;
	}
	void insert(int number)
	{
		if (IsEmpty())
		{
			rootPtr = new TreeNode(number);
			return;
		}

		TreeNode* CurrentNodePtr = rootPtr; 
		while (CurrentNodePtr != NULL)
		{
			int DataStored = CurrentNodePtr->getData();
			if (DataStored == number)
			{
				//value is already inserted 
				return;
			}
			else if (DataStored > number)
			{
				//number is going to be inserted in left branch of the tree
				if (CurrentNodePtr->getleft() == NULL)
				{
					//left branch is empty
					TreeNode* NewNodePtr = new TreeNode(number);
					CurrentNodePtr->setLeft(NewNodePtr);
					return;
				}
				else
				{
					//left branch is not empty 
					//move to the next node in the same branch 
					CurrentNodePtr = CurrentNodePtr->getleft();
				}
			}
			else if (DataStored < number)
			{
				//number is going to be inserted in right branch of the tree
				if (CurrentNodePtr->getright() == NULL)
				{
					//right branch is empty
					TreeNode* NewNodePtr = new TreeNode(number);
					CurrentNodePtr->setRight(NewNodePtr);
					return;
				}
				else
				{
					//left branch is not empty 
					//move to the next node in the same branch 
					CurrentNodePtr = CurrentNodePtr->getright();
				}
			}

		}
	}


	int getHeight(TreeNode* TreePtr)
	{
		if (TreePtr == NULL)
		{
			return 0;
		}
		else
		{
			int l = getHeight(TreePtr->getleft());
			int r = getHeight(TreePtr->getright());
			return max(l, r) + 1;
		}
	}


	bool IsBalanced(TreeNode* TreePtr)
	{
		TreeNode* Ptr = TreePtr;
		int left = 0;
		int right = 0;
		if (Ptr == NULL)
		{
			return 1;
		}
		/*if (Ptr->getleft() == NULL && Ptr->getright() == NULL)
		{
			return 1;
		}*/
		
		if (Ptr->getleft() != NULL)
		{
			left = getHeight(Ptr->getleft());
		}
		if (Ptr->getright() != NULL)
		{
			right = getHeight(Ptr->getright());
		}

		if (abs(left - right) <= 1 && IsBalanced(Ptr->getleft()) && IsBalanced(Ptr->getleft()))
		{
			//BALANCED 
			return 1;
		}
		else
		{
			//unBalanced
			return  0;
		}

	}
};




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


	
	Tree my_tree;

	int num;
	cin >> num;
	
	while (num--)
	{
		int x;
		cin >> x;
		my_tree.insert(x);
	}
	
	if(my_tree.IsBalanced(my_tree.getRootPtr()))
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
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

