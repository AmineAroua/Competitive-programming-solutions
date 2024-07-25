#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define pb push_back
#define nl '\n'
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i, x, y) for(int i = x;i<=y;i++)
#define forn(i, y, x) for(int i = y; i >= x; i--)
const int N = 3e5 + 10;
vector<pair<int ,int>> adj[N];
int subtree[N] ;
int belongs[N];
bool forbidden[N];
int join[N] , up[N];
bool decre[N] , incre[N];
void dfs_subtree(int x ,int p)
{
    subtree[x] = 1;
    for(auto [u,i] :adj[x])
    {
        if(u == p || forbidden[u])
            continue;
        dfs_subtree(u , x);
        subtree[x]+=subtree[u];
    }
}
int dfs_down(int x , int p ,int n)
{
    for(auto [u,i] : adj[x])
    {
        if(u == p || forbidden[u])
            continue;
        if(subtree[u] > n/2)
            return dfs_down(u , x , n);
    }
    return x;
}
vector<int> nodes;
void dfs_belong(int x , int p , int child , int edge_p , int edge_join)
{
    nodes.pb(x);
    belongs[x] = child;
    up[x] = edge_p;
    join[x] = edge_join;
    for(auto [u , i] : adj[x])
    {
        if(u == p || forbidden[u])
            continue;
        dfs_belong(u , x , child , i , edge_join);
    }
}
void dfs_incre(int x , int p , int edge_p)
{
    incre[x] = 1;
    for(auto [u,i] : adj[x])
    {
        if(u == p || forbidden[u])
            continue;
        if(i <= edge_p)
            continue;
        dfs_incre(u , x , i);
    }
}
void dfs_decre(int x , int p , int edge_p)
{
    decre[x] = 1;
    for(auto [u,i] : adj[x])
    {
        if(u == p || forbidden[u])
            continue;
        if(i >= edge_p)
            continue;
        dfs_decre(u , x , i);
    }
}
int ans[N];
vector<vector<int>> queriesQ_in_subtree[N] , queriesC_in_subtree[N];
void rec(int root , vector<vector<int>> queriesQ , vector<vector<int>> queriesC)
{
    vector<int>().swap(nodes);
    vector<vector<int>>().swap(queriesQ_in_subtree[root]);
    vector<vector<int>>().swap(queriesC_in_subtree[root]);
    dfs_subtree(root , -1);
    int centroid = dfs_down(root ,-1 , subtree[root]);
    incre[centroid] = 1;
    decre[centroid] = 1;
    belongs[centroid] = centroid;
    for(auto [child,i] : adj[centroid])
    {
        if(!forbidden[child])
        {
            dfs_belong(child , centroid , child , i , i);
            dfs_incre(child , centroid , i);
            dfs_decre(child , centroid , i);
        }
    }
    for(auto query : queriesQ)
    {
        int a = query[0] , b = query[1] , id = query[2];
        if(belongs[a] != belongs[b])
        {
            if(a == centroid)
            {
                ans[id] = (decre[b] && join[b] < id);
            }
            else if(b == centroid)
            {
                ans[id] = (incre[a] && up[a] < id);
            }
            else
                ans[id] = (incre[a] && decre[b] && join[a] > join[b] && up[a] < id);
        }
        else
        {
            queriesQ_in_subtree[belongs[a]].pb(query);
        }
    }
    vector<tuple<int ,int , int>> sweep;
    for(auto node : nodes)
    {
        if(!incre[node])
            continue;
        sweep.pb({up[node] ,0, node});
    }
    for(auto query : queriesC)
    {
        queriesC_in_subtree[belongs[query[0]]].pb(query);
        if(!decre[query[0]])
            continue;
        sweep.pb({query[1] , 1,query[0]});
    }
    sort(sweep.begin() , sweep.end());
    Tree<int> t;
    for(auto [Time , type , node] : sweep)
    {
        if(type == 0)
        {
            t.insert(join[node]);
        }
        else
        {
            if(node == centroid)
            {
                ans[Time]+=(int)t.size() +1;
            }
            else
            {
                ans[Time]+= (int)t.size() - (int)t.order_of_key(join[node] + 1);
                if(join[node] < Time)
                    ans[Time]++;
            }
        }
    }
    for(auto node : nodes)
        decre[node] = incre[node] = 0;
    forbidden[centroid] = 1;
    for(auto [u,i] : adj[centroid])
    {
        if(!forbidden[u])
            rec(u , queriesQ_in_subtree[u] , queriesC_in_subtree[u]);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , q;
    cin>>n>>q;
    vector<vector<int>> queriesQ , queriesC;
    vector<char> type;
    fore(i , n + q - 1)
    {
        char c;
        cin>>c;
        type.pb(c);
        if(c == 'S')
        {
            int a , b;
            cin>>a>>b;
            adj[a].pb({b , i});
            adj[b].pb({a , i});
        }
        if(c == 'Q')
        {
            int a , d;
            cin>>a>>d;
            if(a == d)
                ans[i] = 1;
            else
                queriesQ.pb({a , d , i});
        }
        if(c == 'C')
        {
            int a;
            cin>>a;
            queriesC.pb({a , i});
        }
    }
    rec(1 , queriesQ , queriesC);
    fore(i , n + q - 1)
    {
        if(type[i] == 'Q' )
        {
            cout<<(ans[i] ? "yes" : "no")<<nl;
        }
        if(type[i] == 'C')
            cout<<ans[i]<<nl;
    }
}
