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
bool check(int a,int b,int c,int d)
{
    return a<b&&c<d&&a<c&&b<d;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vl v(n);
        for(int i = 0;i<n;i++)
        {
            cin>>v[i];
        }
        double mn = 1e9 , mx = 0;
        for(int i=0;i<n-1;i++)
        {
            if(v[i]-v[i+1]<0)
            {
                mn = min(mn , (v[i]+v[i+1])/2.0);
            }
            else if(v[i]-v[i+1]>0)
            {
                mx = max(mx,(v[i]+v[i+1])/2.0);
            }
            else
            {
                continue;
            }
        }
        if(mn>=mx)
        {
            ll x =(ll)(floor(mn));
            if(x>=mx)
            {
                cout<<x<<nl;
                continue;
            }
        }
        cout<<-1<<nl;
    }
}
 
 