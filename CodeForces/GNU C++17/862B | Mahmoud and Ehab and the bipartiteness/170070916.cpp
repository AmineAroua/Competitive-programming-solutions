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
vector<vi> tree(1e5);
vector<bool> col(1e5);
ll a=0,b=0;
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
void dfs(int x,int s,bool c)
{
    col[x]=c;
    a+=c==0;
    b+=c==1;
    for(auto v:tree[x])
    {
        if(v==s)
            continue;
        dfs(v,x,!c);
    }
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int n;
    cin>>n;
    forr(i,2,n)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(0,0,0);
    ll res= a*b;
    for(int i=0;i<n;i++)
    {
        if(col[i]==1)
        {
            res-=(ll)(tree[i].size());
        }
    }
    cout<<res<<nl;
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
 
 