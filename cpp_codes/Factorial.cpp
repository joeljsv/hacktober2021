//Find Factorial using Recursion
#include<iostream>
using namespace std;
 
int Factorial(int n)
{
    if (n <= 1)
        return 1;
    return n*Factorial(n-1);
}
 
int main ()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int output = Factorial(n);
    printf("The output value for input %d is %d",n,output);
    return 0;
}
