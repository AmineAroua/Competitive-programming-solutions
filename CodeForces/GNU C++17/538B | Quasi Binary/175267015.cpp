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
 
bool ok(int x)
{
    string s = to_string(x);
    for(auto c:s)
    {
        if(c!='1'&&c!='0')
        {
            return false;
        }
    }
    return true;
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int n;
    cin>>n;
    int m = n;
    vi rep;
    int co = 0;
    while(m)
    {
        for(int i=0;i<m%10;i++)
        {
            rep.pb(pow(10,co));
        }
        co++;
        m/=10;
    }
    reverse(rep.begin(),rep.end());
    for(int i=0;i<rep.size();i++)
    {
        for(int j=i+1;j<rep.size();j++)
        {
            if(ok(rep[i]+rep[j]))
            {
                rep[i]+=rep[j];
                rep.erase(rep.begin()+j);
                j--;
            }
        }
    }
    cout<<rep.size()<<nl;
    for(auto x:rep)
    {
        cout<<x<<" ";
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
 
 