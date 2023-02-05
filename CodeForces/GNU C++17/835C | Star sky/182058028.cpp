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
#define all(v) (v.begin(),v.end())
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
 
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
    ll n,q,c;
    cin>>n>>q>>c;
    vector<vl> star;
    for(int i=0;i<n;i++)
    {
        ll x,y,s;
        cin>>x>>y>>s;
        star.pb({x,y,s});
    }
    vl v(101,0);
    vector<vl> vv(101,v);
    vector<vector<vl>> coor(11,vv);
    for(int i =0; i< n;i++)
    {
        ll x,y,s;
        x = star[i][0] , y = star[i][1] , s = star[i][2];
        for(int t = 0;t<=c;t++)
        {
            coor[t][x][y] += s;
            s++;
            s%= (c+1);
        }
    }
    for(int t = 0;t<=c;t++)
    {
        for(int i = 1;i<101;i++)
        {
            for(int j = 1;j<101;j++)
            {
                coor[t][i][j]+= coor[t][i-1][j] + coor[t][i][j-1] - coor[t][i-1][j-1];
            }
        }
    }
    while(q--)
    {
        ll t,x1,x2,y1,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        t%= (c+1);
        cout<<coor[t][x2][y2] - coor[t][x1-1][y2] - coor[t][x2][y1-1] + coor[t][x1-1][y1-1]<<nl;
    }
}
 
 