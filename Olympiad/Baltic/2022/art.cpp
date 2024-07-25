#include "art.h"
#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define pb push_back
#define fore(i , n) for(int i = 0 ; i< n;i++)
#define forr(i , x , y) for(int i = x; i <= y; i++)
#define forn(i , x , y) for(int i = x; i >= y ; i--)
vector<int> conv(deque<int> &dq)
{
    vector<int> ans;
    for(auto x :dq)
        ans.pb(x);
    return ans;
}
void solve(int N) {
    deque<int> perm;
    forr(i , 1 ,N)
    {
        perm.pb(i);
    }
    vector<int> pos(N + 1);
    vector<int> final(N + 1);
    int prev = publish(conv(perm));
    forr(i , 1 , N - 1)
    {
        int l = perm.back();
        perm.pop_back();
        perm.push_front(l);
        int nw = publish(conv(perm));
        int after = (N - 1 + nw - prev)/2;
        pos[l] = after;
    }
    forr(i , 1 , N)
    {
        final[pos[i]] = i;
    }
    answer(final);
}
