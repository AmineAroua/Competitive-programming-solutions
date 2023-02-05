#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
vl classy;
void gen(int dg , int dis , ll cur)
{
    if(dg==18)
    {
        classy.pb(cur);
        return ;
    }
    gen(dg+1 , dis , cur*10);
    if(dis<3)
    {
        for(int i = 1;i<=9;i++)
        {
            gen(dg+1 , dis + 1 , cur*10+i);
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    gen(0,0,0);
    sort(classy.begin() , classy.end());
    classy.pb(INF);
    int t;
    cin>>t;
    while(t--)
    {
        ll l , r;
        cin>>l>>r;
        cout<<upper_bound(classy.begin() , classy.end(), r) - lower_bound(classy.begin() , classy.end() , l)<<nl;
    }
}
 
 