#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
#define pb push_back
#define fore(i , n) for(int i = 0 ; i<n;i++)
#define forr(i , x , y) for(int i = x ; i <= y; i++)
#define forn(i , x , y) for(int i = x ; i >= y; i--)
const int N = 2e5 + 10;
vector<int> adj[N];
int a[N];
int n , m;
vector<int> ans(N , 0);
vector<bool> vis(N , 0);
int sz[N];
vector<int> nadj[N];
struct DSU
{
    vector<int> e;
    vector<int> sm;
    DSU(int _n)
    {
        e.assign(_n , -1);
        sm.assign(_n , 0);
        fore(i , _n)
            sm[i] = a[i];
    }
    int get(int x)
    {
        return (e[x] < 0 ? x : e[x] = get(e[x]));
    }
    int sum(int x)
    {
        return sm[get(x)];
    }
    void unite(int u , int v)
    {
        u = get(u) , v = get(v);
        if(u == v)
            return ;
        sm[u]+=sm[v];
        e[u]+=e[v];
        e[v] = u;
    }
};
void dfsCompute(int x)
{
    for(auto u : nadj[x])
    {
        if(vis[u])
            continue;
        if(sz[u] >= a[x])
        {
            ans[u] = 1;
            dfsCompute(u);
        }
    }
}
signed main()
{
    cin>>n>>m;
    vector<pair<int ,int>> order;
    fore(i , n)
    {
        cin>>a[i];
        order.pb({a[i] , i});
    }
    fore(i , m)
    {
        int u , v;
        cin>>u>>v;
        u-- , v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sort(order.begin() , order.end());
    DSU dsu(n);
    vector<bool> mark(n , 0);
    fore(j , n)
    {
        int i = order[j].second;
        mark[i] = 1;
        for(auto u : adj[i])
        {
            u = dsu.get(u);
            if(!mark[u] || u == i)
                continue;
            if(sz[u] >= a[i]) {
                nadj[i].pb(u);
            }
            dsu.unite(i , u);
        }
        sz[i] = dsu.sum(i);
    }
    ans[order.back().second] = 1;
    dfsCompute(order.back().second);
    fore(i , n)
        cout<<ans[i];
}
