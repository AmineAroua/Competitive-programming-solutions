#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int days=0;
        map<char,bool> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=true;
            if(mp.size()==4){
                mp.clear();days++;
                mp[s[i]]=true;
            }
        }
        if(!mp.empty())days++;
        cout<<days<<endl;
    }
}