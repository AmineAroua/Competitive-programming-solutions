#include <bits/stdc++.h>
using namespace std;
int main()
{
    // A , B , C 
    // A <= B
    // find a multiple of C in [A , B] 
    // if not found : -1
    int a , b , c;
    cin>>a>>b>>c;
    
    // find x : x = k * C  
    // A <= x <= B
    // A <= k * C <= B
    // A/C <= k <= B/C
    
    // k integer , A/C <= k <= B/C
    //   A/C = 2.4 <= k <= B/C = 2.8
    
    // largest multiple in [A , B]
    
    int k = (int)floor((double)b / c);
    int multiple = k * c;
    if(multiple >= a)
    {
        cout<<multiple;
    }
    else
        cout<<-1;
}
