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
vi v,a;
void f(int t,int beg,int lst,bool cur)
{
    if(t==0)
    {
        int nb = 0;
        forr(k , beg,lst)
        {
            if(nb>=(lst-beg+1)/2)
            {
                bool b = !cur;
                int x = (int)b;
                a[k] = x;
                continue;
            }
            a[k] = (int)cur;
            nb++;
        }
    }
    else
    {
        forr(k , beg,lst)
        {
            a[k] = (int)cur;
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int n;
    cin>>n;
    v.assign(n,0);
    a.assign(n,0);
    fore(i , n)
    {
        cin>>v[i];
    }
    int i = 0;
    ll res = 0;
    vector<vi> ans;
    while(i<n)
    {
        if(i>=n)
        {
            break;
        }
        bool cur = 0;
        if(v[i]==0)
        {
            cur = 0;
        }
        else
        {
            cur = 1;
        }
        bool f = cur;
        int j = i;
        cur = !cur;
 
        i++;
        int ln = 1;
        while(i<n&&v[i]==(int)cur)
        {
            cur = !cur;
            ln++;
            i++;
        }
        i--;
        int t= 1;
        if(ln==2)
        {
            i=j;
        }
        if(ln%2==0&&ln!=2)
        {
            t = 0;
        }
        if(j<i)
        {
            ans.pb({j,i , f , t});
            res=max(res,(i-j)/2ll);
        }
        i++;
    }
    if(ans.empty())
    {
        cout<<0<<nl;
 
        for(auto x:v)cout<<x<<" ";
        cout<<nl;
        return 0;
    }
    for(int k = 0;k<ans[0][0];k++)
    {
        a[k] = v[k];
    }
    int ln = sz(ans);
    forr(h,0,ln-2)
    {
        int beg = ans[h][0] , lst = ans[h][1]  , t = ans[h][3];
        bool cur = ans[h][2];
        int _beg = ans[h+1][0] , _lst = ans[h+1][1], _t = ans[h+1][3];
        bool _cur = ans[h+1][2];
        f(t,beg,lst,cur);
        forr(k,lst+1, _beg-1)
        {
            a[k] = v[k];
        }
    }
    int _beg = ans[ans.size()-1][0] , _lst = ans[ans.size()-1][1], _t = ans[ans.size()-1][3];
    bool _cur = ans[ans.size()-1][2];
    f(_t,_beg,_lst,_cur);
    forr(k,ans[ans.size()-1][1]+1 , n-1)
    {
        a[k] = v[k];
    }
    cout<<res<<nl;
    for(auto x:a)cout<<x<<" ";
    cout<<nl;
}