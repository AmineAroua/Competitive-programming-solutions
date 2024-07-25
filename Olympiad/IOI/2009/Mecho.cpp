#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i,x,y) for(int i = x;i<=y;i++)
#define forn(i,y,x) for(int i = y; i >= x; i--)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define rall(v) v.rbegin() , v.rend()
#define pii pair<int,int>
#define pll pair<ll , ll>
 
const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (gcd)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (lcm)
 
// HERE IS THE SOLUTION
const int N = 801;
int n , s;
char grid[N][N];
vi xx = {1 , -1 ,0 , 0};
vi yy = {0 , 0 , 1 , -1};
vector<vi> dBees , dMecho;
int mi , mj , di , dj;
bool notinside(int i , int j)
{
    return !(i<n && j< n && j>=0&&i>=0);
}
vector<vi> modifiedBfs(pii strt , int time)
{
    vector<vi> dist(n , vi(n , INF));
    queue<pii> q;
    q.push(strt);
    dist[strt.fi][strt.se] = 0;
    while(!q.empty())
    {
        pii cur = q.front();
        int i = cur.fi , j = cur.se;
        q.pop();
        fore( k , 4)
        {
            int ni = i + xx[k] , nj = j + yy[k];
            int minutes = (dist[i][j] + 1)/s;
            if(notinside(ni , nj)||grid[ni][nj] == 'T' || grid[ni][nj] == 'H' || grid[ni][nj] == 'D')continue;
            if(dist[ni][nj] > dist[i][j] + 1 && dBees[ni][nj]  > minutes + time )
            {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni , nj});
            }
        }
    }
    return dist;
 
}
vector<vi> bfs(vii cur , bool acc)
{
    vector<vi> dist(n , vi(n , INF));
    queue<pii> q;
    for(auto x : cur)
    {
        dist[x.fi][x.se] = 0;
        q.push(x);
    }
    while(!q.empty())
    {
        pii node = q.front();
        int i  = node.fi , j = node.se;
        q.pop();
        fore(k, 4)
        {
            int ni = i + xx[k] , nj = j + yy[k];
            if(notinside(ni , nj)||grid[ni][nj] == 'T' || grid[ni][nj] == 'H' || grid[ni][nj] == 'D')continue;
            if(dist[ni][nj] > dist[i][j] + 1)
            {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni , nj});
            }
        }
    }
    return dist;
}
 
bool check(int HoneyTime)
{
    if(HoneyTime >= dBees[mi][mj])
        return 0;
    dMecho = modifiedBfs({mi , mj} , HoneyTime);
    fore(k , 4)
    {
        if(!notinside(xx[k] + di , yy[k] + dj) && dMecho[xx[k] + di][yy[k] +dj] != INF)
            return  1;
    }
    return 0;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    cin>>n>>s;
    vii MechoV , beesV;
    fore(i , n)
    {
        fore(j , n)
        {
            cin>>grid[i][j];
            char c = grid[i][j];
            if(c == 'M') {
                mi = i , mj = j;
                MechoV.pb({i, j});
            }
            if(c == 'H')
            {
                beesV.pb({i , j});
            }
            if(c == 'D')
                di = i , dj = j;
        }
    }
    dBees = bfs(beesV  ,1);
    int l = -1, r = n*n + 1;
    while(l + 1 < r)
    {
        int mid = (l + r)/2;
        if(check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout<<l<<nl;
    return 0;
}
