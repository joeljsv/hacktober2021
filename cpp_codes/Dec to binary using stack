#include<iostream>
#include<stack>
using namespace std;
void dec_to_bin(int number) {
   stack<int> stk;
   while(number > 0) {
      int rem = number % 2; //take remainder
      number = number / 2;
      stk.push(rem);
   }
   while(!stk.empty()) {
      int item;
      item = stk.top();
      stk.pop();
      cout << item;
   }
}
main() {
   int num;
   cout << "Enter a number: ";
   cin >> num;
   dec_to_bin(num);
}
