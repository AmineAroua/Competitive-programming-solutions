#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#define fore(i, y) for(ll i = 0; i < y; i++)
#define forr(i,x,y) for(int i = x;i<=y;i++)
#define forn(i,y,x) for(ll i = y; i >= x; i--)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define rall(v) v.rbegin() , v.rend()
#define pii pair<int,int>
#define pll pair<ll , ll>

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (PPCM)

// HERE IS THE SOLUTION
vl v;
int n , m;
const int N = 305;
int dp[N][N][N][2];
ll solve(int l  , int r ,int k ,int dir)
{

    ll ans = dp[l][r][k][dir];
    if(k == 0)
        return ans = 0ll;
    if(ans != INF)return ans;
    ans = INF +1;
    if(dir == 0)
    {
        if(r + 1 < n && k - 1 >= 0)
            ans = min(ans , solve(l,r + 1,k - 1,1) + k*(v[r+1] - v[l]));
        if(l - 1 >= 0 && k-1 >= 0)
            ans = min(ans , solve(l-1,r,k - 1,0) + k*(v[l] - v[l - 1]));

    }
    else
    {
        if(r + 1 < n && k >= 1)
            ans = min(ans , solve(l,r + 1,k - 1,1) + k*(v[r+1] - v[r]));
        if(l-1 >= 0  && k>= 1)
            ans = min(ans , solve(l-1,r,k - 1,0) + k*(v[r] - v[l-1]));
    }
    return dp[l][r][k][dir] = ans;
}
signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    v.resize(n);
    bool test = 1;
    ll ans = 0;
    fore(i , n)
    {
        cin>>v[i];
        if(v[i] == 0)test = 0;
    }
    if(test)
    {
        v.pb(0);
        n++;
    }
    else
        ans+=m;
    ll res = 0;
    sort(all(v));
    fore(i , n)
    {
        fore(j , n)
        {
            fore(k , n + 1)
            {
                fore(l , 2)
                {
                    dp[i][j][k][l] = INF;
                }
            }
        }
    }
    fore(i , n)
    {
        if(v[i] == 0)
        {
            fore(k , n + 1)
            {
                res = max(res , k * m - solve(i , i, k , 0));
            }
        }
    }
    cout<<ans+res<<nl;
}
