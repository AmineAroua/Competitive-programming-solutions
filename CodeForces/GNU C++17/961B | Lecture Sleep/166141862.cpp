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
    int n,k;cin>>n>>k;
    vii v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
    }
    ll sum  = 0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i].second;
        int a= v[i].second;
        if(a==1)
            sum+=v[i].first;
    }
    ll s = 0,best = 0;
    for(int i=0;i<k;i++)
    {
        if(v[i].second==0)
            s+=v[i].first;
    }
    best = s;
    for(int i=1;i<=n-k;i++)
    {
        int a = v[i+k-1].first;
        if(v[i+k-1].second==1)a=0;
        int b= v[i-1].first;
        if(v[i-1].second==1)b=0;
        s = s+a-b;
        best = max(best,s);
    }
    cout<<sum+best<<nl;
 
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
 
 