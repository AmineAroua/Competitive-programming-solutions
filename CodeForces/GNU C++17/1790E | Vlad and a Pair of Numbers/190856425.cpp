#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        ll s = x*2;
        ll cur = (x+1)/2;
        ll a = 0, b = 0;
        bool acc = 1;
        for (ll i=0; i<8*sizeof(s); i++)
        {
            ll Xi = (x & (1 << i));
            ll Ai = (cur & (1 << i));
            if (Xi == 0 && Ai == 0)
            {
 
            }
            else if (Xi == 0 && Ai > 0)
            {
                a = ((1 << i) | a);
                b = ((1 << i) | b);
            }
            else if (Xi > 0 && Ai == 0)
            {
                a = ((1 << i) | a);
            }
            else
            {
                cout<<-1<<nl;
                acc = 0;
                break;
            }
        }
        if(!acc)
        {
            continue;
        }
        cout<<a<<" "<<b<<nl;
    }
}
 