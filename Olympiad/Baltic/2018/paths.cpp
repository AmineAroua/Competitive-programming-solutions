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

signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    int n , m, k;
    cin>>n>>m>>k;
    vi c(n);
    fore(i , n)
    {
        cin>>c[i];
        c[i]--;
    }
    vector<vi> adj(n);
    fore(i , m)
    {
        int u , v;
        cin>>u>>v;
        u-- , v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vi> dp((1<<k) , vi(n , 0));
    fore(i , n)
    {
        dp[(1<<c[i])][i] = 1;
    }
    forr(mask ,1, (1<<k) - 1)
    {
        fore(i , n)
        {
            for(auto j : adj[i])
            {
                if((1<<c[j]) & mask)
                {
                    continue;
                }
                dp[mask | (1<<c[j])][j]+=dp[mask][i];
            }
        }
    }
    int res = 0;
    forr(mask ,1, (1<<k) - 1)
    {
        int ans = 0;
        fore(i , n)
            ans+=dp[mask][i];
        if(__builtin_popcount(mask) != 1)
            res+=ans;
    }
    cout<<res<<nl;
}
