#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define pb push_back
#define ll long long
#define ld long double
#define nl '\n'
#define boost ios::sync_with_stdio(false)
#define mp make_pair
#define se second
#define fi first
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i,x,y) for(int i = x;i<=y;i++)
#define forn(i,y,x) for(int i = y; i >= x; i--)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define rall(v) v.rbegin() , v.rend()
#define pii pair<int,int>
#define pll pair<ll , ll>
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (gcd)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (lcm)
 
// HERE IS THE SOLUTION
const int N = 1e5 + 10;
const int LOG = 20;
int n , s , q, e;
vii adj[N];
int mn[LOG][N] , par[LOG][N];
pii edges[N];
int depth[N];
int cost_closest[N];
int distE[N];
int Time = -1;
int tin[N] , tout[N];
void pre_dfs(int x , int p)
{
    Time++;
    tin[x] = Time;
    for(auto [u , c] : adj[x])
    {
        if(u == p)
            continue;
        depth[u] = depth[x] + 1;
        distE[u] = distE[x] + c;
        pre_dfs(u , x);
        cost_closest[x] = min(cost_closest[u] + c , cost_closest[x]);
    }
    tout[x] = Time;
}
 
void main_dfs(int x , int p)
{
    for(auto [u , c] : adj[x])
    {
        if(u == p)
            continue;
        mn[0][u] = cost_closest[x] - distE[x];
        par[0][u] = x;
        forr(j , 1 , LOG - 1)
        {
            par[j][u] = par[j - 1][par[j - 1][u]];
            mn[j][u] = min(mn[j - 1][u] , mn[j - 1][par[j - 1][u]]);
        }
        main_dfs(u , x);
    }
}
 
bool is_ancestor(int anc , int node)
{
    return (tin[node] <= tout[anc] && tin[node] >= tin[anc]);
}
 
signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s>>q>>e;
    e--;
    forr(i ,1, n - 1)
    {
        int u , v , c;
        cin>>u>>v>>c;
        u-- , v--;
        adj[u].pb({v , c});
        adj[v].pb({u , c});
        edges[i] = { u , v};
    }
    fore(i , n)
        cost_closest[i] = INF;
    fore(i , s)
    {
        int x;
        cin>>x;
        x--;
        cost_closest[x] = 0;
    }
    distE[e] = 0;
    depth[e] = 0;
    pre_dfs(e , -1);
    fore(i , LOG)
    {
        fore(j , n)
        {
            mn[i][j] = INF;
            par[i][j] = e;
        }
    }
    main_dfs(e , -1);
    while(q--)
    {
        int i , u;
        cin>>i>>u;
        u--;
        int p = edges[i].first;
        if(depth[edges[i].second] > depth[p])
            p = edges[i].second;
        if(is_ancestor(p , u))
        {
            if(cost_closest[p] >= INF)
            {
                cout<<"oo"<<nl;
                continue;
            }
            int ans = cost_closest[u] - distE[u];
            int node = u;
            forn(j , LOG - 1 , 0)
            {
                int new_node = par[j][node];
                if(is_ancestor(p , new_node))
                {
                    ans = min(ans , mn[j][node]);
                    node = new_node;
                }
            }
            ans+=distE[u];
            cout<<ans<<nl;
        }
        else
        {
            cout<<"escaped"<<nl;
        }
    }
}
