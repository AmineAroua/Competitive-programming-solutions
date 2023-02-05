#include <iostream>
using namespace std;
int main() 
{
    int number;
    cin>>number;
    if(number==2)
    {
        cout<<"NO";
        return 0;
    }
    if (number%2==0)
    cout<<"YES";
    else cout<<"NO";
}