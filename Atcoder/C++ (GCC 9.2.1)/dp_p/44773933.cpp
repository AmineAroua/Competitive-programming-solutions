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
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define rall(v) v.rbegin() , v.rend()
#define pii pair<int,int>
#define pll pair<ll , ll>

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (gcd)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (lcm)

// HERE IS THE SOLUTION
const int N = 100000;
vi adj[N];
int dp[N][2];
int add(int a , int b)
{
    return ((a%MOD) + (b%MOD))%MOD;
}
int mul(int a, int b)
{
    return ((a%MOD)*(b%MOD))%MOD;
}
void init()
{
    fore(i , N)
        fore(j , 2)
            dp[i][j] = -1ll;
}
int dfs(int x , int p , int col)
{
    int &ans = dp[x][col];
    if(ans != -1ll)
        return ans;
    if(col == 0)  // black
    {
        ans = 1;
        for(auto u : adj[x])
        {
            if(u == p)
                continue;
            ans = mul(ans , dfs(u , x , 1  -col));
        }
    }
    else
    {
        ans = 1;
        for(auto u : adj[x])
        {
            if( u== p)
            {
                continue;
            }
            ans = mul(ans , add(dfs(u , x , col) , dfs(u , x , 1 - col)));
        }
    }
    return ans;
}
signed main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int n;
    cin>>n;
    init();

    fore(i , n  - 1)
    {
        int a , b;
        cin>>a>>b;
        a-- , b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = add(dfs(0 , -1 , 0)  , dfs(0 , -1 , 1));
    cout<<ans<<nl;
}

