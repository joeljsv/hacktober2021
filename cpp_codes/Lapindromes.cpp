#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t,m;
   cin>>t;
   while (t--)
 {
     string s;
     cin>>s;
     int l=strlen(s.c_str());
     if (l%2==0)
         m=l/2;
     else
        m=(l+1)/2;
     
   for (int i = 0; i < m; i++)
   {
       for ( int j = m; j < l; j++)
       {
           if (s[i]==s[j])
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