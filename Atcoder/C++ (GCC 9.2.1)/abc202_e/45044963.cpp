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
vi adj[N];
int n , q;
int timer = 0;
int start[N] , End[N];
vi nodes[N];
int depth[N];
void dfs(int x, int p , int h)
{
    start[x] = timer;
    depth[x] = h;
    nodes[h].pb(timer);
    timer++;
    for(auto u : adj[x])
    {
        if(u == p)
            continue;
        dfs(u , x, h + 1);
    }
    End[x] = timer;
}
signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    fore(i , n - 1)
    {
        int x;
        cin>>x;
        x--;
        adj[i + 1].pb(x);
        adj[x].pb(i + 1);
    }
    dfs(0 , -1 , 0);
    cin>>q;
    while(q--)
    {
        int u , d;
        cin>>u>>d;
        u--;
        if(d < depth[u])
        {
            cout<<0<<nl;
            continue;
        }
        int st = start[u] , ed = End[u];
        vi &v = nodes[d];
        int a = lower_bound(all(v) , ed) - v.begin();
        int b = lower_bound(all(v) , st) - v.begin();
        cout<<max(a - b , 0ll) <<nl;
    }
}

