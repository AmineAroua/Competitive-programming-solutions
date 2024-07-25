#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
#define pb push_back
#define nl '\n'
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i, x, y) for(int i = x;i<=y;i++)
#define forn(i, y, x) for(int i = y; i >= x; i--)
const int N = 1e5 + 10;
const int LOG = 19;
vector<int> adj[N];
int par[LOG][N];
int pref[N];
int tin[N];
int dep[N];
int Time = -1;
bool cmp(const int &a , const int &b)
{
    return tin[a] < tin[b];
}
void dfs(int x , int p)
{
    Time++;
    tin[x] = Time;
    for(auto u : adj[x])
    {
        if(u == p)
            continue;
        par[0][u] = x;
        forr(j , 1 ,LOG - 1)
        {
            par[j][u] = par[j - 1][par[j - 1][u]];
        }
        dep[u] = dep[x] + 1;
        dfs(u , x);
    }
}
int lift(int x , int k)
{
    fore(i , LOG)
    {
        if((1<<i) & k)
            x = par[i][x];
    }
    return x;
}
int lca(int a , int b)
{
    if(dep[a] < dep[b])
        swap(a , b);
    int x = dep[a] - dep[b];
    a = lift(a , x);
    if(a == b)
        return a;
    forn(i , LOG -1 , 0)
    {
        int na = par[i][a] , nb = par[i][b];
        if(na == nb)
            continue;
        a = na , b = nb;
    }
    return par[0][a];
}
void re_dfs(int x , int p)
{
    for(auto u : adj[x])
    {
        if(u == p)
            continue;
        re_dfs(u , x);
        pref[x]+=pref[u];
    }
}
map<pair<int ,int> , int> edges;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m , k;
    cin>>n>>m>>k;
    fore(i , n - 1)
    {
        int u , v;
        cin>>u>>v;
        u-- , v--;
        edges[{u , v}] = edges[{v , u}] = i;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0 , -1);
    fore(i , m)
    {
        int s;
        cin>>s;
        vector<int> nodes(s);
        for(auto &x : nodes)
        {
            cin>>x;
            x--;
        }
        sort(nodes.begin() , nodes.end() , cmp);
        nodes.pb(nodes[0]);
        fore(j  ,s)
        {
            int a = nodes[j] , b = nodes[j + 1];
            int mid = lca(a , b);
            pref[mid]-=2;
            pref[a]++;
            pref[b]++;
        }
    }
    re_dfs(0, -1);
    vector<int> ans;
    forr(i ,1, n - 1)
    {
        if(pref[i] >= 2 * k)
        {
            ans.pb(edges[{i , par[0][i]}] + 1);
        }
    }
    sort(ans.begin() , ans.end());
    cout<<(int)ans.size()<<nl;
    for(auto x : ans)
        cout<<x<<" ";

}

