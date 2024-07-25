#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
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
const ll INF = 1e18 + 1;
const int inf = 1e9 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (gcd)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (lcm)

// HERE IS THE SOLUTION
const int N = 50;
int n;
int a[N] , b[N];
bool vis[N + 1];
vi modList;
void dfs(int x , int maxMod)
{
    if(vis[x])
        return;
    vis[x] = 1;
    forr(mod , 1 , min(maxMod , x))
    {
        dfs(x%mod, maxMod);
    }
    for(auto mod : modList)
    {
        dfs(x%mod , maxMod);
    }
}
bool check(int maxMod)
{
    fore(i, n)
    {
        fore(j , N + 1)
            vis[j] = 0;
        int x = a[i] , y = b[i];
        dfs(x ,maxMod);
        if(!vis[y])
            return 0;
    }
    return 1;
}
int solve(int i)
{
    if(i == 0)
        return 0;
    int l = -1 , r = i + 1;
    while(l + 1 < r)
    {
        int mid = (l + r)/2;
        if(check(mid))
        {
            r= mid;
        }
        else
        {
            l = mid;
        }
    }
    if(r == i + 1)
    {
        return ((1ll << r) - 1);
    }
    if(r == 0)
        return  0;
    modList.pb(r);
    return (1ll<<r) + solve(r - 1);
}
signed main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    cin>>n;
    fore(i , n)
        cin>>a[i];
    bool zero  = 0;
    bool eq = 1;
    fore(i , n)
    {
        cin>>b[i];
        if(b[i])zero = 1;
        if(b[i] != a[i])
            eq  = 0;
    }
    if(eq)
    {
        cout<<0<<nl;
        return 0;
    }

    int ans = solve(50);
    cout<<(ans == 2251799813685247 ? -1 : ans)<<nl;
}