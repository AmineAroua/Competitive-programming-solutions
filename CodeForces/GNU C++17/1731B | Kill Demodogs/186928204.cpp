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
        n--;
        ll s = (n*(n+1))/2;
        s%=MOD;
        s*=3;
        s%=MOD;
        s+=n;
        s%=MOD;
        ll x = 1;
        if((n+1)%3==0)
        {
            x = (n+1)/3;
            x*=((2*n+1)*(n))%MOD;
            x%=MOD;
        }
        else if(n%3==0)
        {
            x = n/3;
            x*=((n+1)*(2*n+1))%MOD;
            x%=MOD;
        }
        else if((2*n+1)%3==0)
        {
            x = (2*n+1)/3;
            x%=MOD;
            x*=((n+1)*n)%MOD;
            x%=MOD;
        }
        s+=x;
        s%=MOD;
        s+=1;
        s%=MOD;
        s*=2022;
        s%=MOD;
        cout<<s<<nl;
    }
}
 
 