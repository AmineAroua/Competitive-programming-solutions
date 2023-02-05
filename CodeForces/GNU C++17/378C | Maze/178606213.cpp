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
char grid[500][500];
bool vis[500][500];
int n,m;
int cur = 0;
int mx = 0;
 
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
bool valid(int i,int j)
{
    return i<n&&i>=0&&j<m&&j>=0&&grid[i][j]=='.';
}
 
void dfs(int i,int j)
{
    if(!valid(i,j)||vis[i][j])
    {
        return;
    }
    vis[i][j] = 1;
    cur++;
    if(cur>mx)
    {
        grid[i][j] = 'X';
    }
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            mx+=grid[i][j]=='.';
            vis[i][j] = 0;
        }
    }
    mx-=k;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(grid[i][j]!='.')continue;
            dfs(i,j);
            i = n+1;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j];
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
 
 