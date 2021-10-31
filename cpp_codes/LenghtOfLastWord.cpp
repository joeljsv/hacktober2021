Problem Description : 

    Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

    If the last word does not exist, return 0.

    Note: A word is defined as a character sequence consists of non-space characters only.
    
    
Solution :


int Solution::lengthOfLastWord(const string A) {
    int n = A.length();
    int ans = 0, i = n-1;

    while(i >= 0){
        if(A[i] == ' ') i--;
        else break;
    }

    for(; i >= 0; i--){
        if(A[i] == ' ') break;
        ans++;
    }
    
    return ans;
}
