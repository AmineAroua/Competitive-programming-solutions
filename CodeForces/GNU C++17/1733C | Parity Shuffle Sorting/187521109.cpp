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
#define forn(i, x) for(ll i = x-1; i >= 0; i--)
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
        vi v(n);
        bool acc = 1;
        int mx = -1 , tmp = -1;
        fore(i,n)
        {
            cin>>v[i];
        }
        if(n==1)
        {
            cout<<0<<nl;
            continue;
        }
        cout<<n-1<<nl;
        cout<<1<<" "<<n<<nl;
        for(int i = 2;i<n;i++)
        {
            if((v[i-1]+v[0])%2==1)
            {
                cout<<1<<" "<<i<<nl;
            }
            else
            {
                cout<<i<<" "<<n<<nl;
            }
        }
    }
}
 