#include <iostream>
using namespace std;

int main()
{	int n, menu;
	char ulang;
	Menu:
	cout << "Menu : ";
	cout << "\n1. Sorting Numbers";
	cout << "\n2. Exit\n";
	cin >> menu;
	
	if (menu==1){
		cout << "Enter the number of numbers: ";
		cin >> n;
		
		int data[n];
		int i,j,tmp;
	
		for(i=0;i<n;i++)
		{
			cout << "Enter numbers to " << (i+1) << ": ";
			cin >> data [i];
		}
		
		for(i=0;i<9;i++)
		{
			for (j=i+1;j<n;j++)
			{
				if (data[i]>data[j])
				{
					tmp = data[i];
					data[i]=data[j];
					data [j] = tmp;
				}
			}
		}
		cout << "Order of numbers from smallest to largest : "<<endl;
		for(i=0;i<n;i++)
		{
			cout << data[i]<<" ";
		}
		
		for(i=0;i<9;i++)
		{
			for (j=i+1;j<n;j++)
			{
				if (data[i]<data[j])
				{
					tmp = data[i];
					data[i]=data[j];
					data [j] = tmp;
				}
			}
		}
		cout << endl << "Order of numbers from largest to smallest : "<<endl;
		for(i=0;i<n;i++)
		{
			cout << data[i]<<" ";
		}
		
		Ulang:
		cout << "\nAgain?(y/n)";
		cin >> ulang;
		
		if (ulang=='y'){
			goto Menu;
		}
		else if (ulang=='n'){
			cout << "Have a nice day";
		}
		else {
			goto Ulang;
		}
		
	}
	else if (menu==2){
		cout << "Have a nice day";
	}
	
	return 0;
	
	
}
