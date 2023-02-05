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
    int t;
    cin>>t;
    while(t--)
    {
        int n , k;
        cin>>n>>k;
        if(n<=2&&k>0)
        {
            cout<<-1<<nl;
            continue;
        }
        vi v(n);
        for(int i = 0;i<n;i++)
        {
            v[i] = i+1;
        }
        for(int i = n-1;i>=2;i-=2)
        {
            if(k==0)break;
            swap(v[i] , v[i-1]);
            k--;
        }
        if(k>0)
        {
            cout<<-1;
        }
        else
        {
            for(auto x:v)
            {
                cout<<x<<" ";
            }
        }
        cout<<nl;
    }
}
 
 