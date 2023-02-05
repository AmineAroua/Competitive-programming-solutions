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
vl arr;
set<ll> s;
bool check()
{
    int n = arr.size();
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            for(int k = 0;k<n;k++)
            {
                if(i==k||j==k)
                {
                    continue;
                }
                if(!s.count(arr[i]+arr[j]+arr[k]))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    while(t--)
    {
        s.clear();
        arr.clear();
        ll n;cin>>n;
        vl v(n);
        int neg = 0 , pos = 0;
        for(int i = 0;i<n;i++)
        {
            cin>>v[i];
            pos+=v[i]>0;
            neg+=v[i]<0;
        }
        if(pos>2||neg>2)
        {
            cout<<"no"<<nl;
            continue;
        }
        int zero = 0;
        int j = 0;
        for(int i = 0;i<n;i++)
        {
            zero+=v[i]==0;
        }
        zero = min(zero , 2);
        for(int i = 0;i<zero;i++)
        {
            arr.pb(0);
            s.insert(0);
        }
        for(int i = 0;i<n;i++)
        {
            if(v[i])
            {
                arr.pb(v[i]);
                s.insert(v[i]);
            }
        }
        if(check())
        {
            cout<<"yes"<<nl;
        }
        else
        {
            cout<<"no"<<nl;
        }
    }
}
 
 