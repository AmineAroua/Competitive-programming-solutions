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
ll dist(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int n;
vector<pair<pair<int,int>,int>> circ;
vi fst(10000,-1);
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        circ.pb(mp(mp(a,b),i));
    }
    sort(circ.begin(),circ.end());
    vi rc,xc,idx;
    for(auto p:circ)
    {
        rc.pb(p.fi.se);
        xc.pb(p.fi.fi);
        idx.pb(p.se);
    }
    int ans = 0;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        bool f1 = 0;
        bool f2 = 0;
        int lb = -1e8, ub=1e8;
        if(upper_bound(xc.begin(),xc.end(),x)!=xc.end())
        {
            ub = upper_bound(xc.begin(),xc.end(),x)-xc.begin();
            f1 = 1;
        }
        if(upper_bound(xc.begin(),xc.end(),x)!=xc.begin())
        {
            lb = upper_bound(xc.begin(),xc.end(),x)-xc.begin()-1;
            f2 = 1;
        }
        bool acc = 1;
        if(f1&&dist(xc[ub],0,x,y)<=rc[ub]*rc[ub])
        {
            if(fst[circ[ub].se]==-1)
                fst[circ[ub].se] = i+1,ans++;
        }
        if(f2&&dist(xc[lb],0,x,y)<=rc[lb]*rc[lb])
        {
            if(fst[circ[lb].se]==-1)
                fst[circ[lb].se] = i+1,ans++;
        }
    }
    cout<<ans<<nl;
    for(int i=0;i<n;i++)
    {
        cout<<fst[i]<<" ";
    }
    cout<<nl;
}
 
 