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
        int n,m;cin>>n>>m;
        vii v;
        vi v1(n);
        for(int i=0;i<n;i++){cin>>v1[i];}
        ll sum=1e18+1;
        vii vp(m);
        vector<int> found(n,0);
        for(int i=0;i<m;i++){
            cin>>vp[i].first>>vp[i].second;
            v.pb(mp(v1[vp[i].first-1],vp[i].first-1));
            v.pb(mp(v1[vp[i].second-1],vp[i].second-1));
            sum=min(sum,(ll)(v1[vp[i].first-1]+v1[vp[i].second-1]));
            found[vp[i].second-1]++;found[vp[i].first-1]++;
        }
        if(m%2==0)cout<<0<<nl;
        else{
            bool acc=true;
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                if(v[i].first<sum&&found[v[i].second]%2==1){cout<<v[i].first<<nl;acc=false;break;}
 
            }
         if(acc)cout<<sum<<nl;
        }
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
 
 