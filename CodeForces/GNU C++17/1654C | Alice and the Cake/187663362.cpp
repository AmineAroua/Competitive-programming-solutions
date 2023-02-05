#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
map<ll,ll> elt;
bool acc = 0;
bool br =  0;
void f(ll u)
{
    if(br)return;
    if(!elt.empty()&&(*elt.begin()).fi>u)
    {
        br = 1;
        return;
    }
    if(elt.count(u))
    {
        elt[u]--;
        if(elt[u]<=0)
        {
            elt.erase(u);
        }
        if(elt.empty())
        {
            acc = 1;
            br = 1;
            return;
        }
        return ;
    }
    if(u==1)
    {
        br = 1;
        return;
    }
    f(u/2);
    f((u+1)/2);
 
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t ;
    cin>>t;
    while(t--)
    {
        br = 0;
        acc = 0;
        elt.clear();
        int n;
        cin>>n;
        vl v(n);
        ll s = 0;
        fore(i,n)
        {
            cin>>v[i];
            s+=v[i];
            elt[v[i]]++;
        }
        f(s );
        if(acc)
        {
            cout<<"yes"<<nl;
        }
        else
        {
            cout<<"no"<<nl;
        }
    }
}
 