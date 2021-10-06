#include <iostream>
using namespace std;
//conditions to check for leap year:
//year should be divisible by 4
//it should be divisible by 400 and 100
//it should not be divisible by 100 but divisible by 4 
int main() {
	//to check for leap year
	int year;
	cout<<"Enter year to check if it is leap year or not: "<<endl;
	cin>>year;
	if(year%4==0){
		if(year%400==0 && year%100==0){
			cout<<"It is a Leap year"<<endl;
		}
		else if((year%100)!=0){
			cout<<"It is a leap year"<<endl;

		}
		else{
			cout<<"Not a Leap year"<<endl;
		}

	}
	else{
		cout<<"Not a Leap year"<<endl;
	}
	return 0;
}
