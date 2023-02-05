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
ll fact(ll x)
{
    if(x==0)return 1;
    return ((fact(x-1))%MOD*x%MOD)%MOD;
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
        vl v(n);
        for(int i = 0;i<n;i++)
        {
            cin>>v[i];
        }
        ll an = v[0];
        for(int i = 1;i<n;i++)
        {
            an = (an&v[i]);
        }
        ll occ = 0;
        for(int i = 0;i<n;i++)
        {
            if(v[i]==an)
            {
                occ++;
            }
        }
        ll ans = ((occ*(occ-1)))%MOD * ((fact(n-2))%MOD);
        ans%=MOD;
        cout<<ans<<nl;
    }
}
 
 