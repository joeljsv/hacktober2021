//Nikita12200
//to find maximum subarray sum
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; //number elements in array
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int cs = 0, ms = 0; //cs=current sum, ms=maximum sum so far
    //kadane's algorithm
    for (int i = 0; i < n; i++)
    {
        cs = cs + arr[i];
        if (cs < 0)
        {
            cs = 0;
        }
        ms = max(cs, ms);
    }
    cout << "Maximum subarray sum is : " << ms << endl;
    return 0;
}