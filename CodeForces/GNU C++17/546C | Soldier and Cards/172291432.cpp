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
    int n;
    cin>>n;
    int nb1,nb2;
    deque<int> p1,p2;
    cin>>nb1;
    for(int i=0;i<nb1;i++)
    {
        int a;
        cin>>a;
        p1.pb(a);
    }
    cin>>nb2;
    for(int i=0;i<nb2;i++)
    {
        int a;
        cin>>a;
        p2.pb(a);
    }
    bool acc= 1;
    if(n%2==0)
        acc = 0;
    int op = 0;
    while(!p1.empty()&&!p2.empty())
    {
        if(op>=1e6)
        {
            cout<<-1<<nl;
            return 0;
        }
        op++;
        int a = p1.front();
        int b = p2.front();
        if(a>b)
        {
            p2.pop_front();
            p1.pop_front();
            p1.pb(b);
            p1.pb(a);
        }
        else
        {
            p1.pop_front();
            p2.pop_front();
            p2.pb(a);
            p2.pb(b);
        }
    }
    cout<<op<<" ";
    if(!p1.empty())
    {
        cout<<1<<nl;
    }
    else
    {
        cout<<2<<nl;
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
 
 