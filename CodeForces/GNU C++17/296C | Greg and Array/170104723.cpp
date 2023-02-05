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
    int n,m,k;
    cin>>n>>m>>k;
    vi v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<pair<pair<int,int>,int>> op;
    vl opTr(m,0);
    vl ans(n,0);
    forr(x,1,m)
    {
        int l,r,i;
        cin>>l>>r>>i;
        op.pb({{l,r},i});
    }
    while(k--)
    {
        int opB,opE;
        cin>>opB>>opE;
        opTr[opB-1]++;
        if(opE<m)
            opTr[opE]--;
    }
    ll sum = 0;
    for(int i=0;i<m;i++)
    {
        sum+=opTr[i];
        pair<pair<int,int>,int> opp = op[i];
        ans[opp.fi.fi-1]+=opp.se*sum;
        if(opp.fi.se<n)ans[opp.fi.se]-=opp.se*sum;
    }
    ll res = 0;
    for(int i=0;i<n;i++)
    {
        res+=ans[i];
        cout<<res+v[i]<<" ";
    }
    cout<<nl;
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
 
 