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
const int P = 31627;
bool pr[P+1];
vl primes;
void sieve()
{
    for(int i = 2;i<=P;i++)
    {
        if(pr[i])
        {
            for(int j = i*2;j<=P;j+=i)
            {
                pr[j] = 0;
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    //freopen("in.txt" , "r" , stdin);
    clr(pr , 1);
    sieve();
    for(int i = 2;i<=P;i++)
    {
        if(pr[i])
        {
            primes.pb(i);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vl v(n);
        ll mx = 0;
        fore(i , n)
        {
            cin>>v[i];
            mx = max(mx , v[i]);
        }
        bool acc = 0;
        map<ll,bool> occ;
        for(int i = 0;i<n;i++)
        {
            for(auto x:primes)
            {
                if(x*x>v[i])
                {
                    break;
                }
                if(v[i]%x==0)
                {
                    if(occ[x])
                    {
                        acc = 1;
                        break;
                    }
                    occ[x] = 1;
                }
                while(v[i]%x==0)
                {
                    v[i]/=x;
                }
            }
            if(v[i]!=1)
            {
                if(occ[v[i]])
                {
                    acc = 1;
                    break;
                }
                occ[v[i]]=1;
                v[i] = 1;
            }
            if(acc)
            {
                break;
            }
        }
        if(!acc)
        {
            cout<<"no"<<nl;
        }
        else
        {
            cout<<"yes"<<nl;
        }
    }
}
 