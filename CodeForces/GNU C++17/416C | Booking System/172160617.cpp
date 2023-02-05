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
#define all(v) v.begin(),v.end()
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
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[i][0]=b;
        v[i][1]=a;
        v[i][2]=i+1;
    }
    sort(all(v));
    int k;
    cin>>k;
    map<int,stack<int>> tab;
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        tab[a].push(i+1);
    }
    vii ans;
    int res = 0;
    forn(i,n-1,0)
    {
        int prx = v[i][0];
        int nb = v[i][1];
        int idx = v[i][2];
        auto lb = tab.lower_bound(nb);
        if(lb==tab.end())
        {
            continue;
        }
        ans.pb(mp(idx,lb->se.top()));
        lb->se.pop();
        if(lb->se.empty())
        {
            tab.erase(lb);
        }
        res+=prx;
    }
    cout<<ans.size()<<" "<<res<<nl;
    for(auto p:ans)
    {
        cout<<p.fi<<" "<<p.se<<nl;
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
 
 