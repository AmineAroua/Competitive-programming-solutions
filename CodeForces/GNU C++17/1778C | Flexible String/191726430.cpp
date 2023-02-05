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
vector<pair<char,vi>> v , sub;
string a,b;
int k,n;
ll ans = 0;
ll solve(string s)
{
    ll cur = 0;
    ll nb = 0;
    forr(i , 0 , n-1)
    {
        if(s[i]==b[i])
        {
            cur++;
        }
        else
        {
            nb+=(cur*(cur+1))/2;
            cur = 0;
        }
    }
    nb+=(cur*(cur+1))/2;
    return nb;
}
void subset(int i,int h)
{
    if(i==k)
    {
        string s=a;
        for(auto p:sub)
        {
            vi now = p.se;
            for(auto j:now)
            {
                s[j] = b[j];
            }
        }
        ans = max(ans , solve(s));
        return ;
    }
    forr(j , h , sz(v)-1)
    {
        sub.pb(v[j]);
        subset(i+1,j+1);
        sub.pop_back();
    }
    return ;
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
        sub.clear();
        ans = 0;
        v.clear();
        cin>>n>>k;
        cin>>a>>b;
        map<char , vi> pos;
        fore(i, n)
        {
            pos[a[i]].pb(i);
        }
        for(auto p:pos)
        {
            v.pb(p);
        }
        int m = sz(v);
 
        if(sz(v)<=k)
        {
            string s = a;
            for(auto p:v)
            {
                vi now = p.se;
                for(auto j:now)
                {
                    s[j] = b[j];
                }
            }
            ans = max(ans , solve(s));
        }
        else subset(0,0);
        cout<<ans<<nl;
    }
}
 