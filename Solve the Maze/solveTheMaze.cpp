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
vii dir{{0,1},{1,0},{-1,0},{0,-1}};
int n,m;
char grid[50][50];
bool vis[50][50];
bool acc =true;
//functions:

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)

bool check(int i,int j)
{
    return i<n&&i>=0&&j<m&&j>=0;
}

void ffB(int i,int j)
{
    if(!check(i,j)||vis[i][j])
        return;
    vis[i][j]=true;
    if(grid[i][j]=='B')
    {
        for(auto d:dir)
        {
            ffB(i+d.fi,j+d.se);
        }
    }
    else if(grid[i][j]=='G')
    {
        acc = false;
        return;
    }
    else
    {
        grid[i][j]='#';
    }
}
void ff(int i,int j)
{
    if(!check(i,j)||vis[i][j]||grid[i][j]=='#')
        return;
    vis[i][j]=true;
    for(auto d:dir)
    {
        ff(i+d.fi,j+d.se);
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
        cin>>n>>m;
        acc = true;
        memset(vis,0,sizeof(vis));
        forr(i,0,n-1)
        {
            forr(j,0,m-1)
            {
                cin>>grid[i][j];
            }
        }
        forr(i,0,n-1)
        {
            forr(j,0,m-1)
            {
                if(!vis[i][j]&&grid[i][j]=='B')
                {
                    ffB(i,j);
                }
            }
        }
        if(!acc)
        {
            cout<<"NO"<<nl;
            continue;
        }
        forr(i,0,n-1)
        {
            forr(j,0,m-1)
            {
                if(grid[i][j]=='G'&&!vis[i][j])
                {
                    memset(vis,0,sizeof(vis));
                    ff(i,j);
                    if(!vis[n-1][m-1])
                    {
                        acc = false;
                        i=n;
                        break;
                    }
                }
            }
        }
        if(!acc)
        {
            cout<<"NO"<<nl;
        }
        else
        {
            cout<<"YES"<<nl;
        }
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


