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
#define fore(i, y) for(ll i = 0; i < y; i++)
#define forr(i,x,y) for(int i = x;i<=y;i++)
#define forn(i,y,x) for(ll i = y; i >= x; i--)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define clr(v,k) memset(v,k,sizeof(v))
#define rall(v) v.rbegin() , v.rend()
#define pii pair<int,int>
#define pll pair<ll , ll>

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (PPCM)

// HERE IS THE SOLUTION
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    string s;
    cin>>s;
    int n = sz(s);
    vi nb((1<<10) , 0);
    nb[0]++;
    ll ans = 0;
    vector<vi> occ(n , vi(10 , 0));
    fore(i , n )
    {
        occ[i][s[i] - '0']++;
        if(i)
        {
            fore(j , 10)
            {
                (occ[i][j] += occ[i - 1][j])%=2;
            }
        }
        int mask = 0;
        fore(j , 10)
        {
            mask|=((1<<j) * (occ[i][j]%2));
        }
        ans+=nb[mask];
        nb[mask]++;
    }
    cout<<ans<<nl;
}

