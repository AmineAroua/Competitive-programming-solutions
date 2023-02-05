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
    vl v(n);
    fore(i,n)
    {
        cin>>v[i];
    }
    sort(v.rbegin() , v.rend());
    vl pref(n);
    pref[0] = v[0];
    for(int i  =1;i<n;i++)
    {
        pref[i] = pref[i-1]+v[i];
    }
    ll ans = 0;
    for(int i = 1;i<=n;i*=4)
    {
        ans+=pref[i-1];
    }
    cout<<ans<<nl;
}
 