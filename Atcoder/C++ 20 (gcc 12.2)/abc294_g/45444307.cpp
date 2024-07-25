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
const int N = 200005;
vii adj[N];
int n , q;
vi euler(1 , 0);
vi diff;
vi tree;
int start[N] , End[N];
int depth[N];
int timer = 0;
vi LCATree;
vi st;
vi eulca;
int merge(int a , int b)
{
    if(a == -1) {
        return b;
    }
    if(b == -1)
        return a;
    return (st[a] < st[b] ? a : b);
}
void buildLCA(vi &a , int &m)
{
    while(__builtin_popcount(m) != 1)
    {
        m++;
        a.pb(-1);
    }
    LCATree.resize(2*m);
    fore(i , m)
    {
        LCATree[i + m] = a[i];
    }
    forn(i , m - 1 , 1)
    {
        LCATree[i] = merge(LCATree[2*i] , LCATree[2*i + 1]);
    }
}
int queryLCA(int node , int nodeL , int nodeR , int queryL , int queryR)
{
    if(nodeL >= queryL && nodeR <= queryR)
    {
        return LCATree[node];
    }
    if(nodeL > queryR || nodeR < queryL)
    {
        return -1;
    }
    int mid = (nodeL + nodeR)/2;
    return merge(queryLCA(2*node , nodeL , mid , queryL , queryR) , queryLCA(2*node + 1  , mid + 1 , nodeR , queryL , queryR));
}
void dfs1(int x , int p , int h)
{
    st[x] = timer;
    eulca[timer] = x;
    timer++;
    for(auto [u,c] : adj[x])
    {
        if(u == p)
            continue;
        dfs1(u , x , h + 1);
        eulca[timer] = x;
        timer++;
    }
}
void dfs(int x , int p , int sum , int dep)
{
    start[x] = timer;
    euler.pb(sum);
    depth[x] = dep;
    for(auto [u,c] : adj[x])
    {
        if(u == p)
            continue;
        timer++;
        dfs(u , x , sum + c , dep + 1);
    }
    End[x] = timer;
}
void build(int &m)
{
    while(__builtin_popcount(m) != 1)
    {
        m++;
        diff.pb(0);
    }
    tree.resize(2*m);
    fore(i , m)
    {
        tree[m + i] = diff[i];
    }
    forn(i , m - 1 , 1)
    {
        tree[i] = tree[2*i] + tree[2*i + 1];
    }
}
int query(int node , int nL , int nR , int l , int r)
{
    if(nL >= l && nR <= r)
    {
        return tree[node];
    }
    if(nL > r || nR < l)
    {
        return 0;
    }
    int mid = (nL + nR)/2;
    return query(2*node , nL , mid , l , r) + query(2*node + 1 , mid + 1 , nR , l , r);
}
void update(int i , int v, int m)
{
    tree[i + m] += v;
    for(int j = (i + m)/2;j>= 1 ;j/=2)
    {
        tree[j] = tree[2*j] + tree[2*j + 1];
    }
}
int lca(int u , int v , int M)
{
    return queryLCA(1 , 0 , M - 1 , min(st[u] , st[v]) , max(st[v] , st[u]));
}
signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    st.resize(n);
    eulca.resize(2*n - 1);
    vector<tuple<int ,int , int>> edg;
    fore(i , n - 1)
    {
        int a , b , c;
        cin>>a>>b>>c;
        a-- , b--;
        edg.pb({a , b , c});
        adj[a].pb({b , c});
        adj[b].pb({a , c});
    }
    timer = 1;
    dfs(0 , -1 , 0 , 0);
    timer = 0;
    dfs1(0 , -1 , 0);
    int M = 2*n - 1;
    buildLCA(eulca , M);
    euler.pb(0);
    forr(i , 1, sz(euler) - 1)
    {
        diff.pb(euler[i] - euler[i - 1]);
    }
    int m = sz(diff);
    build(m);
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t == 1)
        {
            int s , x;
            cin>>s>>x;
            s--;
            auto &[a,b,c] = edg[s];
            int u = a , v =b;
            if(depth[u] > depth[v])
                swap(u  , v);
            update(start[v] - 1 , x - c , m);
            update(End[v] , c - x , m);
            c = x;
        }
        else
        {
            int u , v;
            cin>>u>>v;
            u-- , v--;
            int LCA = lca(u , v , M);
            int a = query(1 , 0 , m - 1 , 0 , start[u] - 1);
            int b = query(1 , 0 , m - 1 , 0 , start[v] - 1);
            int c = query(1 , 0 , m - 1 , 0 , start[LCA] - 1);
            cout<<a + b - 2*c<<nl;
        }
    }
}