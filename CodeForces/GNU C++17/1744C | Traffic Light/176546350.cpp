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
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        vi pos,red,yel;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='g')
            {
                pos.pb(i);
            }
            if(s[i]=='r')
            {
                red.pb(i);
            }
            if(s[i]=='y')
            {
                yel.pb(i);
            }
        }
        if(c=='g')
        {
            cout<<0<<nl;
            continue;
        }
        if(c=='r')
        {
            int ans = 0;
            for(auto x:red)
            {
                int lb = pos[0];
                int ub = upper_bound(pos.begin(),pos.end(),x)-pos.begin();
                if(lb<x&&upper_bound(pos.begin(),pos.end(),x)!=pos.end())
                {
                    ans = max(ans,min(n-x+lb,pos[ub]-x));
                    continue;
                }
                if(lb<x)
                {
                    ans = max(ans,n-x+lb);
                }
                if(upper_bound(pos.begin(),pos.end(),x)!=pos.end())
                {
                    ans = max(ans,pos[ub]-x);
                }
            }
            cout<<ans<<nl;
        }
        else
        {
            int ans = 0;
            for(auto x:yel)
            {
                int lb = pos[0];
                int ub = upper_bound(pos.begin(),pos.end(),x)-pos.begin();
                if(lb<x&&upper_bound(pos.begin(),pos.end(),x)!=pos.end())
                {
                    ans = max(ans,min(n-x+lb,pos[ub]-x));
                    continue;
                }
                if(lb<x)
                {
                    ans = max(ans,n-x+lb);
                }
                if(upper_bound(pos.begin(),pos.end(),x)!=pos.end())
                {
                    ans = max(ans,pos[ub]-x);
                }
            }
            cout<<ans<<nl;
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
 
 