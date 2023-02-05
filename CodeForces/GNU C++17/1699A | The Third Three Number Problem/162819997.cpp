#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        long long a;cin>>a;
        if(a%2==0){
            cout<<a/2<<" "<<a/2<<" "<<0<<endl;
        }
        else
            cout<<-1<<endl;
    }
}