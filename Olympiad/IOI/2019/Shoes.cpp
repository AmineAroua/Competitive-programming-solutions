#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#include <cstdio>
#include <cassert>
#define Int long long
#define fore(i , n) for(int i = 0 ; i<n;i++)
#define pb push_back
#define forn(i , x , y) for(int i = x ; i >= y; i--)
Int swaps(vector<int> a , vector<int> b)
{
    map<Int , vector<Int>> pos;
    Int m = (Int)a.size();
    fore(i , m)
    {
        pos[a[i]].pb(i);
    }
    Tree<Int> t;
    Int ans = 0;
    forn(i , m - 1 , 0)
    {
        t.insert(pos[b[i]].back());
        ans+=(Int)t.order_of_key(pos[b[i]].back());
        pos[b[i]].pop_back();
    }
 
 
    return ans;
}
Int count_swaps(vector<int> s)
{
    int n = (int)s.size();
    vector<int> t;
    map<int , int> occ;
    for(auto x : s)
    {
        occ[x]++;
        if(occ[-x] >= occ[x])
        {
            occ[-x]--;
            occ[x]--;
        }
        else
        {
            t.pb(-abs(x));
            t.pb(abs(x));
        }
    }
    return swaps(s , t);
}
