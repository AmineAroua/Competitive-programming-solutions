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
        int n;cin>>n;
        vi per(n);
        cout<<n<<nl;
        for(int i=0;i<n;i++)
        {
            per[i]=i+1;
            cout<<i+1<<" ";
        }
        cout<<nl;
        int l=0;
        for(int i=1;i<n;i++)
        {
            swap(per[l],per[l+1]);
            l++;
            for(int i=0;i<n;i++)
            {
                cout<<per[i]<<" ";
            }
            cout<<nl;
        }
    }
}