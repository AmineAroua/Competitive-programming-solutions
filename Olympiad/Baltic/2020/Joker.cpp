#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
vector<pair<int ,int>> edges;
struct DSU
{
    vector<pair<int ,int>> e;
    vector<int> col;
    bool bip;
    vector<int> rank;
    vector<vector<int>> hist;
    void init(int n)
    {
        bip = 1;
        e.assign(n , {0 , 0});
        rank.assign(n , 0);
        for(int i = 0 ; i < n ; i++)
            e[i].first = i;
    }
    pair<int ,int> get(int x)
    {
        if(e[x].first != x)
        {
            int len = e[x].second;
            pair<int ,int> p = get(e[x].first);
            (p.second+=len)%=2;
            return p;
        }
        return e[x];
    }
    bool is_bip()
    {
        return bip;
    }
    void unite(int u , int v)
    {
        if(u == v)
            return ;
        pair<int ,int> uu = get(u) , vv = get(v);
        if(uu.first == vv.first)
        {
            hist.push_back({-1 , bip});
            if(uu.second == vv.second)
            {
                bip = 0;
            }
            return ;
        }
        if(rank[uu.first] < rank[vv.first])
        {
            swap(uu , vv);
        }
        hist.push_back({vv.first , e[vv.first].first , e[vv.first].second , uu.first , rank[uu.first] == rank[vv.first]});
        e[vv.first].first = uu.first;
        e[vv.first].second = (uu.second + vv.second + 1)%2;
        rank[uu.first]+=(rank[uu.first] == rank[vv.first]);
    }
    void roll_back()
    {
        auto last = hist.back();
        hist.pop_back();
        if(last[0] == -1)
        {
            bip = last.back();
        }
        else
        {
            e[last[0]] = {last[1] , last[2]};
            rank[last[3]] -= last[4];
        }
    }
    void roll_back(int x)
    {
        while (x--)
        {
            roll_back();
        }
        
    }
    void clear()
    {
        roll_back((int)hist.size());
    }
}dsu;
int n , m , q;
vector<int> nxt;
void solve(int l , int r , int optl , int optr)
{
    if(l > r)
        return ;
    int mid = (l + r)/2;
    int ops = 0;
    for(int i = l ; i < mid ; i++)
    {
        ops++;
        dsu.unite(edges[i].first , edges[i].second);
    }
    int opt = optr;
    for(int i = optr ; i >= max(mid , optl) ; i--)
    {
        if(!dsu.is_bip())
        {
            break;
        }
        opt = i;
        if(i < m)
        {
            ops++;
            dsu.unite(edges[i].first , edges[i].second);
        }
    }
    nxt[mid] = opt;
    dsu.roll_back(ops);
    ops = 0;
    for(int i = opt + 1 ; i <= optr ;i++)
    {
        if(i < m)
        {
            dsu.unite(edges[i].first , edges[i].second);
            ops++;
        }
    }
    solve(l , mid - 1 , optl , opt);
    dsu.roll_back(ops);
    ops = 0;
    for(int i = l ; i <= mid ; i++)
    {
        ops++;
        dsu.unite(edges[i].first , edges[i].second);
    }
    solve(mid + 1 , r , opt , optr);
    dsu.roll_back(ops);
    ops = 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    nxt.assign(m , m);
    dsu.init(n);
    for(int i = 0 ; i < m ; i++)
    {
        int u , v;
        cin>>u>>v;
        u-- , v--;
        edges.push_back({u , v});
    }
    solve(0 , m - 1 , 0 , m);
    for(int i = 0 ; i< q; i++)
    {
        int l , r;
        cin>>l>>r;
        l-- , r--;
        if(nxt[l] <= r)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }
}
