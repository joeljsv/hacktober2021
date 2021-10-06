
// This program find the total number of times the sorted array is rotated clockwise.
#include<bits/stdc++.h>
using namespace std;

// Since the number of raotation(clockwise)== index of minimum element, here we will find the
// index of smallest element in the array using binary search.

int findRotationCount(vector<int>& arr)
{
    int n=arr.size();
    int start=0, end=n-1;

    // If array is not raotated at all
     if(arr[start] < arr[end]) 
        return 0;
        
    while(start<= end)
    {
        int mid= start+ (end-start)/2;
        int next= (mid+1)%n;
        int prev=(mid+n-1)%n;

        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev])
            return mid;
        else
        {
            if(arr[start] <= arr[mid] && arr[mid] <= arr[end]) 
                return start;
            else if(arr[start] <= arr[mid])
	           {
	                start = mid+1;
               }
    	    else if(arr[mid] <= arr[end])
            {
    	        end = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{15, 18, 2, 3, 6, 12} ;
    //Here the rotation count will be 2.
    cout<<"The rotation count(clockwise) of array is "<<findRotationCount(arr)<<"."<<endl;
    return 0;
}
