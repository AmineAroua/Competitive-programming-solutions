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
    int n ,  m , k;
    cin>>n>>m>>k;
    vi a(n) , b(m);
    int sb = 0 , sa = 0;
    fore(i , n)
    {
        cin>>a[i];
        if(a[i] < k)
        {
            cout<<"Impossible"<<nl;
            return 0;
        }
        sa+=a[i];
    }
    fore(i , m)
    {
        cin>>b[i];
        sb+=b[i];
    }
    int s = sb - sa;
    if(s < 0)
    {
        cout<<"Impossible"<<nl;
        return 0;
    }
    int dp[sb + 1] , reach[sb + 1];
    fore(i , sb + 1)
    {
        dp[i] = -INF;
        reach[i] = 0;
    }
    dp[0] = 0;
    reach[0] = 1;
    for(auto x : b)
    {
        forn(j , sb , 0)
        {
            if(j + x <= sb && reach[j])
            {
                reach[j + x] = 1;
                dp[j + x] = max(dp[j + x] , dp[j] + min(n , x));
            }
        }
    }
    int ans = -1;
    fore(i , sb + 1)
    {
        if(dp[i] >= n*k && i >= sa)
        {
            ans = i;
            break;
        }
    }
    if(ans != -1)
        cout<<ans - sa<<nl;
    else
        cout<<"Impossible"<<nl;
}
