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
        int al=0,bb=0;
        vi v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
            al=v[0];
            bb=v[n-1];
 
        int c=0;
        int i=0,j=n-1;
        while(i<j){
 
            if(al>bb&&j-1>i){j--;bb+=v[j];}
            if(al<bb&&i+1<j){i++;al+=v[i];}
            if(al==bb){c=i+1+n-j;i++;if(i+1<j)al+=v[i];}
            if(!(al<bb&&i+1<j)&&!(al>bb&&j-1>i))break;}
        cout<<c<<nl;}
 
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
 
 