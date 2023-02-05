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
const int N  = 1e5;
//variables:
vector<vi> adj(26);
vector<bool> vis(26,0);
bool acc = 1;
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
void dfs(int x,int p)
{
    if(vis[x])
    {
        acc = 0;
        return;
    }
    vis[x] = 1;
    for(auto u:adj[x])
    {
        if(u==p)
        {
            continue;
        }
        dfs(u,x);
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
        adj.clear();
        adj.assign(26,{});
        vis.clear();
        vis.assign(26,0);
        int n;
        string s;
        string res;
        cin>>n>>s;
        vi parof(26,-1);
        vector<bool> used(26,0);
        set<char> st;
        for(auto c:s)
        {
            st.insert(c);
            int cur = c-'a';
            if(parof[cur]!=-1)
            {
                res.pb(parof[cur]+'a');
                continue;
            }
            for(int let=0;let<26;let++)
            {
                if(used[let])
                {
                    continue;
                }
                vis.assign(26,0);
                acc = 1;
                adj[let].pb(cur);
                adj[cur].pb(let);
                dfs(let,-1);
                if(!acc&&st.size()<26)
                {
                    adj[let].pop_back();
                    adj[cur].pop_back();
                }
                else
                {
                    used[let] = 1;
                    res.pb(let+'a');
                    parof[cur] = let;
                    break;
                }
            }
        }
        cout<<res<<nl;
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
 
 