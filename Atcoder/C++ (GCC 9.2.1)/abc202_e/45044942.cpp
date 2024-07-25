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
int n , m;
const int N = 100005;
vi adj[N];
int dpDown[N] , dpUp[N];
int add(int a , int b)
{
    return ((a%m) + (b%m))%m;
}
int mul(int a , int b)
{
    return ((a%m)*(b%m))%m;
}
void init()
{
    fore(i , n)
    {
        dpDown[i] = 2;
        dpUp[i] = 1;
        adj[i].clear();
    }
}
void dfs(int x , int p)
{
    if(x == 0)
        dpUp[x] = 1;
    dpDown[x] = 1;
    for(auto u : adj[x])
    {
        if(u == p)
            continue;
        dfs(u, x);
        dpDown[x] = mul(dpDown[x] , dpDown[u]);
    }
    dpDown[x] = add(dpDown[x] , 1);
}
void dfs2(int  x,  int p)
{
    int curPref = 1;
    for(int i = 0;i<sz(adj[x]);i++)
    {
        int u = adj[x][i];
        if(u == p)
            continue;
        dpUp[u] = mul(dpUp[u] , dpUp[x]);
        dpUp[u] = mul(dpUp[u] , curPref);
        curPref = mul(curPref, dpDown[u]);
    }
    int curSuf = 1;
    for(int i = sz(adj[x]) - 1 ;i>= 0;i--)
    {
        int u = adj[x][i];
        if(u == p)
            continue;
        dpUp[u] = mul(dpUp[u] , curSuf);
        dpUp[u] = add(1 , dpUp[u]);
        curSuf = mul(curSuf , dpDown[u]);
    }
    for(int i = 0;i<sz(adj[x]);i++)
    {
        int u = adj[x][i];
        if(u == p)
            continue;
        dfs2(u , x);
    }
}
signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    init();
    fore(i , n - 1)
    {
        int u , v;
        cin>>u>>v;
        u-- , v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0 , -1);
    dfs2(0 , -1);
    fore(i , n)
    {
        cout<<mul((dpDown[i] - 1 + m)%m , dpUp[i])<<nl;
    }
}

