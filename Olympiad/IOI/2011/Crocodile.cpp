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
const int inf = 1e9 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (gcd)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (lcm)
 
// HERE IS THE SOLUTION
const int N = 100000;
vii adj[N];
int dijkstra(int n ,vi start)
{
    vector<vi> dist(n ,vi(2 , INF));
    priority_queue<pii> pq;
    for(auto x : start)
    {
        dist[x][0]= dist[x][1] = 0;
        pq.push({0 , x});
    }
    while(!pq.empty())
    {
        int cur = pq.top().se;
        int d = -pq.top().fi;
        pq.pop();
        if(d != dist[cur][1])
            continue;
        for(auto [u,c] : adj[cur])
        {
            if(dist[u][0] > dist[cur][1] + c)
            {
                if(dist[u][0] !=  dist[u][1] && dist[u][0] < INF)
                {
                    dist[u][1] = dist[u][0];
                    dist[u][0] = dist[cur][1] + c;
                    pq.push({-dist[u][1] , u});
                }
                else
                {
                    dist[u][0] = dist[cur][1] + c;
                }
            }
            else if(dist[u][1]>dist[cur][1] + c)
            {
                dist[u][1] = dist[cur][1] + c;
                pq.push({-dist[u][1] , u});
            }
        }
    }
    return dist[0][1];
}
 
int travel_plan(int n , int m , int r[][2] , int l[] , int k , int p[])
{
    fore(i , m)
    {
        adj[r[i][0]].pb({r[i][1] , l[i]});
        adj[r[i][1]].pb({r[i][0] , l[i]});
    }
    vi v;
    fore(i, k)
    {
        v.pb(p[i]);
    }
    return dijkstra(n,v);
 
}
