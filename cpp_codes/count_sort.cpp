// Count sort or counting sort code cpp


// Hacktober fest 2021 first PR 
// author : @prateek11rai

#include<bits/stdc++.h>
using namespace std;

void countsort(vector<int>& arr){
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    int len=arr.size();
 
    vector<int> count(range), output(len);
    for (int i = 0; i < len; i++){
        count[arr[i] - min]++;
    }
 
    for (int i = 1; i < count.size(); i++){
        count[i] += count[i - 1];
    }
 
    for (int i = len - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    for (int i = 0; i < len; i++){
        arr[i] = output[i];
    }
}

int main(){
    vector<int> arr = { -5, -1, 10, -36, 84, 5, -10, 20, 21, -32, -2 };

    cout<<"Befor sorting : "<<endl;

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"After sorting : "<<endl;

    countsort(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    return 0;
}