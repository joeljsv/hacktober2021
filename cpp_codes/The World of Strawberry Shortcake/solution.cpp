#include <bits/stdc++.h>

using namespace std;

int main() {
  //getting test cases
  int t;
  cin >> t;
  while (t--) {
    //getting input n 
    long long n;
    cin >> n;
    //applying the logic 
    cout << max(6LL, n + 1) / 2 * 5 << '\n';
  }
}