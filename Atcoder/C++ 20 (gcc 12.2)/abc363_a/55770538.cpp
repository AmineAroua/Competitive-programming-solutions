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

const ll MOD = 998244353;
const ll INF = 1e18 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (gcd)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (lcm)

// HERE IS THE SOLUTION
const int SQ = 450;
const int N = 200005;
vector<int> dp(N , 1);
vector<vi> DP(SQ , vi(N , 0));
int n , a[N];
signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    fore(i , n)
    {
        cin>>a[i + 1];
    }
    forn(i , n , 1)
    {
        forr(j , 1, SQ - 1)
        {
            if(i + j > n)
                break;
            (DP[j][i] = DP[j][i + j] + dp[i + j])%=MOD;
        }
        if(a[i] < SQ)
        {
            (dp[i] += DP[a[i]][i])%=MOD;
        }
        else
        {
            for(int j = i + a[i]; j <= n;j+=a[i])
            {
                (dp[i]+=dp[j])%=MOD;
            }
        }
    }
    cout<<dp[1]<<nl;
}

