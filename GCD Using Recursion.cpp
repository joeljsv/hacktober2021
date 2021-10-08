//GCD of two numbers
#include <iostream>
using namespace std;

int GCD(int n1, int n2);

int main()
{
   int num1, num2;
   cout << "\nEnter two positive integers: ";
   cin >> num1 >> num2;

   cout << "\nGCD of " << num1 << " & " <<  num2 << " is : " << GCD(num1, num2);
   return 0;
}
int GCD(int num1, int num2)
{
    if (num2 != 0)
       return GCD(num2, num1 % num2);
    else 
       return num1;
}
