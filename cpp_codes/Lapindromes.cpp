
/* * @file
 @brief Implementation of [Lapindrome]

Lapindrome is defined as a string which when split in the middle, 
gives two halves having the same characters and same frequency of each character.
If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. 
For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency. 
Also, abccab, rotor and xyzxy are a few examples of lapindromes.
Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match.
Your task is simple. Given a string, you need to tell if it is a lapindrome.

@author [PARVEEN](https://github.com/Parveen-jangra)*/

#include<bits/stdc++.h>
using namespace std;
int main()//main
{
   int t,m;//int variable t is used for test case
   cin>>t;
   while (t--)
 {
     string s;
     cin>>s;
     int l=strlen(s.c_str());
     if (l%2==0)//check if rem. zero
         m=l/2;
     else
        m=(l+1)/2;
     
   for (int i = 0; i < m; i++)
   {
       for ( int j = m; j < l; j++)
       {
           if (s[i]==s[j])//compare
           {
               s[j]=0;
               break;
           }
           
       }
       
   }
   
     int count=0;
     for (int i = m; i < l; i++)
         if(s[i]!=0)
         {
         count++;
         }
         if (count==0)
        {
             cout<<"YES"<<endl;
         }
         else
         {
         cout<<"NO"<<endl;
         }
     }
     
     return 0;
   
}
