#include<bits/stdc++.h>

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int,int>> s,s1;
        vector<int> r,l;
        for(int i=h.size()-1;i>=0;i--){
            while(1){
                if(!s.size()){
                    r.push_back(h.size());
                    break;
                }
                if(s.top().first<h[i]){
                    r.push_back(s.top().second);
                    break;
                }
                s.pop();
            }
            s.push({h[i],i});
        }
        reverse(r.begin(),r.end());
        for(int i=0;i<h.size();i++){
            while(1){
                if(!s1.size()){
                    l.push_back(-1);
                    break;
                }
                if(s1.top().first<h[i]){
                    l.push_back(s1.top().second);
                    break;
                }
                s1.pop();
            }
            s1.push({h[i],i});
        }
        int area=0;
        for(int i=0;i<h.size();i++){
            int temp=(r[i]-l[i]-1)*h[i];
            area=max(area,temp);
        }        
        return area;
    }
};

int main(){
    Solution s;
    vector<int> v{2,1,5,6,2,3};
    s.largestRectangleArea(v);
    return 0;
}