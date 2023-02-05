#include <bits/stdc++.h>
using namespace std;
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
#define forr(i, x, y) for(ll i = x; i <= y; i++)
#define forn(i, x, y) for(ll i = x; i >= y; i--)
#define all(v) (v.begin(),v.end())
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
// HERE IS THE SOLUTION
vl solve(2e5+1 , -1);
ll f(int x , ll m)
{
    if(m+x<10)return 1;
    m-=10-x;
    if(m<=8&&m>=0)return 2;
    if(m==9)return 3;
    if(solve[m]==-1)
    {
        solve[m] = (f(10,m-9) + f(10,m-10))%MOD;
    }
    return solve[m]%MOD;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    //freopen("in.txt" , "r" , stdin);
    int t;
    cin>>t;
    while(t--)
    {ll m;
    string n;
    cin>>n>>m;
    ll ans = 0;
    for(auto c:n)
    {
        ans+=(f(c-48 , m))%MOD;
        ans%=MOD;
    }
    cout<<ans<<nl;}
}
 
 