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
        vl v(n+1);
        fore(i,n)
        {
            cin>>v[i+1];
        }
        if(n==1)
        {
            cout<<0<<nl;
            continue;
        }
        ll s = 0;
        ll  ans = 0;
        priority_queue<ll> pq;
        for(int i = m;i>=2;i--)
        {
            s+=v[i];
            if(v[i]>0)
            {
                pq.push(v[i]);
            }
            if(s>0)
            {
                ll tp = pq.top();
                pq.pop();
                s-=2*tp;
                ans++;
            }
        }
        ll q = 0;
        priority_queue<ll> pqq;
        for(int i = m+1;i<=n;i++)
        {
            q+=v[i];
            if(v[i]<0)
            {
                pqq.push(abs(v[i]));
            }
            if(q<0)
            {
                ll tp = pqq.top();
                tp = -tp;
                pqq.pop();
                ans++;
                q-=2*tp;
            }
        }
        cout<<ans<<nl;
    }
}
 