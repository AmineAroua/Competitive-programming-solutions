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
 
int n,p;
vi pos1,pos2;
string s;
int solve(vi &pos)
{
    int res = 0;
    int s1 = 0,s2 = 0;
    int k = p;
    int j = pos.size();
    for(int i=0;i<pos.size();i++)
    {
        if(pos[i]>k)
        {
            j= i;
            break;
        }
    }
    for(int i = j-1;i>=0;i--)
    {
        s1+=k-pos[i];
        k = pos[i];
    }
    k = p;
    for(int i=j;i<pos1.size();i++)
    {
        s2+=pos[i]-k;
        k = pos[i];
    }
    res = s1+s2+min(s1,s2);
    return res;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    cin>>n>>p;
    cin>>s;
    ll ans = 0;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
        {
            int a = (int)s[i] - 'a',b = (int)s[n-1-i] -'a';
            ans+=min(26-max(a,b)+min(a,b),abs(a-b));
            pos1.pb(n-i);
            pos2.pb(i+1);
        }
    }
    sort(pos1.begin(),pos1.end());
    sort(pos2.begin(),pos2.end());
    cout<<min(solve(pos1),solve(pos2))+ans<<nl;
}
 
 