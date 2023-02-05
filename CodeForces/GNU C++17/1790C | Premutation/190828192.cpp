#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
        int grid[n][n];
        fore(i,n)
        {
            fore(j,n-1)
            {
                cin>>grid[i][j];
            }
        }
        vi occ(n+1 , 0);
        vector<bool> used(n+1 , 0);
        int mx = 0;
        fore(i,n)
        {
            occ[grid[i][n-2]]++;
            mx = max(mx , occ[grid[i][n-2]]);
        }
        vi ans;
        int tmp = -1;
        int kmp = -1;
        forr(i,1,n)
        {
            if(occ[i]==mx)
            {
                tmp = i;
                used[i] = 1;
            }
            if(occ[i]>0&&occ[i]!=mx)
            {
                kmp = i;
                used[i] = 1;
            }
        }
        ans.pb(tmp) , ans.pb(kmp);
        forn(i , n-3 , 0)
        {
            fore(j , n)
            {
                if(!used[grid[j][i]])
                {
                    ans.pb(grid[j][i]);
                    used[grid[j][i]] = 1;
                    break;
                }
            }
        }
        reverse(all(ans));
        for(auto x:ans)cout<<x<<" ";
        cout<<nl;
    }
}
 