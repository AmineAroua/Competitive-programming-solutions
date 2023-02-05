#include <bits/stdc++.h>
#include <vector>
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
//variables:
 
//functions:
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
int compare(const void* a, const void* b)
{
   const int* x = (int*) a;
   const int* y = (int*) b;
   return (*x - *y);
}
 
//bsearch(&cible,arr,n,sizeof(int),compare);
 
 
int main()
{
    boost;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        map<int,vi> pos;
        vi c(n);
        for(int i=0;i<n;i++){
            cin>>c[i];
            pos[c[i]-1].pb(i);
        }
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[i]=0;
        }
        for(auto it=pos.begin();it!=pos.end();it++){
            vi v=it->second;
            int ans=1;
            for(int j=0;j<v.size()-1;j++){
                if((v[j+1]-v[j]-1)%2==0)ans++;
            }
            mp[it->first]=ans;
        }
        for(int i=0;i<n;i++)cout<<mp[i]<<" ";
        cout<<nl;
    }
}
 
 
 
 
/*
Test 1
INPUT:                              |OUTPUT:
                                    |
                                    |
                                    |
                                    |
                                    |
                                    |
        |
Test 2                              |
INPUT:                              |OUTPUT:
                                    |
                                    |
                                    |
                                    |
                                    |
        |
        |
        |
        |
----------------------------------------------------------------------------------------
 
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
 
 