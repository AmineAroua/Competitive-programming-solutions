#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define pb push_back
#define nl '\n'
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i, x, y) for(int i = x;i<=y;i++)
#define forn(i, y, x) for(int i = y; i >= x; i--)
const int MAX_N = 200010;
const int MAX_K = 1000010;
int k;
int res = MAX_N;
vector<pair<int ,int>> adj[MAX_N];
vector<int> minPath(MAX_K , MAX_N);
bool forbidden[MAX_N];
int sz[MAX_N];
int depth[MAX_N] , dist[MAX_N];
void dfsSZ(int x , int p)
{
    sz[x] = 1;
    for(auto [u,l]   : adj[x])
    {
        if(u == p || forbidden[u])
            continue;
        dfsSZ(u , x);
        sz[x]+=sz[u];
    }
}
int dfs_down(int x , int p , int n)
{
    for(auto [u , l] : adj[x])
    {
        if(u == p || forbidden[u])
            continue;
        if(sz[u] > n/2)
            return dfs_down(u , x , n);
    }
    return x;
}
vector<int> nodes;
void dfs_compute(int x , int p , int L)
{
    nodes.pb(x);
    depth[x] = depth[p] + 1;
    dist[x] = dist[p] + L;
    for(auto [u , l] : adj[x])
    {
        if(u == p || forbidden[u])
            continue;
        dfs_compute(u , x , l);
    }
}
void rec(int root)
{
    dfsSZ(root , -1);
    int n = sz[root];
    int centroid = dfs_down(root , -1 , n);
    depth[centroid] = dist[centroid] = 0;
    minPath[0] = 0;
    vector<int> reset;
    reset.pb(0);
    for(auto [child , l] : adj[centroid])
    {
        if(forbidden[child])
            continue;
        nodes.clear();
        dfs_compute(child , centroid , l);
        for(auto node : nodes)
        {
            if(dist[node] <= k)
                res = min(res , depth[node] + minPath[k - dist[node]]);
        }
        for(auto node : nodes)
        {
            if(dist[node] <= k)
            {
                reset.pb(dist[node]);
                minPath[dist[node]] = min(minPath[dist[node]] , depth[node]);
            }
        }
    }
    for(auto r : reset)
        minPath[r] = MAX_N;
    forbidden[centroid] = 1;
    for(auto [child , l] : adj[centroid])
    {
        if(forbidden[child])
            continue;
        rec(child);
    }
}
int best_path(int N, int K, int H[][2], int L[])
{
    k = K;
    fore(i , N - 1)
    {
        adj[H[i][0]].pb({H[i][1] , L[i]});
        adj[H[i][1]].pb({H[i][0] , L[i]});
    }
    rec(0);
    return (res == MAX_N ? -1 : res);
}
