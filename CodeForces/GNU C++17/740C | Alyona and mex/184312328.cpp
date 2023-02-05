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
    int n , m;
    cin>>n>>m;
    int d = 1e8;
    for(int i = 0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        d = min(b-a , d);
    }
    vi ans(n);
    for(int i  = 0;i<n;i+=d+1)
    {
        for(int j = i;j<=i+d&&j<n;j++)
        {
            ans[j] = j-i;
        }
    }
    cout<<d+1<<nl;
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<nl;
}
 
 