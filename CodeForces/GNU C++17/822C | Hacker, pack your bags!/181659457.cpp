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
#define all(v) v.begin(),v.end()
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
    int n,x;
    cin>>n>>x;
    vector<vl> lt,rt;
    for(int i =0;i<n;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        lt.pb({a,b,c});
        rt.pb({b,a,c});
    }
 
    sort(all(lt));
    sort(rt.rbegin(),rt.rend());
    vl upd(2e5+1,INF);
    ll ans = INF;
    for(int i = 0;i<n;i++)
    {
        ll l = rt[i][1] , r = rt[i][0] , c = rt[i][2];
        while(!lt.empty()&&lt.back()[0]>r)
        {
            ll _l = lt.back()[0];
            ll _r = lt.back()[1];
            ll _c = lt.back()[2];
            upd[_r-_l+1] = min(upd[_r-_l+1],_c);
            lt.pop_back();
        }
        ll dur = r-l+1;
        ll comp = x-dur;
        if(comp<=0)continue;
        ans = min(ans,upd[comp]+c);
    }
    if(ans == INF)cout<<-1;
    else cout<<ans;
    cout<<nl;
 
}
 
 