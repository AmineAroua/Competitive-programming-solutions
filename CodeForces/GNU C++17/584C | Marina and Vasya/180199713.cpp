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
    int n,t;
    cin>>n>>t;
    string a,b;
    string ans(n,'.');
    cin>>a>>b;
    int x = n-t,y = n-t;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]&&x>0&&y>0)
        {
            ans[i] = a[i];
            x--;
            y--;
        }
    }
    if(x==0&&y==0)
    {
        for(int i=0;i<n;i++)
        {
            if(ans[i]=='.')
            {
                bool acc = 0;
                for(int j=0;j<25;j++)
                {
                    if(j+'a'!=a[i]&&j+'a'!=b[i])
                    {
                        ans[i] = j+'a';
                        acc = 1;
                        break;
                    }
                }
                if(!acc)
                {
                    cout<<-1<<nl;
                    return 0;
                }
            }
        }
        cout<<ans<<nl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(ans[i]!='.')
        {
            continue;
        }
        if(x>0)
        {
            x--;
            ans[i] = a[i];
        }
        else if(y>0)
        {
            y--;
            ans[i] = b[i];
        }
    }
    if(x>0||y>0)
    {
        cout<<-1<<nl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(ans[i]=='.')
        {
            bool acc = 0;
            for(int j=0;j<25;j++)
            {
                if(j+'a'!=a[i]&&j+'a'!=b[i])
                {
                    ans[i] = j+'a';
                    acc = 1;
                    break;
                }
            }
            if(!acc)
            {
                cout<<-1<<nl;
                return 0;
            }
        }
    }
    cout<<ans<<nl;
    return 0;
}
/*
4 3
ccbb
caab
 
*/