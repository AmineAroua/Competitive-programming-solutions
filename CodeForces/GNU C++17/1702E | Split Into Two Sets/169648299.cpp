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
const int N = 2*(1e5);
//variables:
bool acc = true;
vector<vi> graph(N);
vector<bool> vis(N,0);
vector<bool> col(N,0);
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
void dfs(int x,bool c)
{
    vis[x]=true;
    col[x]=c;
    for(auto v:graph[x])
    {
        if(vis[v])
        {
            if(col[v]==c)
            {
                acc = false;
            }
            continue;
        }
        dfs(v,!c);
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
        int n;
        cin>>n;
        vis.assign(n,0);
        col.assign(n,0);
        graph.assign(n,{});
        acc = true;
        vii v;
        forr(i,0,n-1)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            graph[a].pb(b);
            graph[b].pb(a);
            if(a==b||graph[a].size()>=3||graph[b].size()>=3)
            {
                acc = false;
            }
        }
        if(!acc)
        {
            cout<<"NO"<<nl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,0);
                if(!acc)
                {
                    break;
                }
            }
        }
        if(!acc)
        {
            cout<<"NO"<<nl;
            continue;
        }
        cout<<"YES"<<nl;
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
 
 