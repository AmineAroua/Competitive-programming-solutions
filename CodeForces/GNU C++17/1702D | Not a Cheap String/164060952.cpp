#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int p;cin>>p;
        int cost=0;
        vector<pair<int,int>> vmax;
        for(int i=0;i<s.size();i++){
            vmax.push_back(make_pair(s[i]-'a'+1,i));
            cost+=s[i]-'a'+1;
        }
        sort(vmax.begin(),vmax.end());
        int n=s.size()-1;
        while(cost>p){
            s[vmax[n].second]='\0';
            cost-=vmax[n].first;
            n--;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='\0')cout<<s[i];
        }
        cout<<endl;
    }
}