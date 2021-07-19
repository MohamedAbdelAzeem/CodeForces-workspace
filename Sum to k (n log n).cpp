
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;



int main()
{
    int n; 

    cin >> n; 
    
    int k;
    cin >> k;
    vector<int> my_vect(n);

    //looping form the last index to the first index 
    for (int i = 0 ; i < n; i++)  
    {
        cin >> my_vect[i];
    }

    bool ok = false;


    sort(my_vect.begin(), my_vect.end());
  
    int low_index = 0;
    int high_index = n - 1;
    while (low_index <= high_index)
    {
        // sum found
        if (my_vect[low_index] + my_vect[high_index] == k)
        {
            cout << "Yes" << endl;
            cout << my_vect[low_index] << " " << my_vect[high_index];
            ok = true;
            break;
        }

        if (my_vect[low_index] + my_vect[high_index] < k)
        {
            low_index++;
        
        }
        else
        {
            high_index--;
        }

    }
    if (!ok)
    {
        cout << "No";
    }

}

