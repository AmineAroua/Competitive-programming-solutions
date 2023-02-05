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
bool g = 0;
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
map<pair<int,int>,int> edg;
void dfs(int x,int s,vector<vi> &tree)
{
    int res = 3;
    if(g==1)
    {
        res = 2;
    }
    for(auto v:tree[x])
    {
        if(v==s)
            continue;
        edg.insert(mp(mp(v+1,x+1),res));
        g = !g;
        dfs(v,x,tree);
    }
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
        g = 1;
        edg.clear();
        int n;
        cin>>n;
        vector<vi> tree(n);
        bool acc = true;
        vii edgg;
        forr(i,2,n)
        {
            int a,b;
            cin>>a>>b;
            a--;b--;
            tree[a].pb(b);
            tree[b].pb(a);
            edgg.pb(mp(a+1,b+1));
        }
        for(int i=0;i<n;i++)
        {
            if(tree[i].size()>2)
                acc = false;
        }
        if(!acc)
        {
            cout<<-1<<nl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(tree[i].size()==1)
            {
                dfs(i,-1,tree);
                break;
            }
        }
        for(auto p:edgg)
        {
            if(edg.count(p))
                cout<<edg[p]<<" ";
            else
            {
                cout<<edg[mp(p.se,p.fi)]<<" ";
            }
        }
        cout<<nl;
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
 
 