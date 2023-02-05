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
 
bool sorted(vi v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]>v[i+1])
            return false;
    }
    return true;
}
int main()
{
    boost;
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vi v(n);
        map<int,int> ss;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]==v[i-1]&&i>0)
                continue;
            ss[v[i]]++;
        }
        if(sorted(v))
        {
            cout<<0;
        }
        else
        {
            int i=n-1,co=1;
            while(i>0)
            {
                if(v[i]>v[i-1]&&ss[v[i]]==1&&ss[v[i-1]]==1)
                {
                    co++;
                }
                else if(v[i]==v[i-1]&&ss[v[i]]==1&&ss[v[i-1]]==1)
                {
                    while(v[i]==v[i-1]&&i>0)
                        i--;
                    i++;
                }
                else
                {
                    break;
                }
                i--;
            }
            if(co>1)
                cout<<ss.size()-co;
            else
            {
                if(ss[v[n-1]]==1)
                    cout<<ss.size()-1;
                else
                    cout<<ss.size();
            }
        }
        cout<<nl;
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
 
 