#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define nl '\n'
#define boost ios::sync_with_stdio(false)
//variables:
 
//functions:
int compare(const void* a, const void* b)
{
   const int* x = (int*) a;
   const int* y = (int*) b;
   return (*x - *y);
}
// binary search
 
//bsearch(&cible,arr,n,sizeof(int),compare);
 
 
int main()
{
    boost;
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n];
        int restore =0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(m<a[i]){
                restore+=abs(m-a[i]);
                m=0;
            }
            else{
                m-=a[i];
            }
        }
        cout<<restore<<nl;
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
 
 