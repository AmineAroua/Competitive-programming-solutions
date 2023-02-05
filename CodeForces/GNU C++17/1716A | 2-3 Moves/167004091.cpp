#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define nl '\n'
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll ans =0,res=0;
        if(n-(n/3)*3==0)
            res = n/3;
        else
        {
            res = n/3+1;
        }
        ans = n/2;
        if(n!=1)
        cout<<min(ans,res)<<nl;
        else cout<<2<<nl;
    }
}