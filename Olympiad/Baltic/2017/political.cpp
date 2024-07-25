#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
#define pb push_back
#define nl '\n'
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i, x, y) for(int i = x;i<=y;i++)
#define forn(i, y, x) for(int i = y; i >= x; i--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 50000;
vector<bitset<N>> adj(N , 0);
int n , k;
bitset<N> cur = 0;
//bool done[N];
int maxClique(int i)
{
    cur = adj[i];
    int last = i;
    int cnt = 0;
    while(true)
    {
        cnt++;
        cur&=adj[last];
        vector<int> candidates;
        for(int j = cur._Find_first() ; (int)candidates.size() < 10 && j < N ; j = cur._Find_next(j))
        {
            candidates.pb(j);
        }
        if(candidates.empty())
            break;
        last = candidates[uniform_int_distribution<int>(0 , (int)candidates.size() - 1)(rng)];
    }
    return cnt;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>k;
 
    fore(i , n)
    {
        int d;
        cin>>d;
        fore(j , d)
        {
            int x;
            cin>>x;
            if(x != i)
                adj[i][x] = 1;
        }
    }
    int best = 0;
    vector<int> p(n);
    fore(i , n)
        p[i] = i;
    fore(i , 5 * n)
    {
        if(i % n == 0)
        {
            shuffle(p.begin() , p.end() , rng);
        }
        best = max(best , maxClique(p[i%n]));
    }
    cout<<best<<nl;
}
