#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
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
#define fore(i, y) for(ll i = 0; i < y; i++)
#define forr(i,x,y) for(int i = x;i<=y;i++)
#define forn(i,y,x) for(ll i = y; i >= x; i--)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define ub upper_bound
#define lb lower_bound
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
// HERE IS THE SOLUTION
int n;
string s , res;
vector<vi> occ;
vector<bool> vis;
int ans = 0;
bool SortByLength(pair<vi,int> &a , pair<vi,int> &b)
{
    vi x = a.fi , y = b.fi;
    return sz(x)>sz(y);
}
void solve(int nb , int trg)
{
    vector<pair<vi, int>> vc;
    for(int i = 0;i<26;i++)
    {
        int c = i;
        vi v = occ[c];
        vc.pb(mp(v , c));
    }
    sort(all(vc) , SortByLength);
    map<int,int> oc;
    forr(i , 0 , nb-1)
    {
        vi v = vc[i].fi ;int c = vc[i].se;
        int ln = sz(v);
        int mn = min(ln , trg);
        forr(j , 0 , mn-1)
        {
            vis[v[j]] = 1;
        }
        oc[c] = trg - ln;
        if(oc[c]<=0)
        {
            oc.erase(c);
        }
    }
    fore(i , n)
    {
        if(vis[i])continue;
        int c = (oc.begin()) -> fi;
        res[i] = char(c+'a');
        oc[c]--;
        if(oc[c]<=0)oc.erase(c);
        ans++;
    }
}
vi divisors()
{
    vi ar;
    for(int i = 1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i != n)
            {
                ar.pb(i) , ar.pb(n/i);
            }
            else
            {
                ar.pb(i);
            }
        }
    }
    return ar;
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
        cin>>n>>s;
        occ.clear();
        occ.assign(26 , {});
        vis.clear();
        vis.assign(n , 0);
        fore(i,n)
        {
            occ[s[i]-'a'].pb(i);
        }
        ans = 0 ;int nb = 0 , trg = 0;
        res = s;
        vi div = divisors();
        sort(all(div));
        string fin ;
        int best  = 1e8;
        for(auto x:div)
        {
            nb = n/x;
            if(nb>26)continue;
            trg = x;
            solve(nb , trg);
            if(ans<best)
            {
                best = ans;
                fin = res;
            }
            ans = 0;
            res = s;
            vis.clear();
            vis.assign(n , 0);
 
        }
        cout<<best<<nl<<fin<<nl;
    }
}
 