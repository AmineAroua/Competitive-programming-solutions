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
vector<vii> adj;
int  m , k;

signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    int n ;
    cin>>n>>k>>m;
    vector<vi> dp((1<<k) , vi(n , INF));
    vi special(k);
    fore(i , k)
    {
        int  u ;
        cin>>u;
        u--;
        special[i] = u;
        dp[(1<<i)][u] = 0;
    }
    adj.assign(n , {});
    fore(i , m)
    {
        int u , v , c;
        cin>>u>>v>>c;
        u-- , v--;
        adj[u].pb({v , c});
        adj[v].pb({u , c});
    }
    forr(mask , 1 , (1<<k) - 1)
    {
        for(int submask = (mask) ; submask ; submask = (submask-1)&mask)
        {
            fore(v , n)
            {
                dp[mask][v] = min(dp[mask][v] , dp[submask][v] + dp[mask^submask][v]);
            }
        }
        priority_queue<pii> pq;
        fore(v , n)
        {
            if(dp[mask][v] != INF)
                pq.push({-dp[mask][v] , v});
        }
        vector<bool> vis(n , 0);
        while(!pq.empty())
        {
            int node = pq.top().se;
            int dist = -pq.top().fi;
            pq.pop();
            if(vis[node])
                continue;
            vis[node] = 1;
            for(auto [u , c] : adj[node])
            {
                if(c + dist < dp[mask][u])
                {
                    dp[mask][u] = c + dist;
                    pq.push({-1LL*(c + dist) , u});
                }
            }
        }
    }
    int ans= INF;
    fore(i , n)
    {
        ans = min(ans , dp[(1<<k) - 1][i]);
    }
    cout<<ans<<nl;
}
