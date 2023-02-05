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
 
vi pfac(int n)
{
    vector<int> ans;
    int x= 0;
    while(n%2==0)
    {
        n/=2;
        x++;
    }
    if(x>=2)
    {
        ans.pb(4);
    }
    for(int i=3;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            ans.pb(i);
        }
    }
    if(n>1)
    {
        ans.pb(n);
    }
    return ans;
}
 
int main()
{
    cin.tie(0);
    cout.tie(0);
    boost;
    int n;
    cin>>n;
    vector<bool> mood(n);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        mood[i]=a==1;
    }
    vi pf = pfac(n);
    set<int> pff;
    for(auto p:pf)
    {
        pff.insert(p);
    }
    for(auto p:pff)
    {
        if(p==2)
        {
            continue;
        }
        for(int i=0;i<n;i++)
        {
            bool  acc = 1;
            for(int j = i;j<n+i;j+=n/p)
            {
                if(!mood[j%n])
                {
                    acc = 0;
                    break;
                }
            }
            if(acc)
            {
                cout<<"YES"<<nl;
                return 0;
            }
        }
    }
    cout<<"NO"<<nl;
 
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
 
 