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
const int N = 2*(1e5);
//variables:
vector<vi> tree(N);
vl bb(N),aa(N),ans(N,0);
vl curB;
ll sumB = 0,sumA = 0;
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
void dfs(int x,int s)
{
    if(x)
    {
        sumB+=bb[x];
        sumA+=aa[x];
        curB.pb(sumB);
        ans[x]=upper_bound(curB.begin(),curB.end(),sumA)-curB.begin();
    }
    for(auto u:tree[x])
    {
        if(u==s)
            continue;
        dfs(u,x);
    }
    if(x)
    {
        sumB-=bb[x];
        sumA-=aa[x];
        curB.pop_back();
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
        int n;
        cin>>n;
        ans.assign(n,0);
        tree.clear();
        tree.assign(n,{});
        forr(i,1,n-1)
        {
            int v;
            ll a,b;
            cin>>v>>a>>b;
            v--;
            tree[i].pb(v);
            tree[v].pb(i);
            aa[i]=a;
            bb[i]=b;
        }
        dfs(0,0);
        forr(i,1,n-1)
        {
            cout<<ans[i]<<" ";
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
 
 