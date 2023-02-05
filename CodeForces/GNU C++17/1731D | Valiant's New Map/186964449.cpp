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
bool check(ll n,ll m,vector<vi> &g , ll md)
{
    vi u(m+1 , 0);
    vector<vi> v(n+1 , u) , pref(n+1 , u);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            v[i+1][j+1] = (g[i][j]>=md);
            ll q  = v[i+1][j+1] ;
            q--;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            pref[i][j] = v[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            ll q = pref[i][j] ;
            q--;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        if(i+md-1>n)break;
        for(int j = 1;j<=m;j++)
        {
            if(j+md-1>m)break;
            ll r = i+md-1 , c = j+md-1;
            ll sq = pref[r][c] - pref[i-1][c] -pref[r][j-1] + pref[i-1][j-1];
            if(sq==md*md)
            {
                return 1;
            }
        }
    }
    return 0;
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
        ll n , m;
        cin>>n>>m;
        vi v(m);
        vector<vi> g(n , v);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                cin>>g[i][j];
            }
        }
        ll l = 1 , r = 1e3+1;
        while(l+1<r)
        {
            ll md = (l+r)/2;
            if(check(n,m,g,md))
            {
                l = md;
            }
            else
            {
                r = md;
            }
        }
        cout<<l<<nl;
    }
}
 
 