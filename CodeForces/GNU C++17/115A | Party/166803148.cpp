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
 
const ll MOD = 1e9 + 7;
 
//variables:
 
 
//functions:
 
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
int n;
vector<vector<int>> graph(2001);
vector<bool> visited(2001,false);
 
void dfs(int s)
{
    if(visited[s])
    {
        return;
    }
    visited[s]=true;
    cout<<s<<" ";
    for(auto it:graph[s])
    {
        dfs(it);
    }
}
queue<int> q;
 
void bfs(int s,vi &distance)
{
    visited[s]=true;
    distance[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();q.pop();
        for(auto it:graph[x])
        {
            if(visited[it])
                continue;
            visited[it]=true;
            distance[it]=distance[x]+1;
            q.push(it);
        }
    }
}
 
int main()
{
    boost;
    vi distance(2001,0);
    cin>>n;
    vi parent;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a!=-1)
        {
            graph[a].pb(i+1);
            graph[i+1].pb(a);
        }
        else
        {
            parent.pb(i+1);
        }
    }
    int maxL = 0;
    for(auto p:parent)
    {
        bfs(p,distance);
        for(int i=0;i<2001;i++)
        {
            maxL = max(maxL,distance[i]);
        }
    }
    cout<<maxL+1<<nl;
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
 
 