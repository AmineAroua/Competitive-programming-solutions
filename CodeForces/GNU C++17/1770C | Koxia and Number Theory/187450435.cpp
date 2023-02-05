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
 
void sieve(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    sieve(1e5);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vl v(n);
        map<ll,ll> nb;
        bool acc = 1;
        for(int i = 0;i<n;i++)
        {
            cin>>v[i];
            nb[v[i]]++;
            if(nb[v[i]]==2)
            {
                acc = 0;
            }
        }
        if(!acc)
        {
            cout<<"no"<<nl;
            continue;
        }
        for(int p = 2;p<=(n+1)/2;p++)
        {
            vl a = v;
            vi occ(p , 0);
            for(int i = 0;i<n;i++)
            {
                a[i]%=p;
                occ[a[i]]++;
            }
            int mn = 1e8;
            for(int i = 0;i<p;i++)
            {
                mn = min(mn , occ[i]);
            }
            if(mn>=2)
            {
                acc = 0;
                break;
            }
        }
        if(acc)
        {
            cout<<"yes"<<nl;
        }
        else
        {
            cout<<"no"<<nl;
        }
    }
}
 
 
// 1 2 5 7