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
#define vld vector<ld>
#define fi first
#define se second
//variables:

//functions:
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)


bool check(double t,vll &v)
{
    double MIN = 1e9+1,MAX = -1000000001;
    for(int i=0;i<v.size();i++)
    {
        MAX = max(MAX,v[i].fi-t*v[i].se);
        MIN = min(MIN,t*v[i].se+v[i].fi);
    }
    if(MAX<=MIN)
        return true;
    return false;
}

int main()
{
    boost;
    int n;cin>>n;
    vll v;
    vi xx(n),vv(n);
    for(int i=0;i<n;i++)
        cin>>xx[i];
    for(int i=0;i<n;i++)
    {
        cin>>vv[i];
        v.pb({xx[i],vv[i]});
    }
    double l = -1,r = 1e9+1;
    int c = 60;
    while(c--)
    {
        double mid = (l+r)/2.0;
        if(check(mid,v))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout<<setprecision(10)<<r<<fixed<<nl;
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


