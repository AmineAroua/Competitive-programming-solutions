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
 
int main()
{
    boost;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v(n);
        vi arr(101,0);
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr[a]++;
            v.pb(a);
        }
        for(int i=0;i<101;i++){
            if(arr[i]>0){cout<<i<<" ";arr[i]--;}
        }
        for(int i=0;i<101;i++){
            if(arr[i]>0)
            {for(int j=0;j<arr[i];j++)cout<<i<<" ";}
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
 
 