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
 
const ll MOD = 1e9 + 7;
 
//variables:
 
 
//functions:
 
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
bool check(ll n,ll mid,vl taches)
{
    ll imposs = 0,addT=0;
    for(int i=0;i<n;i++)
    {
 
            imposs+=taches[i]-min(taches[i],mid);
            addT += (mid-min(mid,taches[i]))/2;
 
    }
    if(addT-imposs>=0)return true;
    return false;
}
 
int main()
{
    boost;
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll m;cin>>m;
        vl v(m);
        vl taches(n,0);
        for(int i=0;i<m;i++)
        {
            cin>>v[i];
            taches[v[i]-1]++;
        }
        ll l=-1,r=1e9+1;
        while(l+1<r)
        {
            ll mid = l+(r-l)/2;
            if(check(n,mid,taches))
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        cout<<r<<nl;
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
 
 