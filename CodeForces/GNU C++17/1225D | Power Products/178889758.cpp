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
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
//variables:
 
 
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
vi pfac(int x)
{
    vi res;
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            res.pb(i);
            x/=i;
        }
    }
    if(x>=2)
    {
        res.pb(x);
    }
    return res;
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int n,k;
    cin>>n>>k;
    vl v(n);
    vi lim(1e5+1);
    for(int i=2;i<=1e5;i++)
    {
        int lst = 1;
        for(int j=1;j<=1e10;j++)
        {
            if(pow(i,j)>1e5)
            {
                lst = j;
                break;
            }
        }
        lim[i] = lst;
    }
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vl occ(1e5+1,0);
    for(int i=0;i<n;i++)
    {
        vi prf = pfac(v[i]);
        map<int,int> cur;
        for(auto x:prf)
        {
            cur[x]++;
        }
        ll nb = 1;
        for(auto p:cur)
        {
            cur[p.fi] = (p.se%k);
            nb*= pow(p.fi,cur[p.fi]);
        }
        occ[nb]++;
        v[i] = nb;
    }
    vl used(1e5+1,0);
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        vi prf = pfac(v[i]);
        map<int,int> cur;
        for(auto x:prf)
        {
            cur[x]++;
        }
        ll nb = 1;
        for(auto p:cur)
        {
            cur[p.fi] = (k-p.se%k)%k;
            if(cur[p.fi]>=lim[p.fi])
            {
                ll res = 0;
                for(int i=0;i<n;i++)
                {
                    if(v[i]!=1)continue;
                    res+=occ[v[i]]-1;
                }
                cout<<res/2<<nl;
                return 0;
            }
            nb*= pow(p.fi,cur[p.fi]);
        }
        used[v[i]]++;
        ans+=occ[nb]-used[nb];
    }
    cout<<ans<<nl;
}
 
 
 
 
/*
 
1/2 half of the contest:
 Read the subject in ~2 min
 Reformulate the topic
 solve examples
 Think of the solution 3 min
 Implement the solution for 20 min
 Pseudo-code your algorithm
 Verify your solution
 Code your solution
 Test your solution
 Debug your code
2/2 half of the contest:
 find the easiest subtasks and try to solve them or give up
 if there are many subtasks, the problem is easy
 if the first subtask is difficult with no much points, the problem is difficult
----------------------------
!(: remember, you are the king of competitive programming
*/
 
 