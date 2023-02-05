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
        int n;
        cin>>n;
        vi v(n);
        fore(i,n)
        {
            cin>>v[i];
        }
        vi p(n) , q(n);
        bool acc = 0;
        for(int i = 0;i<n;i++)
        {
            if(v[i]==n)
            {
                acc = 1;
            }
        }
        vi occ(n+1,  0);
        for(int i = 0;i<n;i++)
        {
            occ[v[i]]++;
            if(occ[v[i]]==3)
            {
                acc = 0;
            }
        }
        vi a = v;
        sort(all(a));
        fore(i,n)
        {
            if(a[i]<i+1)
            {
                acc = 0;
                break;
            }
        }
        if(!acc)
        {
            cout<<"no"<<nl;
            continue;
        }
        vii ftchp , ftchq;
        vector<bool> up(n+1 , 0) , uq(n+1 , 0);
        fore(i , n)
        {
            int cur = v[i];
            if(!up[cur])
            {
                p[i] = cur;
                ftchp.pb(mp(cur , i));
                up[cur] = 1;
            }
            else
            {
                q[i] = cur;
                ftchq.pb(mp(cur , i));
                uq[cur] = 1;
            }
        }
        sort(all(ftchp));
        sort(all(ftchq));
        vi nup , nuq;
        for(int  i = 1;i<=n;i++)
        {
            if(!up[i])
            {
                nup.pb(i);
            }
            if(!uq[i])
            {
                nuq.pb(i);
            }
        }
        int i = 0;
        for(auto x:ftchp)
        {
            int idx = x.se;
            q[idx] = nuq[i];
            i++;
        }
        i = 0;
        for(auto x:ftchq)
        {
            int idx = x.se;
            p[idx] = nup[i];
            i++;
        }
        cout<<"yes"<<nl;
        for(auto x:p)cout<<x<<" ";
        cout<<nl;
        for(auto x:q)cout<<x<<" ";
        cout<<nl;
    }
}
 