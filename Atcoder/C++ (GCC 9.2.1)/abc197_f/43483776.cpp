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
const ll INF = 1e9 + 1;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return a * (b / gcd(a , b));} // least common multiple (PPCM)

// HERE IS THE SOLUTION

int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int k;
    cin>>k;
    vi dist(k , INF);
    int strt = 1;
    deque<int> dq;
    dq.push_back(strt);
    dist[strt] = 1;
    while(!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();
        if(dist[(cur + 1)%k] > dist[cur] + 1)
        {
            dist[(cur  + 1)%k] = dist[cur] + 1;
            dq.pb((cur  + 1)%k);
        }
        if(dist[(cur * 10)%k] > dist[cur])
        {
            dist[(cur*10)%k] = dist[cur];
            dq.push_front((cur*10)%k);
        }
    }
    cout<<dist[0]<<nl;

}

