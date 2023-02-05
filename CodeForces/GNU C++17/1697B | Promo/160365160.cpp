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
int sumax(int i,int n,int tab[]){
    int sum=0;
    for(int k=n-1;k>=n-i;k--){
        sum+=tab[k];
    }
    return sum;
}
// binary search
 
//bsearch(&cible,arr,n,sizeof(int),compare);
 
 
int main()
{
    boost;
    int n,q;cin>>n>>q;
    int tab[n];
    ll sumMax[n+1];
    for(int i=0;i<n;i++){
        cin>>tab[i];
    }
    sort(tab,tab+n);
    sumMax[0]=0;
    for(int i=1;i<n+1;i++){
        sumMax[i]=sumMax[i-1]+tab[n-i];
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(a==b)
            cout<<sumMax[a]<<endl;
        else
            cout<<sumMax[a]-sumMax[a-b]<<endl;
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
 
 