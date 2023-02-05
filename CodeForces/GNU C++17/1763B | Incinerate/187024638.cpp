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
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vi h(n);
        vii v(n);
        for(int i = 0;i<n;i++)
        {
            cin>>v[i].fi;
            h[i] = v[i].fi;
        }
        for(int i = 0;i<n;i++)
        {
            cin>>v[i].se;
        }
        sort(v.begin() , v.end());
        sort(h.begin() , h.end());
        vi sufmn(n+1,1e8);
        sufmn[n] = -1;
        sufmn[n-1] = v[n-1].se;
        for(int i = n-2;i>=0;i--)
        {
            sufmn[i] = min(sufmn[i+1] , v[i].se);
        }
        int beg = 0 , cur=  k;
        bool acc = 0;
        while(k>0)
        {
            beg = upper_bound(h.begin()+beg , h.end(),cur) - h.begin();
            k-=sufmn[beg];
            cur+=k;
            if(beg == n)
            {
                acc = 1;
                break;
            }
        }
        if(acc)
        {
            cout<<"YES"<<nl;
        }
        else
        {
            cout<<"NO"<<nl;
        }
    }
}
 
 