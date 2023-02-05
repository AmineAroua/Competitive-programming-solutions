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
int n;
vector<string> words(100000);
vi c(100000);
vll reversed(100000,{-1,-1});
 
//functions:
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
 
bool isgreater(string s , string t)
{
    int n = min(s.size(),t.size());
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i])
        {
            continue;
        }
        if(s[i]>t[i])
        {
            return true;
        }
        return false;
    }
    return s.size()>t.size();
}
 
ll backtrack(string old,int i,ll cur)
{
    if(i==n)
    {
        return cur;
    }
    string s = words[i];
    string t = s;
    reverse(t.begin(),t.end());
    ll a=INF,b=INF;
    if(!isgreater(old,s))
    {
        if(reversed[i].fi!=-1)
        {
            a= cur+reversed[i].fi;
            a = min(a,INF);
        }
        else
        {
            ll x = backtrack(s,i+1,0);
            a=cur+x;
            a= min(INF,a);
            reversed[i].fi = x;
        }
    }
    if(!isgreater(old,t))
    {
        if(reversed[i].se!=-1)
        {
            b = c[i]+cur+reversed[i].se;
            b = min(INF,b);
        }
        else
        {
            ll y = backtrack(t,i+1,0);
            b=cur+c[i]+y;
            b = min(INF,b);
            reversed[i].se = y;
        }
    }
    if(isgreater(old,s)&&isgreater(old,t))
    {
        return INF;
    }
    return min(a,b);
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>words[i];
    }
    ll a = backtrack(words[0],1,0);
    string x= words[0];
    reverse(x.begin(),x.end());
    ll b = c[0]+backtrack(x,1,0);
    ll mn = min(a,b);
    if(mn==INF){cout<<-1<<nl;return 0;}
    else
    {
        cout<<mn<<nl;
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
 
 