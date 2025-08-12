#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w;
    // read w 
    cin>>w;
    // if w pair and w > 2 : YES
    if(w % 2 == 0 && w > 2)
    {
        cout<<"YES";
    }
    // else : NO
    else
    {
        cout<<"NO";
    }
}
