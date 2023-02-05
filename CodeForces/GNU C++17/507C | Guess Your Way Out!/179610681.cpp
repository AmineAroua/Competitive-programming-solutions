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
ll h,n;
ll ans = 0;
void solve(ll l,ll r,bool dir,ll h)
{
    if(l==r)
    {
        return;
    }
    ll l1,l2,r1,r2;
    if(dir)
    {
        l1 = (l+r)/2 +1;
        l2 = l;
        r1 = r;
        r2 = (l+r)/2;
    }
    else
    {
        l1 = l;
        l2 = (l+r)/2 + 1;
        r1 = (l+r)/2;
        r2 = r;
    }
    if(n<=r1&&n>=l1)
    {
        ans++;
        solve(l1,r1,!dir,h-1);
    }
    else
    {
        ans+=(ll)pow(2,h);
        solve(l2,r2,dir,h-1);
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    cin>>h>>n;
    solve(1,(ll)pow(2,h),0,h);
    cout<<ans<<nl;
}
 
 