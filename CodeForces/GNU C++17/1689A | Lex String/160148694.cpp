#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define nl '\n'
#define boost ios::sync_with_stdio(false)
//variables:
 
//functions:
void sortString(string &str)
{
   sort(str.begin(), str.end());
}
bool mt(string a,int l1){
    for(int i=0;i<l1;i++){
        if(a[i]!='\0')
            return true;
    }
    return false;
}
int main()
{
    boost;
    int t;cin>>t;
    while(t--)
    {
        int l1,l2,k;
        cin>>l1>>l2>>k;
        string a,b;
        cin>>a>>b;
        sortString(a);sortString(b);
        char c[l1+l2];
        int i=0,j=0,h=0,n=0,m=0;
        if(a<=b)
        {
        while(mt(a,l1)&&mt(b,l2))
        {
            if(mt(a,l1)&&mt(b,l2))
            {c[m]=a[i];h++;m++;a[i]='\0';i++;}
            while(i<l1&&a[i]<b[j]&&h<k&&mt(a,l1)&&mt(b,l2))
            {
                c[m]=a[i];
                a[i]='\0';
                m++;
                i++;
                h++;
            }
            h=0;
            if(mt(a,l1)&&mt(b,l2))
            {c[m]=b[j];n++;m++;b[j]='\0';j++;}
            while(j<l2&&b[j]<=a[i]&&n<k&&mt(a,l1)&&mt(b,l2)){
                c[m]=b[j];
                b[j]='\0';
                m++;
                j++;
                n++;
            }
            n=0;
        }}
        else{
        while(mt(a,l1)&&mt(b,l2))
        {
            if(mt(a,l1)&&mt(b,l2))
            {c[m]=b[j];n++;m++;b[j]='\0';j++;}
            while(j<l2&&b[j]<a[i]&&n<k&&mt(a,l1)&&mt(b,l2))
            {
                c[m]=b[j];
                b[j]='\0';
                m++;
                j++;
                n++;
            }
            n=0;
            if(mt(a,l1)&&mt(b,l2))
            {c[m]=a[i];h++;m++;a[i]='\0';i++;}
            while(i<l1&&a[i]<=b[j]&&h<k&&mt(a,l1)&&mt(b,l2)){
                c[m]=a[i];
                a[i]='\0';
                m++;
                i++;
                h++;
            }h=0;
        }
        }
 
        for(int v=0;v<m;v++)
            cout<<c[v];
        cout<<nl;
    }
}
// sort the two strings
// compare the two str
// compare their lengths
 
// do the operation on the smallest lexicographically string
// add first k chars from this string at the end of c
 
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
 
 