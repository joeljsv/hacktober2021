// CPP program to find minimum sum of product
// of two arrays with k operations allowed on
// first array.
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the minimum product
int minproduct(int a[], int b[], int n, int k)
{
    int diff = 0, res = 0;
    int temp;
    for (int i = 0; i < n; i++) {
 
        // Find product of current elements and update
        // result.
        int pro = a[i] * b[i];
        res = res + pro;
 
        // If both product and b[i] are negative,
        // we must increase value of a[i] to minimize
        // result.
        if (pro < 0 && b[i] < 0)
            temp = (a[i] + 2 * k) * b[i];
 
        // If both product and a[i] are negative,
        // we must decrease value of a[i] to minimize
        // result.
        else if (pro < 0 && a[i] < 0)
            temp = (a[i] - 2 * k) * b[i];
 
        // Similar to above two cases for positive
        // product.
        else if (pro > 0 && a[i] < 0)
            temp = (a[i] + 2 * k) * b[i];
        else if (pro > 0 && a[i] > 0)
            temp = (a[i] - 2 * k) * b[i];
 
        // Check if current difference becomes higher
        // than the maximum difference so far.
        int d = abs(pro - temp);
        if (d > diff)
            diff = d;       
    }
 
    return res - diff;
}
 
// Driver function
int main()
{
    int a[] = { 2, 3, 4, 5, 4 };
    int b[] = { 3, 4, 2, 3, 2 };
    int n = 5, k = 3;
    cout << minproduct(a, b, n, k)
         << endl;
    return 0;
}
