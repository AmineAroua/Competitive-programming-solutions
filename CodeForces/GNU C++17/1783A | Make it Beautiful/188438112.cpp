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
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vl v(n);
        fore(i,n)
        {
            cin>>v[i];
        }
        if(n==1)
        {
            cout<<"yes"<<nl;
            cout<<v[0]<<nl;
            continue;
        }
        if(n==2&&v[0]==v[1])
        {
            cout<<"no"<<nl;
            continue;
        }
        sort(v.rbegin(),v.rend());
        bool acc = 0;
        fore(i,n)
        {
            if(v[i]!=v[0])
            {
                acc = 1;
            }
        }
        if(!acc)
        {
            cout<<"no"<<nl;
            continue;
        }
        if(v[0]==v[1])
        {
            swap(v[1] , v[n-1]);
        }
        cout<<"yes"<<nl;
        for(auto x:v)cout<<x<<" ";
        cout<<nl;
    }
}
 