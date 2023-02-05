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
bool isCube(ll x)
{
    ll l = 0 , r = 1e6+1;
    while(l+1<r)
    {
        ll mid = (l+r)/2;
        if(mid*mid*mid==x)
        {
            return 1;
        }
        if(mid*mid*mid>x)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return 0;
}
ll cube(ll x)
{
    ll l = 0 , r = 1e6+1;
    while(l+1<r)
    {
        ll mid = (l+r)/2;
        if(mid*mid*mid==x)
        {
            return mid;
        }
        if(mid*mid*mid>x)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int n;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        ll cr;
        if(isCube(a*b))
        {
            cr = cube(a*b);
            if(a%cr==0&&b%cr == 0)
            {
                cout<<"Yes"<<nl;
            }
            else
            {
                cout<<"NO"<<nl;
            }
        }
        else
        {
            cout<<"NO"<<nl;
        }
    }
}
 
 