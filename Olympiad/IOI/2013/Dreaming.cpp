#include "dreaming.h"
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int ,int>>> adj;
vector<int> center;
vector<bool> vis;
vector<int> nodes;
void dfs1(int x , int p = -1)
{
    nodes.push_back(x);
    vis[x] = 1;
    for(auto [u , c] : adj[x])
    {
        if(u == p)
            continue;
        dfs1(u , x);
    }
}
vector<vector<int>> dist;
int dfs2(int x ,int i, int p = -1 , int d = 0)
{
    dist[i][x] = d;
    int opt = x;
    for(auto [u , c] : adj[x])
    {
        if(u == p)
            continue;
        int n = dfs2(u , i , x , d + c);
        if(dist[i][opt] < dist[i][n])
            opt = n;
    }
    return opt;
}
int travelTime(int N, int M, int L, int A[], int B[], int T[])
{
    adj.assign(N , {});
    vis.assign(N , 0);
    for(int i = 0 ; i < M; i++)
    {
        adj[A[i]].push_back({B[i] , T[i]});
        adj[B[i]].push_back({A[i] , T[i]});
    }
    dist.assign(2 , vector<int>(N , 0));
    int ans = 0;
    for(int i = 0 ; i < N ; i++)
    {
        if(!vis[i])
        {
            nodes.clear();
            dfs1(i);
            int x = dfs2(i , 0);
            int y = dfs2(x , 0);
            ans = max(ans , dist[0][y]);
            dfs2(y , 1);
            int mn = 2e9;
            for(auto node : nodes)
            {
                mn = min(mn , max(dist[0][node] , dist[1][node]));
            }
            center.push_back(mn);
        }
    }
    sort(center.rbegin(), center.rend());
    if((int)center.size() > 1)
        ans = max(ans , center[0] + center[1] + L);
    if((int)center.size() > 2)
        ans = max(ans , center[1] + center[2] + 2 * L);
    return ans;
}
