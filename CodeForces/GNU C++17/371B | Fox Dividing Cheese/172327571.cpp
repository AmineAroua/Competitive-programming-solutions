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
 
vi prf(int x)
{
    vi res;
    while(x%2==0)
    {
        res.pb(2);
        x/=2;
    }
    for(int i=3;i*i<=x;i+=2)
    {
        while(x%i==0)
        {
            res.pb(i);
            x/=i;
        }
    }
    if(x>2)
    {
        res.pb(x);
    }
    return res;
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int a,b;
    cin>>a>>b;
    int d = gcd(a,b);
    vi pra = prf(a/d);
    vi prb = prf(b/d);
    for(auto x:pra)
    {
        if(x!=5&&x!=2&&x!=3)
        {
            cout<<-1<<nl;
            return 0;
        }
    }
    for(auto x:prb)
    {
        if(x!=5&&x!=2&&x!=3)
        {
            cout<<-1<<nl;
            return 0;
        }
    }
    cout<<pra.size()+prb.size()<<nl;
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
 
 