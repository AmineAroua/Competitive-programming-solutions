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
//variables:

//functions:
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
ll MOD = 1e9+7;
int main()
{
    boost;
    ll n;cin>>n;
    ll fact[100001];
    fact[0]=1;
    for(int i=1;i<100001;i++)fact[i]=(fact[i-1]*i)%MOD;
    ll ans1=(((fact[n/2]*fact[n/2-1])%MOD)*n)%MOD,ans2 = (((fact[n/2]*fact[n/2])%MOD)*(n/2+1))%MOD;
    if(n==2)cout<<2<<" "<<2<<nl;
    else if(n==3)cout<<4<<" "<<2<<nl;
    else if(n%2==0)cout<<ans1<<" "<<ans1<<nl;
    else{
        cout<<(((((fact[n/2+1]*fact[n/2-1])%MOD)*(n/2))%MOD)+(((fact[n/2]*fact[n/2])%MOD)*(n/2+1))%MOD)%MOD<<" "<<ans2<<nl;
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


