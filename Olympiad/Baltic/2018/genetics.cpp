#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
 
using namespace std;
#define pb push_back
#define nl '\n'
#define fore(i, y) for(int i = 0; i < y; i++)
#define forr(i, x, y) for(int i = x;i<=y;i++)
#define forn(i, y, x) for(int i = y; i >= x; i--)
mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
vector<int> encode(char c)
{
    vector<int> v(3 , 0);
    if(c == 'A')
        v[0] = 1;
    else if(c == 'C')
        v[1] = 1;
    else if(c == 'G')
        v[2] = 1;
    else
    {
        v = vector<int>(3 , 1);
    }
    return v;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m , k;
    cin>>n>>m>>k;
    bitset<3 * 4100> bs[n];
    vector<int> cnt(n);
    vector<int> perm;
    fore(i , n) {
        string s;
        cin >> s;
        fore(j, m) {
            vector<int> code = encode(s[j]);
            forr(l , 3*j , 3*j + 2)
            {
                if(code[l - 3*j] == 1)
                    cnt[i]++;
                bs[i][l] = code[l - 3*j];
            }
        }
    }
    vector<vector<int>> f(n , vector<int>(n , -1));
    fore(i , n)
    {
        perm.clear();
        bool ac = 0;
        fore(j , n)
        {
            if(i == j)
                continue;
            if(abs(cnt[i] - cnt[j]) > 2 * k || cnt[i] + cnt[j] < 2 * k)
            {
                ac = 1;
                continue;
            }
            perm.pb(j);
        }
        if(ac)
            continue;
        shuffle(perm.begin() , perm.end() , rng);
        bool acc = 1;
        for(auto j : perm)
        {
            if(f[i][j] == -1 && f[j][i] == -1)
                f[i][j] = f[j][i] = (int)(bs[j]^bs[i]).count();
            if(f[i][j] != 2*k)
            {
                acc = 0;
                break;
            }
        }
        if(acc)
        {
            cout<<i + 1<<nl;
            return 0;
        }
    }
}
 
