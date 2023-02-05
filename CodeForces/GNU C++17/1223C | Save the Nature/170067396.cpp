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
 
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 1;
 
//variables:
 
 
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
bool check(ll mid,ll a,ll b,ll x,ll y,vl prix,ll k)
{
    map<ll,int> mult;
    ll cost=0;
    ll nbA = mid/a,nbB = mid/b;
    if(y>x)
    {
        swap(x,y);
        swap(a,b);
        swap(nbA,nbB);
    }
    for(int i=1;i<=nbA;i++)
    {
        mult[a*i]++;
    }
    for(int i=1;i<=nbB;i++)
    {
        mult[b*i]++;
    }
    ll c = 0;
    for(auto m:mult)
    {
        if(m.se>=2)
        {
            c++;
        }
    }
    for(int i=0;i<nbA;i++)
    {
        cost+=(prix[i]/100)*x;
    }
    for(int i=0;i<c;i++)
    {
        cost+=(prix[i]/100)*y;
    }
    for(int i=nbA;i<nbB+nbA-c;i++)
    {
        cost+=(prix[i]/100)*y;
    }
    return cost>=k;
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
        int n;
        cin>>n;
        vl prix(n);
        forr(i,0,n-1)
        {
            cin>>prix[i];
        }
        ll x,a,y,b;
        cin>>x>>a>>y>>b;
        ll k;
        cin>>k;
        ll l = 0,r = n+1;
        sort(prix.begin(),prix.end(),greater<ll>());
        while(l+1<r)
        {
            ll mid = (l+r)/2;
            if(check(mid,a,b,x,y,prix,k))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        if(r!=n+1)
        {
            cout<<r<<nl;
        }
        else
            cout<<-1<<nl;
    }
}
 
 
 
 
/*
 
1/2 half of the contest:
 Read the subject in ~2 min
 Reformulate the topic
 solve examples
 Think of the solution 3 min
 Implement the solution for 20 min
 Pseudo-code your algorithm
 Verify your solution
 Code your solution
 Test your solution
 Debug your code
2/2 half of the contest:
 find the easiest subtasks and try to solve them or give up
 if there are many subtasks, the problem is easy
 if the first subtask is difficult with no much points, the problem is difficult
----------------------------
!(: remember, you are the king of competitive programming
*/
 
 