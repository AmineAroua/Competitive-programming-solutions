#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        map<int,bool> mp;
        for(int i=0;i<27;i++)mp[i]=false;
        string s;cin>>s;
        int b=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]-'A'])b++;
            else{
                b+=2;mp[s[i]-'A']=true;
        }}
        cout<<b<<endl;
    }
}