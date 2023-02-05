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
int f(int x)
{
    string s = to_string(x);
    return (int)s.size();
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
        int n;
        cin>>n;
        vi a(n) , b(n);
        vector<map<ll,ll>> occ(2);
        priority_queue<pair<int,bool>> pq;
        fore(i,n)
        {
            cin>>a[i];
            pq.push(mp(a[i] , 0));
            occ[0][a[i]]++;
        }
        fore(i,n)
        {
            cin>>b[i];
            pq.push(mp(b[i] , 1));
            occ[1][b[i]]++;
        }
        int ans = 0;
        while(sz(pq)>1)
        {
            int cur = pq.top().fi ;bool type = pq.top().se;
            if(occ[type][cur]<=0)
            {
                pq.pop();
                continue;
            }
            if(occ[!type][cur]>0)
            {
                occ[type][cur]--;
                occ[!type][cur]--;
                pq.pop();
            }
            else
            {
                occ[type][cur]--;
                cur = f(cur);
                ans++;
                pq.pop();
                pq.push(mp(cur , type));
                occ[type][cur]++;
            }
        }
        cout<<ans<<nl;
    }
}
 