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
vii dir{{1,-1},{1,1},{-1,-1},{-1,1}};
vii corn{{1,1},{-1,1},{1,-1},{-1,-1}};
vii nxy{{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
char grid[50][50];
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
bool check(pair<int,int> d,int i,int j)
{
    int ni = d.fi+i;
    int nj = d.se+j;
    return ni>=0&&ni<n&&nj>=0&&nj<m;
}
 
bool iscorn(int i,int j,int ni,int nj)
{
    int nbC = 0;
    for(auto c:corn)
    {
        int di = c.fi+ni;
        int dj = c.se+nj;
        if(check(c,ni,nj))
        {
            if(grid[di][dj]=='*')
            {
                nbC++;
            }
        }
    }
    if(ni!=i||nj!=j)
    {
        return nbC>1;
    }
    else
    {
        return nbC>0;
    }
}
bool isadj(int i,int j)
{
    int nbA = 0;
    for(auto xy:nxy)
    {
        int ni = xy.fi+i;
        int nj = xy.se+j;
        if(check(xy,i,j))
        {
            if(grid[ni][nj]=='*')
            {
                nbA++;
            }
        }
    }
    return nbA>1;
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
        bool vis[n][m];
        for(int i=0;i<n;i++)
        {
            forr(j,0,m-1)
            {
                cin>>grid[i][j];
                vis[i][j]=0;
            }
        }
        bool acc = true;
        forr(i,0,n-1)
        {
            forr(j,0,m-1)
            {
                if(grid[i][j]=='*')
                {
                    int ti,tj;
                    int nbS = 0;
                    for(auto d:dir)
                    {
                        int ni = i+d.fi;
                        int nj = j+d.se;
                        if(check(d,i,j))
                        {
                            if(grid[i][nj]=='*'&&grid[ni][j]=='*')
                            {
                                if(iscorn(i,j,i,j)||iscorn(i,j,i,nj)||iscorn(i,j,ni,j)||isadj(i,nj)||isadj(ni,j))
                                {
                                    acc = false;
                                    break;
                                }
                                nbS++;
                                ti = ni;
                                tj = nj;
                            }
                        }
                    }
                    if(nbS>1)
                    {
                        acc = false;
                        break;
                    }
                    if(nbS==1)
                    {
                        vis[i][tj]=true;
                        vis[ti][j]=true;
                        vis[i][j]=true;
                    }
                }
            }
        }
        forr(i,0,n-1)
        {
            forr(j,0,m-1)
            {
                if(grid[i][j]=='*'&&!vis[i][j])
                    acc = false;
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
 
 