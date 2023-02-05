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
 
 
int main()
{
    boost;
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        int m;cin>>m;
        vl v(m);
        vl diff;
        for(int i=0;i<m;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        bool acc = true;
        if(m==1)
        {
            cout<<2<<nl;
            acc = false;
        }
        if(acc)
        {
            for(int i=0;i<m-1;i++)
            {
                diff.pb(abs(v[i]-v[i+1])-1);
            }
            ll pbb = v[0]-1+n-v[m-1];
            if(pbb>0)
            diff.pb(pbb);
            sort(diff.begin(),diff.end(),greater<int>());
 
            ll ans = 0,days = 0;
            for(int i=0;i<diff.size();i++)
            {
                ll houses = diff[i];
                ll res = houses-2*days;
                if(res>0&&res<=2)
                {
                    ans++;
                    days++;
                }
                else if(res>2)
                {
                    days+=2;
                    ans+=res-1;
                }
            }
            cout<<n-ans<<nl;
        }
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
 
 