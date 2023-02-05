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
vi fac(ll u)
{
    vi ans;
    for(int i = 1;i*i<=u;i++)
    {
        if(u%i!=0)continue;
        if(i*i!=u)
        {
           ans.pb(i);
           ans.pb(u/i);
        }
        else
        {
            ans.pb(i);
        }
    }
    return ans;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    ll a,b;
    cin>>a>>b;
    ll d = gcd(a,b);
    vi div = fac(d);
    sort(div.begin() , div.end());
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        ll l , r;
        cin>>l>>r;
        ll nxt = *(upper_bound(div.begin(), div.end(),r)-1);
        if(nxt>=l)
        {
            cout<<nxt<<nl;
        }
        else
        {
            cout<<-1<<nl;
        }
    }
}
 
 