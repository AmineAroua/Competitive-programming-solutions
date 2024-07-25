#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int r;
    cin>>r;
    if(r < 100)
    {
        cout<<100 - r<<'\n';
    }
    else if(r < 200)
    {
        cout<<200 - r<<'\n';
    }
    else
        cout<<300 - r<<'\n';
}
