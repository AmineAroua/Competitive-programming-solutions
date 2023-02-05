#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    map<string,string> mp;
    for(int i=0;i<n;i++){
        string name;cin>>name;
        string ip;cin>>ip;
        mp[ip]=name;
    }
    for(int i=0;i<m;i++){
        string request;cin>>request;
        string ip;cin>>ip;
        int pos=ip.find(';');
        string Mip = ip.substr(0,pos);
        cout<<request<<" "<<ip<<" #"<<mp[Mip]<<endl;
    }
}