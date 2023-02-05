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
const int imp = 1e6;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
// HERE IS THE SOLUTION
bool primes[1001];
pair<int,char> mx;
int n;
string ans;
void sieve()
{
    for(int i = 2;i<=1000;i++)
    {
        if(primes[i])
        {
            for(int j = 2*i;j<=1000;j+=i)
            {
                primes[j] = 0;
            }
        }
    }
}
void solve(int p)
{
    for(int i = p;i<=n;i+=p)
    {
        if(ans[i]!='.')continue;
        ans[i] = mx.se;
        mx.fi--;
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    string s;
    cin>>s;
    n = sz(s);
    ans.assign(n+1 , '.');
    clr(primes , 1);
    sieve();
    map<char, int> occ;
    for(auto c:s)
    {
        occ[c]++;
        if(occ[c]>mx.fi)
        {
            mx.fi = occ[c] , mx.se = c;
        }
    }
    for(int i = 2;i<=n;i++)
    {
        if(i%2==0)
        {
            mx.fi--;
            ans[i] = mx.se;
        }
    }
    for(int i = 2;i<=n;i++)
    {
        if(!primes[i])continue;
        if(i*2<=n)
        {
            solve(i);
        }
    }
    if(mx.fi < 0)
    {
        cout<<"NO"<<nl;
        return 0;
    }
    cout<<"YES"<<nl;
    occ[mx.se]=mx.fi;
    vi mis;
    forr(i,1,n)
    {
        if(ans[i]=='.')
        {
            mis.pb(i);
        }
    }
    int cnt = 0;
    for(auto p:occ)
    {
        if(p.se)
        {
            while(p.se--)
                ans[mis[cnt]] = p.fi , cnt++;
        }
    }
    for(int i = 1;i<=n;i++)cout<<ans[i];
    cout<<nl;
}
 