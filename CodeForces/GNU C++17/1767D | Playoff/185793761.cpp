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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l = 1 , r= (int)(pow(2,n));
    int one=1, zer=1;
    bool a1 = 1 , a2 = 1;
    for(auto c:s)
    {
        if(c=='0'&&a1)
        {
            a1 = 0;
            r--;
            zer*=2;
            continue;
        }
        if(c=='1'&&a2)
        {
            a2 = 0;
            l++;
            one*=2;
            continue;
        }
        if(c=='0')
        {
            r-=zer;
            zer*=2;
        }
        if(c=='1')
        {
            l+=one;
            one*=2;
        }
    }
    for(int i = l;i<=r;i++)cout<<i<<" ";
    cout<<nl;
}
 
 
 