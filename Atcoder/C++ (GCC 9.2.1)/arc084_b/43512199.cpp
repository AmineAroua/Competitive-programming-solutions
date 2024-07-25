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

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (PPCM)

// HERE IS THE SOLUTION

int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int n , m;
    cin>>n>>m;
    vector<vector<pair<int , char>>> adj(n);
    queue<pii> q;
    int dist[n][n];
    fore(i , n)
    {
        fore(j , n)
        {
            dist[i][j] = INF;
        }
    }
    fore(i , m)
    {
        int u , v;
        char c;
        cin>>u>>v>>c;
        u-- , v--;
        adj[u].pb({v , c});
        adj[v].pb({u , c});
        q.push({u , v});
        dist[u][v] = 1;
        dist[v][u]  = 1;
    }
    fore(i , n)
    {
        q.push({i  , i});
        dist[i][i] = 0;
    }
    while(!q.empty())
    {
        pii cur = q.front();
        q.pop();
        int i  = cur.fi , j = cur.se;
        for(auto &[x , c] : adj[i])
        {
            for(auto &[y , cc] : adj[j])
            {
                if(cc != c)continue;
                if(dist[x][y] > dist[cur.fi][cur.se] + 2)
                {
                    dist[x][y] = dist[y][x] = dist[cur.fi][cur.se] + 2;
                    q.push({x , y});
                }
            }
        }
    }
    if(dist[0][n - 1] != INF)cout<<dist[0][n - 1]<<nl;
    else
        cout<<-1<<nl;
}

