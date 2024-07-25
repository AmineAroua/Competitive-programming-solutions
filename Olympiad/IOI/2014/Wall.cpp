#include "wall.h"
#include<bits/stdc++.h>
using namespace std;
int BASE;
struct Node
{
    int mn , mx;
};
vector<Node> tree , lazy;
void build(int n)
{
    while(__builtin_popcount(BASE) != 1)
        BASE++;
    tree.assign(2*BASE , {(int)1e9  , (int)-1e9});
    lazy.assign(2*BASE , {(int)1e9 , -1});
    for(int i = 0 ; i < n ; i++)
    {
        tree[i + BASE].mx = tree[i + BASE].mn = 0;
    }
    for(int i = BASE - 1 ; i >= 1 ; i--)
    {
        tree[i].mn = min(tree[2*i].mn , tree[2*i + 1].mn);
        tree[i].mx = max(tree[2*i].mx , tree[2*i + 1].mx);
    }
}
 
void propagate(int node)
{
    if(lazy[node].mn != 1e9)
    {
        for(int i = 2*node ; i <= 2*node + 1 ; i++)
        {
            lazy[i].mn = min(lazy[i].mn , lazy[node].mn);
            lazy[i].mx = min(lazy[i].mx , lazy[node].mn);
            tree[i].mn = min(tree[i].mn , lazy[node].mn);
            tree[i].mx = min(tree[i].mx , lazy[node].mn);
        }
        lazy[node].mn = 1e9;
    }
    if(lazy[node].mx != -1)
    {
        for(int i = 2 * node ; i <= 2*node + 1 ; i++)
        {
            lazy[i].mx = max(lazy[i].mx , lazy[node].mx);
            tree[i].mx = max(tree[i].mx , lazy[node].mx);
            lazy[i].mn = max(lazy[i].mn , lazy[node].mx);
            tree[i].mn = max(tree[i].mn , lazy[node].mx);
        }
        lazy[node].mx = -1;
    }
}
void minimize(int node , int s , int e , int l , int r , int val)
{
    int m = (s + e)/2;
    if(l <= s && e <= r)
    {
        if(tree[node].mx <= val)
            return ;
        if(tree[node].mn >= val)
        {
            tree[node].mx = val;
            lazy[node].mx = val;
            tree[node].mn = val;
            lazy[node].mn = val;
        }
        else
        {
            propagate(node);
            minimize(2*node , s , m , l , r , val);
            minimize(2*node + 1 , m + 1 , e , l , r , val);
            tree[node].mx = max(tree[2*node].mx , tree[2*node + 1].mx);
            tree[node].mn = min(tree[2*node].mn , tree[2*node+ 1].mn);
        }
        return ;
    }
    if(s > r || l > e)
        return ;
    propagate(node);
    minimize(2*node , s , m , l , r , val);
    minimize(2*node + 1 , m + 1 , e , l , r , val);
    tree[node].mx = max(tree[2*node].mx , tree[2*node + 1].mx);
    tree[node].mn = min(tree[2*node].mn , tree[2*node+ 1].mn);
}
void maximize(int node , int s , int e , int l , int r , int val)
{
    int m = (s + e)/2;
    if(l <= s && e <= r)
    {
        if(tree[node].mn >= val)
            return ;
        if(tree[node].mx <= val)
        {
            tree[node].mx = val;
            lazy[node].mx = val;
            tree[node].mn = val;
            lazy[node].mn = val;
        }
        else
        {
            propagate(node);
            maximize(2*node , s , m , l , r , val);
            maximize(2*node + 1 , m + 1 , e , l , r , val);
            tree[node].mx = max(tree[2*node].mx , tree[2*node + 1].mx);
            tree[node].mn = min(tree[2*node].mn , tree[2*node+ 1].mn);
        }
        return ;
    }
    if(s > r || l > e)
        return ;
    propagate(node);
    maximize(2*node , s , m , l , r , val);
    maximize(2*node + 1 , m + 1 , e , l , r , val);
    tree[node].mx = max(tree[2*node].mx , tree[2*node + 1].mx);
    tree[node].mn = min(tree[2*node].mn , tree[2*node+ 1].mn);
}
void maximize(int l , int r , int val)
{
    maximize(1 , 0 , BASE - 1 , l , r , val);
}
void minimize(int l , int r , int val)
{
    minimize(1 , 0 , BASE - 1 , l , r ,val);
}
int query(int node , int s , int e , int i)
{
    if(s == e)
    {
        return tree[node].mn;
    }
    int m = (s + e)/2;
    propagate(node);
    if(s <= i && i <= m)
    {
        return query(2*node , s , m , i);
    }
    else
        return query(2*node + 1, m + 1 , e , i);
}
int query(int i)
{
    return query(1 , 0 , BASE - 1 , i);
}
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[])
{
    BASE = n;
    build(n);
    for(int i = 0 ; i < k ; i++)
    {
        if(op[i] == 1)
        {
            maximize(left[i] , right[i] , height[i]);
        }
        else
        {
            minimize(left[i] , right[i] , height[i]);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        finalHeight[i] = query(i);
    }
}
