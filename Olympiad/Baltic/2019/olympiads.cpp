#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
#define pb push_back
#define nl '\n'
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i, x, y) for(int i = x;i<=y;i++)
#define forn(i, y, x) for(int i = y; i >= x; i--)
int n , k , c;
vector<vector<int>> events;
void sort(vector<int> &v)
{
    fore(i , k)
    {
        forr(j , i + 1 , (int)v.size() - 1)
        {
            if(events[v[j]][i] > events[v[i]][i])
                swap(v[i] , v[j]);
        }
    }
}
int val(vector<int> &v)
{
    int cur = 0;
    fore(j , k)
    {
        int mx = 0;
        fore(i , k)
        {
            mx = max(mx , events[v[i]][j]);
        }
        cur+=mx;
    }
    return cur;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>c;
    vector<int> cur;
    events.assign(n , vector<int>(k));
    priority_queue<tuple<int , int , vector<int>>> pq;
    fore(i , n)
    {
        cur.pb(i);
        fore(j , k)
        {
            cin>>events[i][j];
        }
    }
    sort(cur);
    pq.push({val(cur), 0 , cur});
    while(c--)
    {
        auto [score , p , vec] = pq.top();
        if(c == 0)
        {
            cout<<score<<nl;
            return 0;
        }
        pq.pop();
        if((int)vec.size() == k)
            continue;
        forr(i , p , k - 1)
        {
            vector<int> nxt = vec;
            nxt.erase(nxt.begin() + i);
            sort(nxt);
            pq.push({val(nxt) , i , nxt});
        }
    }
}
