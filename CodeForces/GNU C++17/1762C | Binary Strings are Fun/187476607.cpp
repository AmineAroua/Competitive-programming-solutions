#include <bits/stdc++.h>
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
#define forn(i, x) for(ll i = x-1; i >= 0; i--)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define ub upper_bound
#define lb lower_bound
 
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const ll INF = 1e18 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
// HERE IS THE SOLUTION
ll mpow(ll u,ll v)
{
    if(v==0)
    {
        return 1%mod;
    }
    ll x = mpow(u,v/2);
    x%=mod;
    x*=x;
    x%=mod;
    if(v%2==1)
    {
        x*=u;
        x%=mod;
    }
    return x%mod;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(n==1)
        {
            cout<<1<<nl;
            continue;
        }
        ll ans = 0;
        char lst = s[0];
        int  i = 0;
        while(i<n)
        {
            int cur = 0;
            while(lst==s[i]&&i<n)
            {
                cur++;
                i++;
            }
            ans+=(mpow(2,cur) - 1)%mod;
            ans%=mod;
            if(i==n)
            {
                break;
            }
            lst = s[i];
        }
        cout<<ans<<nl;
    }
}
 