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
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vll v(n);
        vl a(n);
        fore(i,n)
        {
            cin>>v[i].fi;
            a[i] = v[i].fi;
            v[i].se = i;
        }
        sort(all(v));
        ll s = 0;
        int wn = 0;
        fore(i,n)
        {
            if(s+v[i].fi>m)
            {
                break;
            }
            wn++;
            s+=v[i].fi;
        }
        if(wn==n)
        {
            cout<<1<<nl;
            continue;
        }
        if(wn==0)
        {
            cout<<n+1<<nl;
            continue;
        }
        bool acc =  0;
        fore(i,wn)
        {
            if(v[i].se==wn)
            {
                acc = 1;
            }
        }
        if(acc)
        {
            cout<<n-wn<<nl;
            continue;
        }
        s = s+a[wn]-v[wn-1].fi;
        if(s<=m)
        {
            cout<<n-wn<<nl;
        }
        else
        {
            cout<<n-wn+1<<nl;
        }
    }
}
 