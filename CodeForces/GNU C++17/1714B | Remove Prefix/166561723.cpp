#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> v(n);
        vector<bool> v1(n+1,false);
        for(int i=0;i<n;i++)
        cin>>v[i];
        int ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(v1[v[i]]==true)
            {
                ans = i+1;
                break;
            }
            v1[v[i]]=true;
        }
    cout<<ans<<endl;}
    
}