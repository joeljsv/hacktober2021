/*Given a number n, print all primes smaller than or equal to n.

Input : n =10
Output : 2 3 5 7

Input : n = 20
Output: 2 3 5 7 11 13 17 19


 */
// prime number : A number is prime it is only divisible and number 1 and itself
// A number is prime, if none of the smaller prime numbers divides it
//Since we iterate over the prime numbers in order, we already marked all numbers, who are divisible by at least one of the prime numbers, as divisible.
//Hence if we reach a cell and it is not marked, then it isn't divisible by any smaller prime number and therefore has to be prim

//---------------------Approach----------------------------------------
// we will use Sieve of Eratosthenes method to find the primes numbers

// First we will construct a is_prime boolean array
// And assign it will true which mean initially all we are assuming all number are prime

// Now we will run two nested loop
// Inside first loop we will iterate from 2 to n
// and in second loop we will check if the is_prime[i] = true which means if number is prime,
// we will mark is_prime every multiple of that number as false as we know prime number is only divisible by 1 and itself

//--------------------------Conclusion----------------------------------
// Since we iterate over the prime numbers in order, we already marked all numbers, who are divisible by at least one of the prime numbers, as divisible.
//  Hence if we reach a cell and it is not marked, then it isn't divisible by any smaller prime number and therefore has to be prim

//-----------------------Time Complexity and Space Complexity--------------------------------
// Since we are traversing n time is outer loop
// and finding fact of n in second loop which takes log(n) time
// its complexity will be O(n(log(logn))
// Space complexity : Since we are creating a linear boolean vector its space complexity will be O(n)

#include<bits/stdc++.h>
using namespace std;
vector<bool> findPrime(int n){                // this function will return boolean vector
vector<bool>is_prime(n+1,true);
	is_prime[0]=false;                  // is_prime[i] = true means the number i is prime
	is_prime[1]=false;                  // is_prime[i] = false means the number is not prime
	for (int i = 2; i <=n; i++) {
	    if (is_prime[i]==true && i * i <= n) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;    // Marking multiples of i as false
	    }
	}
	return is_prime;
}
int main(){
	int n;              // taking input of n
	cin>>n;
	vector<bool> prime = findPrime(n) ;
	cout<<"Prime numbers from 1 to n are :";
	for(int i=1;i<=n;i++){
		if(prime[i]==true){
			cout<<i<<" ";
		}
	}
}
