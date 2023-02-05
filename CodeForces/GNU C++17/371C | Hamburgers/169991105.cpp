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
ll nbB,nbS,nbC,pB,pS,pC;
ll m;
ll B=0,S=0,C=0;
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
bool check(ll mid)
{
    ll c1 = (mid*B-nbB)*pB;
    ll c2 = (mid*S-nbS)*pS;
    ll c3 = (mid*C-nbC)*pC;
    c1 = max(c1,0ll);
    c2 = max(c2,0ll);
    c3 = max(c3,0ll);
    ll res = c1+c2+c3;
    return res<=m;
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    string s;
    cin>>s;
    cin>>nbB>>nbS>>nbC>>pB>>pS>>pC;
    cin>>m;
    for(auto c:s)
    {
        B+=c=='B';
        C+=c=='C';
        S+=c=='S';
    }
    ll l = 0,r = 1e14+1;
    while(l+1<r)
    {
        ll mid = (l+r)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r = mid;
        }
    }
    cout<<l<<nl;
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
 
 