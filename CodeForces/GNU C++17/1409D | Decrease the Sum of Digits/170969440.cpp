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
        ll n;
        int m;
        cin>>n>>m;
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int len = s.size();
        vi suf(len);
        suf[0]=s[0]-'0';
        forr(i,1,len-1)
        {
            suf[i]=suf[i-1]+s[i]-'0';
        }
        int tot = suf[len-1];
        if(tot<=m)
        {
            cout<<0<<nl;
            continue;
        }
        ll ans;
        forr(i,0,len-1)
        {
            int cur = tot-suf[i]+1;
            if(cur<=m)
            {
                ans = (ll)pow(10,len)-n;
                if(i+1<len)
                {
                    ans = (s[i+1]-'0'+1)*(ll)pow(10,i+1)-n%(ll)pow(10,i+2);
                }
                break;
            }
        }
        cout<<ans<<nl;
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
 
 