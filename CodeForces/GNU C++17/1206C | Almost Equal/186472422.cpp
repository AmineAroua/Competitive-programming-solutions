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
    int t = 1;
    while(t--)
    {
        int n;
        cin>>n;
        vi ans(n*2+1);
        if(n%2==0)
        {
            cout<<"NO"<<nl;continue;
        }
        ll s = ((2*n)*(2*n+1))/2;
        ll a = s/2 , b = s/2+1;
        for(int i = 1;i<=n;i++)
        {
            if(i%2==0)
            {
                ans[i] = 2*i;
            }
            else
            {
                ans[i] = 2*i-1;
            }
        }
        for(int i = n+1;i<=2*n;i++)
        {
            if(i%2==0)
            {
                ans[i] = ans[i-n] + 1;
            }
            else
            {
                ans[i] = ans[i-n] - 1;
            }
        }
        cout<<"YES"<<nl;
        for(int i = 1;i<=2*n;i++)
        {
            int x = ans[i];
            cout<<x<<" ";
        }
        cout<<nl;
    }
}
 
 