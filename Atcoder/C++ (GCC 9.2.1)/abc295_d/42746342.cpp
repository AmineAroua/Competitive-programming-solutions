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
    int n;
    cin>>n;
    vector<vi> compatible(n+1 , vi(n+1 , 0));
    fore(i , n)
    {
        fore(j, n)
        {
            cin>>compatible[i+1][j+1];
        }
    }
    vector<vl> dp((1<<n) , vl(n+1 ,0));
    fore(mask , (1<<n))
    {
        dp[mask][0] =1;
    }
    forr(mask , 1 , (1<<n))
    {
        forr(i , 1 , n)
        {
            if(__builtin_popcount(mask)!=i)continue;
            fore(j , n)
            {
                if(mask&(1<<j))
                {
                    if(compatible[i][j+1])
                        (dp[mask][i]+=dp[mask^(1<<j)][i-1])%=MOD;
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n]<<nl;
}

