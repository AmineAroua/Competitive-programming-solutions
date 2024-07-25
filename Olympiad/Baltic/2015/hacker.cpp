#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n ;
    cin>>n;
    vector<int> v(n);
    vector<int> pref(4 * n);
    for(int i = 0 ;i < n ; i++)
    {
        cin>>v[i];
        pref[i] = v[i];
        if(i)
            pref[i]+=pref[i - 1];
    }
    for(int i = n ; i < 4 * n; i++)
    {
        pref[i] = pref[i - 1] + v[i%n];
    }
    int best = 0;
    vector<int> sm(4 * n);
    for(int i = 0 ; i < n ; i++)
    {
        if(i + (n + 1)/2 - 1 < 4 * n)
        {
            sm[i] = pref[i + (n + 1)/2 - 1] - (i ? pref[i - 1] : 0);
        }
    }
    for(int i = n ; i < 4 * n ; i++)
    {
        sm[i] = sm[i%n];
    }
    multiset<int> ms;
    vector<int> mn(4*n);
    for(int i = 0 ; i < (n + 1)/2 ; i++)
    {
        ms.insert(sm[i]);
    }
    mn[0] = *ms.begin();
    for(int i = 1 ; i + (n + 1)/2 - 1 < 4* n ; i++)
    {
        ms.insert(sm[i + (n + 1)/2 - 1]);
        ms.erase(ms.find(sm[i - 1]));
        mn[i] = *ms.begin();
    }
    for(int shift = 0 ; shift  < n ; shift++)
    {
        int ans = mn[1 + (n / 2) + shift];
        best = max(best , ans);
    }
    cout<<best<<'\n';
}
