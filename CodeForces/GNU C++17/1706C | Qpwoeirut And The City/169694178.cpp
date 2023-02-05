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
        forr(i,0,n-1)
        {
            cin>>v[i];
        }
        vl cost(n);
        ll ans = 0;
        forr(i,1,n-2)
        {
            ll d1 = v[i]-v[i+1];
            ll d2 = v[i]-v[i-1];
            if(d1>0)
            {
                d1 = 0;
            }
            else
            {
                d1 = abs(d1)+1;
            }
            if(d2>0)
            {
                d2 = 0;
            }
            else
            {
                d2 = abs(d2)+1;
            }
            cost[i]=max(d1,d2);
            if(i%2)
            {
                ans+=cost[i];
            }
        }
        ll best = ans;
        if(n%2==0)
        {
            for(int i = n-2;i>=1;i-=2)
            {
                ans+=cost[i];
                ans-=cost[i-1];
                best = min(best,ans);
            }
        }
        cout<<best<<nl;
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
 
 