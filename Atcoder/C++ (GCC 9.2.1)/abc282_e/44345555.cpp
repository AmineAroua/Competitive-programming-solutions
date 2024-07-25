#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define pb push_back
#define ld long double
#define nl '\n'
#define boost ios::sync_with_stdio(false)
#define mp make_pair
#define se second
#define fi first
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i,x,y) for(int i = x;i<=y;i++)
#define forn(i,y,x) for(int i = y; i >= x; i--)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define rall(v) v.rbegin() , v.rend()
#define pii pair<int,int>
#define pll pair<ll , ll>
const ll MOD = 1e9 + 7;
//const ll INF = 1e18 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (gcd)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (lcm)

// HERE IS THE SOLUTION
struct DSU
{
    vl e;
    DSU(int x )
    {
        e.assign(x , -1);
    }
    int getPar(int u)
    {
        return (e[u] < 0 ? u : e[u] = getPar(e[u]));
    }
    ll getSize(int u)
    {
        return -e[getPar(u)];
    }
    bool unite(int u , int v)
    {
        u = getPar(u) , v = getPar(v);
        if(u == v)
            return 0;
        if(e[u] > e[v])
            swap(u , v);
        e[u]+=e[v];
        e[v] = u;
        return 1;
    }
};
int bpow(int a , int b , int m)
{
    if(b == 0)
        return 1;
    ll u = bpow(a , b/2 , m);
    u = u*u;
    u%=m;
    if(b%2)
        u*=a;
    u%=m;
    return (int)u;
}
void run_case()
{
    int n,m;
    cin>>n>>m;
    vi a(n);
    fore(i , n)
    {
        cin>>a[i];
    }
    vector<tuple<int , int , int>> edg;
    fore(i , n)
    {
        forr(j , i + 1,  n - 1)
        {
            edg.pb({(bpow(a[i] , a[j] , m) + bpow(a[j] , a[i] , m))%m , i , j});
        }
    }
    DSU dsu(n);
    sort(rall(edg));
    ll ans = 0;
    for(auto [c , u , v] : edg)
    {
        if(dsu.unite(u , v))
        {
            ans+=c;
        }
    }
    cout<<ans<<nl;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t = 1;

    while(t--)
    {
        run_case();
    }
}

