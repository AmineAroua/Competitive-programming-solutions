#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int a;cin>>a;
        int tab[a];
        for(int i=0;i<a;i++){
            cin>>tab[i];
 
        }
        sort(tab,tab+a);
        int h=a;
        for(int i=0;i<a-1;i++){
            if(tab[i]==tab[i+1])
            {
                h--;
            }
        }
        if((a-h)%2==0)
            cout<<h<<endl;
        else
            cout<<h-1<<endl;
    }
}