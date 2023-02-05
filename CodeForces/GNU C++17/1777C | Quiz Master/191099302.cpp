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
vector<vi> di;
vi v;
int mx = 0;
int n,m;
vi divis(int q)
{
    vi res;
    for (int i=1; i*i<=q; i++)
    {
        if (q%i == 0)
        {
            if (q/i == i)
                res.pb(i);
 
            else
                res.pb(i) , res.pb(q/i);
        }
    }
    return res;
}
bool tru(int diff)
{
    int lst = n;
    vi ms(m+1 , 0);
    int cnt = 0;
    forn(i,n-1,0)
    {
        int h = mx;
        int cur = 0;
        if(i!=n-1)
        {
            for(auto d:di[i+1])
            {
                if(d>m)continue;
                ms[d]--;
                if(ms[d]<=0){ms[d] = 0;cnt--;}
            }
        }
        if(cnt==m)return 1;
        for(int j = lst-1;j>=0;j--)
        {
            if(cnt==m)return 1;
            if(v[i]-v[j]>diff){cur = j+1;break;}
            for(auto d:di[j])
            {
                if(d>m)continue;
                if(ms[d]==0)cnt++;
                ms[d]++;
            }
        }
        if(cnt==m)return 1;
        lst = cur;
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
        cin>>n>>m;
        di.assign(n , {});
        v.assign(n , 0);
        fore(i,n)
        {
            int x;
            cin>>x;
            v[i] = x;
        }
        sort(all(v));
        fore(i,n)
        {
            di[i] = divis(v[i]);
        }
        mx = v[n-1];
        int l = -1 , r = mx+1;
        while(l+1<r)
        {
            int diff = (l+r)/2;
            if(tru(diff))
            {
                r = diff;
            }
            else
            {
                l = diff;
            }
 
        }
        if(r==mx+1)cout<<-1<<nl;
        else
        {
            cout<<r<<nl;
        }
    }
}
 