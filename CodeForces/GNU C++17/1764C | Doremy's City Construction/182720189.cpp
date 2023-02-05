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
bool alleq(vi &v)
{
    int lst = v[0];
    for(auto x:v)
    {
        if(x!=lst)return 0;
        lst= x;
    }
    return 1;
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
        vi v(n);
        map<int,ll> occ;
        for(int i =0;i<n;i++)
        {
            cin>>v[i];
            occ[v[i]]++;
        }
        if(alleq(v))
        {
            cout<<n/2<<nl;
            continue;
        }
        ll sum = 0, cur = 0;
        ll ans = 0;
        ll eq = 0;
        for(auto p:occ)
        {
            ll x = p.fi , y = p.se;
            sum+=y;
        }
        for(auto p:occ)
        {
            ll res = cur;
            ll x = p.fi , y = p.se;
            cur+=y;
            res = min(sum-cur , res);
            ans+=res*y;
            eq+=(y*(y-1))/2;
        }
        cout<<(n*(n-1))/2 - ans - eq<<nl;
    }
}
 
 