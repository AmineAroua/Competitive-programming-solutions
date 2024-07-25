#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n , t , p;
    cin>>n>>t>>p;
    vector<int> l(n);
    for(int i = 0 ;i < n ; i++)
        cin>>l[i];
    sort(l.begin() , l.end());
    reverse(l.begin() , l.end());
    int nb = 0;
    for(auto x : l)
        if(x >= t)
            nb++;
    if(nb >= p)
    {
        cout<<0<<'\n';
        return 0;
    }
    nb = p - nb;
    int d = l.back();
    for(auto x : l)
    {
        if(x < t && nb > 0)
        {
            nb--;
            d = max(d , t - x);
        }
    }
    cout<<d<<'\n';
}
