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
        vii v(n);
        int a = 0,b = 0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i].se;
            a+=v[i].se==0;
            b+=v[i].se==1;
        }
        for(int i=0;i<n;i++)
        {
            cin>>v[i].fi;
        }
        vi aa,bb;
        for(auto p:v)
        {
            if(p.se==0)
            {
                aa.pb(p.fi);
            }
            else
            {
                bb.pb(p.fi);
            }
        }
        sort(aa.begin(),aa.end(),greater<int>());
        sort(bb.begin(),bb.end(),greater<int>());
        int mn = min(a,b);
        ll ans =0;
        for(int i=0;i<mn;i++)
        {
            ans+=2*aa[i];
            ans+=2*bb[i];
        }
        for(int i=mn;i<a;i++)
        {
            ans+=aa[i];
        }
        for(int i=mn;i<b;i++)
        {
            ans+=bb[i];
        }
        if(a==b)
        {
            ans-=min(aa[a-1],bb[a-1]);
        }
        cout<<ans<<nl;
    }
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
 
 