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
const int LOG = 19;
vector<vi> adj;
vector<vi> dp;
vi sub;
vi SZ;
int n ;
vi idx;
vi node;
vi mark;
bool cmp(const int u , const int v)
{
    return sub[u] < sub[v];
}
void dfs(int x)
{
    for(auto u : adj[x])
    {
        dp[0][u] = x;
        for(int lg = 1 ; lg <= LOG ; lg++)
        {
            dp[lg][u] = dp[lg - 1][dp[lg - 1][u]];
        }
        dfs(u);
        SZ[x]+=SZ[u];
        sub[x]=min(sub[u] , sub[x]);
    }
}
int timer;
void dfsTime(int x)
{
    idx[x] = timer;
    node[timer] = x;
    sort(rall(adj[x]) , cmp);
    for(auto u : adj[x])
    {
        timer--;
        dfsTime(u);
    }
}
signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    mark.assign(n + 1 , 0);
    node.assign(n + 1, 0);
    idx.assign(n  +1 , n + 1);
    sub.assign(n + 1 , 0);
    SZ.assign(n + 1 , 1);
    adj.assign(n  + 1 , {});
    dp.assign(LOG + 1 , vi(n + 1 , 0));
    fore(i , n)
    {
        int x;
        cin>>x;
        adj[x].pb(i + 1);

    }
    fore(i , n  + 1)
        sub[i] = i;
    dfs(0);
    timer = n;
    dfsTime(0);
    priority_queue<int> pq;
    fore(i , n)
    {
        pq.push(-i);
    }
    while(q--)
    {
        int t;
        cin>>t;
        if(t == 1)
        {
            int k;
            cin>>k;
            int last = 0;
            while(k--)
            {
                int u = node[-pq.top()];
                last = u;
                mark[u] = 1;
                pq.pop();
            }
            cout<<last<<nl;
        }
        else
        {
            int u;
            cin>>u;
            int nb = 0;
            for(int lg = LOG; lg >=  0; lg--)
            {
                int up = dp[lg][u];
                if(mark[up])
                {
                    u = up;
                    nb+=(1<<lg);
                }
            }
            mark[u] = 0;
            if(u)
                pq.push(-idx[u]);
            cout<<nb<<nl;
        }
    }
}
