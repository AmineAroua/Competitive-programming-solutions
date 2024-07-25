#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
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
#define ub upper_bound
#define lb lower_bound

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)

// HERE IS THE SOLUTION

int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    ll n , w;
    cin>>n>>w;
    ll sum = 0;
    vl weight(n+1) , val(n+1);
    fore(i , n)
    {
        cin>>weight[i+1]>>val[i+1];
        sum+=val[i+1];
    }
    vector<vl> dp(sum+1 , vl(n+1 , INT32_MAX));
    forr(i , 0 , n)dp[0][i] = 0;
    forr(i , 1 , n)
    {
        forr(x , 1 , sum)
        {
            dp[x][i] = dp[x][i-1];
            if(x - val[i]>=0)
            {
                dp[x][i] = min(dp[x][i] , dp[x - val[i]][i-1]+weight[i]);
            }
        }
    }
    ll ans = -1;
    forn(x, sum , 0)
    {
        if(dp[x][n]<=w)
        {
            ans = x*1LL;
            break;
        }
    }
    cout<<ans<<nl;
}

