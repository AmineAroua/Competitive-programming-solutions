#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;while(t--){
        string s;cin>>s;
        int n=6;
        int sum1=0,sum2=0;
        for(int i=0;i<3;i++)
        {
            sum1+=s[i]-'0';
        }
        for(int i=n-1;i>=3;i--){
            sum2+=s[i]-'0';
        }
        if(sum1==sum2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}