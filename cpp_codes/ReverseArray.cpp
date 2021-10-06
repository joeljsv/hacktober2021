#include <iostream>
using namespace std;

int main() {
	//to reverse an array
	int n;
    cout<<"Enter the size of an array: "<<endl;
	cin>>n;
	//declaring array
	int ar[n];
    cout<<"Enter an array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	int i=0;
	int j=n-1;
	while(i<=j){
		int temp;
		temp=ar[i];
		ar[i]=ar[j];
		ar[j]=temp;
		i++;
		j--;
	}
    cout<<"Reverse array is: "<<endl;
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	return 0;
}
