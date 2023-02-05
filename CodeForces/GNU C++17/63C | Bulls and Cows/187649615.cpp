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
vs nb;
void gen()
{
    for(int a = 0;a<=9;a++)
    {
        for(int b = 0;b<=9;b++)
        {
            if(a==b)
            {
                continue;
            }
            for(int c = 0;c<=9;c++)
            {
                if(c==b||c==a)
                {
                    continue;
                }
                for(int d = 0;d<=9;d++)
                {
                    if(d==c||d==a||d==b)
                    {
                        continue;
                    }
                    string cur = "";
                    cur+=(char)(a+48);
                    cur+=(char)(b+48);
                    cur+=char(c+48);
                    cur+=(char)(d+48);
                    nb.pb(cur);
                }
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    gen();
    vector<pair<string , pair<int,int>>> data;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        string s;
        int x,y;
        cin>>s>>x>>y;
        data.pb(mp(s,mp(x,y)));
    }
    string ans ;
    int check = 0;
    for(auto s:nb)
    {
        bool acc = 1;
        for(int i = 0;i<n;i++)
        {
            string t = data[i].fi;
            int x = data[i].se.fi , y = data[i].se.se;
            int _x = 0 , _y = 0;
            vector<bool> vis(4 , 0);
            for(int j = 0;j<4;j++)
            {
                if(t[j]==s[j])
                {
                    _x++;
                    continue;
                }
                for(int k = 0;k<4;k++)
                {
                    if(vis[k])continue;
                    if(s[k]==t[j])
                    {
                        _y++;
                        vis[k] = 1;
                        break;
                    }
                }
            }
            if(_x!=x||_y!=y)
            {
                acc = 0;
            }
        }
        if(acc)
        {
            check++;
            ans = s;
        }
    }
    if(check==1)
    {
        cout<<ans<<nl;
    }
    else if(check>1)
    {
        cout<<"Need more data"<<nl;
    }
    else
    {
        cout<<"Incorrect data"<<nl;
    }
}
 