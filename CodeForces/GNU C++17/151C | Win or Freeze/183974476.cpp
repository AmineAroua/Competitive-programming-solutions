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
ll pf(ll x)
{
    ll p = 1;
    ll cur = 0;
    ll now = 0;
    for(ll i = 2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            cur++;
            p*=i;
            x/=i;
            if(cur==2)
            {
                now = p;
            }
        }
    }
    if(x>1)
    {
        p*=x;
        cur++;
    }
    if(cur>2)
    {
        return now;
    }
    if(cur == 2)
    {
        return -2;
    }
    if(cur==1)
    {
        return -1;
    }
 
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    ll q;
    cin>>q;
    if(q==1){cout<<1<<nl<<0<<nl;return 0;}
    ll res = pf(q);
    if(res==-1)
    {
        cout<<1<<nl<<0<<nl;
    }
    else if(res==-2)
    {
        cout<<2<<nl;
    }
    else
    {
        cout<<1<<nl;
        cout<<res<<nl;
    }
}
 
 