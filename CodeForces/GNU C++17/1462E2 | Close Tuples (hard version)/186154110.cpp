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
ll ckn[101][2*100000+1];
ll choose(ll k, ll n)
{
    if(k==n||k==0)
    {
        return 1%MOD;
    }
    if(ckn[k][n]==-1)
    {
        ckn[k][n] = (choose(k-1 , n-1)%MOD + choose(k , n-1)%MOD)%MOD;
    }
    return ckn[k][n];
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    memset(ckn , -1 , sizeof(ckn));
    while(t--)
    {
        int n , m , k;
        cin>>n>>m>>k;
        vi v(n);
        for(int i = 0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin() , v.end());
        ll ans = 0;
        for(int i = 0;i<=n-m;i++)
        {
            auto ub = upper_bound(v.begin(),v.end(),v[i]+k);
            int cnt = ub-v.begin()-i-1;
            if(m-1>cnt)continue;
            ans+=choose(m-1 , cnt);
            ans%=MOD;
        }
        cout<<ans<<nl;
    }
}
 
 