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
vl fib(100,-1);
ll f(ll k)
{
    if(k==1)
    {
        return 2;
    }
    if(k==2)
    {
        return 3;
    }
    if(fib[k]!=-1)
    {
        return fib[k];
    }
    ll ans = f(k-1)+f(k-2);
    fib[k] = ans;
    return ans;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    ll n;
    cin>>n;
    if(n==2)
    {
        cout<<1<<nl;
        return 0;
    }
    n-=3;
    ll k = 1;
    ll s  = 0;
    ll ans= 0;
    while(s+f(k)<=n)
    {
        s+=f(k);
        k++;
    }
    cout<<k+1<<nl;
}
 
 