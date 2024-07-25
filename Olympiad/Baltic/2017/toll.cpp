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
#define sz(v) (int)v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define rall(v) v.rbegin() , v.rend()
#define pii pair<int,int>
#define pll pair<ll , ll>
#define vvi vector<vi>
#define vvii vector<vii>
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (gcd)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (lcm)
 
// HERE IS THE SOLUTION
int N , K , M , O;
const int LOG = 15;
int lim;
vector<vi> comb(vector<vi> a , vector<vi> b)
{
    vector<vi> target(K , vi(K , INF));
    fore(x , K)
    {
        fore(y , K)
        {
            fore(z , K)
            {
                target[x][y] = min(target[x][y]  , a[x][z] + b[z][y]);
            }
        }
    }
    return target;
}
vector<vvi> tree;
vvi query(int l , int r)
{
    l+=lim;
    r+=lim;
    if(l == r)
    {
        return tree[l];
    }
    vvi resL = tree[l] , resR = tree[r];
    while(l + 1< r)
    {
        if(l%2 == 0)
        {
            resL = comb(resL , tree[l + 1]);
        }
        if(r%2 == 1)
        {
            resR = comb(tree[r - 1] , resR);
        }
        l>>=1;
        r>>=1;
    }
    return comb(resL ,resR);
}
 
signed main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    cin>>K>>N>>M>>O;
    lim = (N+ K - 1)/K;
    while(__builtin_popcount(lim) != 1)
    {
        lim++;
    }
    tree.assign(2*lim , vvi(K , vi(K , INF)));
    fore(i , M)
    {
        int a , b ,t;
        cin>>a>>b>>t;
        tree[lim + (a/K)][a%K][b%K] = min(tree[lim + (a/K)][a%K][b%K] , t);
    }
    forn(i , lim - 1 , 1)
    {
        tree[i] = comb(tree[2*i] , tree[2*i + 1]);
    }
    while(O--)
    {
        int a , b;
        cin>>a>>b;
        if(a/K == b/K)
        {
            cout<<-1<<nl;
            continue;
        }
        int ans = query(a/K , (b/K) - 1)[a%K][b%K];
        if(ans == INF)
            cout<<-1<<nl;
        else
            cout<<ans<<nl;
    }
}
