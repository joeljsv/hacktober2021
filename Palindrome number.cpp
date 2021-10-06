//Palindrome Number
//If reverse of a number is equal to the number itself then it is called as a palindrome number

#include<iostream>
using namespace std;
int main()
{
    int n, rev, rem, var;
    cout<<"Please Enter the Number: ";
    cin>>n;
    var = n;
    while(var>0)
    {
        rem = var%10;
        rev = (rev*10)+rem;
        var = var/10;
    }
    if(rev==n)
    {
    	cout<<n<<" is a Palindrome Number";
	}
    else
    {
    	cout<<n<<" is not a Palindrome Number";
	}
	return 0;
}
