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
#define forr(i,x,y) for(int i = x;i<=y;i++)
#define forn(i,y,x) for(ll i = y; i >= x; i--)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define ub upper_bound
#define lb lower_bound

const ll MOD = 2019;
const ll INF = 1e18 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)

// HERE IS THE SOLUTION
ll modPow(ll a , ll b)
{
    if(b==0)
    {
        return 1;
    }
    int u = modPow(a , b/2);
    u*=u;
    u%=MOD;
    if(b%2==1)
    {
        u*=a;
    }
    u%=MOD;
    return u;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    string s;
    cin>>s;
    ll occ[2020];
    clr(occ , 0);
    reverse(all(s));
    ll sum = 0;
    ll ans = 0;
    occ[0] = 1;
    ll n = sz(s);
    fore(i,n)
    {
        ll exp = modPow(10 , i);
        sum+= (exp*(s[i]-48))%MOD;
        sum%=MOD;
        occ[sum]++;
        ans+=occ[sum]-1;
    }
    cout<<ans<<nl;
}

