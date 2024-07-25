#include <bits/stdc++.h>

using namespace std;
#pragma once
#define lint long long
#define fore(i , n) for(int i = 0 ; i<n;i++)
#define forr(i , x , y) for(int i = x; i<=y;i++)
#define forn(i , x , y) for(int i = x ; i>=y;i--)
#define vi vector<lint>
#define vii vector<pair<lint ,lint>>
#define pb push_back

#define sz(s) (lint)s.size()
#define all(v) v.begin() , v.end()
#define nl '\n'
const int N = 5e5 + 1;
std::vector<int> find_subset(int l, int u, std::vector<int> w)
{
    int n = (int)w.size();
    vii v(n);
    fore(i , n)
        v[i] = {w[i] , i};
    sort(all(v));
    deque<int> dq;
    lint sum = 0;
    if(v[0].first > u)
    {
        return {};
    }
    fore(i , n)
    {
        if(sum <= u && sum>= l)
        {
            vector<int> ret;
            for(auto x : dq)
                ret.pb(x);
            return ret;
        }
        while(!dq.empty() && sum + v[i].first > u)
        {
            int fi = dq.front();
            sum-= w[fi];
            dq.pop_front();
        }
        sum+=v[i].first;
        dq.push_back(v[i].second);
    }
    if(sum <= u && sum >= l)
    {
        vector<int> ret;
        for(auto i : dq)
            ret.pb(i);
        return ret;
    }
    return {};
}
