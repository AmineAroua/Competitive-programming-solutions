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
bool check(ll a, ll b , ll c)
{
    if(a>=0&&b>=0&&c>=0)
    {
        return true;
    }
    return false;
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
        ll n , k , a , b;
        cin>>n>>k>>a>>b;
        if(n%3!=0){cout<<"no"<<nl;continue;}
        if((a-b+k)%3 == 0)
        {
            ll y = (a-b+k)/3;
            ll x = y-a , z = b+y;
            if(x<=y&&y<=z&&z<=n/3&&x>=0)
            {
                cout<<"yes"<<nl;
                continue;
            }
        }
        if((b-a+k)%3 == 0)
        {
            ll y = (b-a+k)/3;
            ll x = y+a , z = y-b;
            if(n/3>=x&&x>=y&&y>=z&&z>=0)
            {
                cout<<"yes"<<nl;
                continue;
            }
        }
        if((a+b+k)%3==0)
        {
            ll y = (a+b+k)/3;
            ll x = y-a , z = y - b;
            if(n/3>=y&&y>=x&&y>=z&&z>=0&&x>=0)
            {
                cout<<"yes"<<nl;
                continue;
            }
        }
        if((k-a-b)%3 == 0)
        {
            ll y = (k-a-b)/3;
            ll x = y+a , z = y+b;
            if(y<=x&&y<=z&&max(z,x)<=n/3&&y>=0)
            {
                cout<<"yes"<<nl;
                continue;
            }
        }
        cout<<"no"<<nl;
    }
}
 
 