#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
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
#define fore(i, y) for(ll i = 0; i < y; i++)
#define forr(i,x,y) for(int i = x;i<=y;i++)
#define forn(i,y,x) for(ll i = y; i >= x; i--)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define ub upper_bound
#define lb lower_bound
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
// HERE IS THE SOLUTION
int n,m;
int grid[1001][1001];
ll memo[1001][1001] , momo[1001][1001];
ll mnpth(int i , int j, ll cur)
{
    if(i<0||i>=n||j<0||j>=m)
    {
        return INF;
    }
    if(momo[i][j]!=INF)
    {
        return momo[i][j];
    }
    cur+=grid[i][j];
    if(i==n-1&&j==m-1)
    {
        return cur;
    }
    ll a = mnpth(i+1 , j, 0);
    ll b = mnpth(i , j+1 , 0);
    momo[i][j] = min(a,b) + cur;
    return momo[i][j];
}
ll backtrack(int i , int j, ll cur)
{
    if(i<0||i>=n||j<0||j>=m)
    {
        return INF;
    }
    if(memo[i][j]!=INF)
    {
        return memo[i][j];
    }
    cur+=grid[i][j];
    if(i==n-1&&j==m-1)
    {
        return cur;
    }
    ll a = backtrack(i+1 , j, 0);
    ll b = backtrack(i , j+1 , 0);
    if(a!=INF && b!=INF)
        memo[i][j] = max(a,b);
    else if(a!=INF)
    {
        memo[i][j] = a;
    }
    else
    {
        memo[i][j] = b;
    }
    memo[i][j]+=cur;
    return memo[i][j];
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
        fore(i , n)
        {
            fore(j , m)
            {
                cin>>grid[i][j];
                memo[i][j] = INF;
                momo[i][j] = INF;
            }
        }
        if((n+m-1)%2==1)
        {
            cout<<"NO"<<nl;
            continue;
        }
        memo[n-1][m-1] = grid[n-1][m-1];
        momo[n-1][m-1] = grid[n-1][m-1];
        ll mx = backtrack(0 , 0 , 0);
        ll mn = mnpth(0 , 0 , 0);
        if(mn<=0&&0<=mx)
        {
            cout<<"YES"<<nl;
        }
        else
        {
            cout<<"NO"<<nl;
        }
    }
}
 