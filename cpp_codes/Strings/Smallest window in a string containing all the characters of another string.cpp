/*
Problem Link : https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#
Given two strings S and P.
Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.
Return "-1" in case there is no such window present.
In case there are multiple such windows of same length,
return the one with the least starting index.

Example 1:
Input:
S = "timetopractice"
P = "toc"
Output:
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.

Example 2:
Input:
S = "zoomlazapzo"
P = "oza"
Output:
apzo
Explanation: "apzo" is the smallest
substring in which "oza" can be found.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S|, |P| ≤ 105


*/


//----------------------Approach--------------------------------------
// We will use two pointer approach in this question as we have to find solution in O(n)
// As string only contain alphabet and we know that length of all alphabet is 26
// therefore we can construct two hashing array
// req_freq[26] -> this will contain frequency of alphabet in string p
// freq[26] -> this will contain frequency of alphabet in string s and it will be dynamic
// it means that we will manipulate this freq array in our algorithm
// mn_window -> this will keep track of minimum window length which satisfy the given condition
// leftInd and rightInd -> this will contain the final starting index and ending index of minimum window which satisfy the condition
// found -> initially it is initialized as false
// when we find any window which satisfy the condition then we will make found = true

//--------------------Algorithm-------------------------------------
// we will have start_ind and end_ind pointers
// start_ind -> it will point to starting index of the window
// end_ind -> it will point to ending index of the window
// we will iterate the end_ind uptil length of string s
// at every point we will compare freq and req_freq array
// if the frequency of all alphabet in freq array is greater than frequency of all alphabet in req_freq array
// this means we can form string p from window having starting index as start_ind and ending index as end_ind;
// As we have to find minimum length window we will keep incrementing the star_ind until my Compare_Freq function return true so that end_ind-start_ind+1 becomes less
// and whenever we will find the current length of window < mn_window the we will update our mn_window and leftInd and rightInd respectively


//-----------------TimeComplexity and space complexity ----------------
// since we are traversing the string once therefore its time complexity will be O(n)
// as we are only using the hash array of length 26 which is independent of string inputs
// therefore space complexity will be O(1) constant


class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    void initilize_freq(int a[],int b[]){
        for(int i=0;i<26;i++){
            a[i]=0;
            b[i]=0;
        }
    }
    bool Compare_Freq(int a[],int b[]){
        // here a =  freq  and b = req_freq
        for(int i=0;i<26;i++){
            if(a[i]<b[i]){                 // so if freq[i] < req_freq[i] then it means the current window does not contain all character of p in it
                return false;
            }
        }
        return true;
    }
    string smallestWindow (string s, string p)
    {
        int req_freq[26];
        int freq[26];

        initilize_freq(freq,req_freq);               // initializing arrays with 0 value

        for(int i=0;i<p.length();i++){
            req_freq[p[i]-'a']++;                   // storing  frequency of characters string p in req_freq array
        }                                            // so that later we can compare it with freq array
        bool found = false;
        int mn_window = s.length()+1;
        int leftInd,rightInd;
        int start_ind=0;
        int end_ind=0;

        while(end_ind<s.length()){
        freq[s[end_ind]-'a']++;
        while(Compare_Freq(freq,req_freq) == true){    // As we have to find minimum length window we will keep incrementing the star_ind until my Compare_Freq function return true
            found = true;
            if(end_ind-start_ind+1<mn_window){             //whenever we will find the current length of window < mn_window and update leftInd and rightInd
            mn_window = end_ind - start_ind +1;
            leftInd = start_ind;
            rightInd = end_ind;
            }
            freq[s[start_ind]-'a']--;              // as we are decreasing the size of window we have to exclude the character which will not be present in the current window
            start_ind++;
        }
        end_ind++;
        }

        if(found){                                // if found == true that means we have found a window satisfying condition
            string ans = "";
        	for(int i=leftInd;i<=rightInd;i++){
        		ans+=s[i];
        	}
            return ans;
        }
        else{
        	return "-1";
        }
    }
};
