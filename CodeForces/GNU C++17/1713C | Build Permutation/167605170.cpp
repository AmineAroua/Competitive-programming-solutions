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
        int n;cin>>n;
        vector<bool> found(200000,false);
        vi sq;
        vi per;
 
        for(int i=0;i<=448;i++)
        {
            sq.pb(i*i);
        }
        int r=448;
        for(int i=n-1;i>=0;i--)
        {
            while(sq[r]-i>=n||found[sq[r]-i]&&r-1>=0)
                r--;
            per.pb(sq[r]-i);
            found[sq[r]-i]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            cout<<per[i]<<" ";
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
 
 