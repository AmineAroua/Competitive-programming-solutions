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
        string s,t;
        cin>>s>>t;
        int bs=0,bt = 0;
        vector<pair<char,int>> ss,tt;
        for(auto c:s)
        {
            bs+=c=='b';
        }
        for(auto c:t)
        {
            bt+=c=='b';
        }
        if(bt!=bs)
        {
            cout<<"NO"<<nl;
            continue;
        }
        forr(i,0,n-1)
        {
            if(s[i]!='b')
                ss.pb(mp(s[i],i));
            if(t[i]!='b')
                tt.pb(mp(t[i],i));
        }
        if(ss.empty()||tt.empty())
        {
            if(bs==bt)
            {
                cout<<"YES"<<nl;
                continue;
            }
            else
            {
                cout<<"NO"<<nl;
                continue;
            }
        }
        if(ss.size()!=tt.size())
        {
            cout<<"NO"<<nl;
            continue;
        }
        bool acc = true;
        forr(i,0,ss.size()-1)
        {
            if(ss[i].fi!=tt[i].fi)
            {
                cout<<"NO"<<nl;
                acc = false;
                break;
            }
            if(ss[i].fi=='a')
            {
                if(ss[i].se>tt[i].se)
                {
                    cout<<"NO"<<nl;
                    acc = false;
                    break;
                }
            }
            if(ss[i].fi=='c')
            {
                if(ss[i].se<tt[i].se)
                {
                    cout<<"NO"<<nl;
                    acc = false;
                    break;
                }
            }
        }
        if(acc)
        {
            cout<<"YES"<<nl;
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
 
 