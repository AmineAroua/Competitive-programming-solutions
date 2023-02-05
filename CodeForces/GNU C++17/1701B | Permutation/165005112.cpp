#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<2<<'\n';
        set<int> st;
        for(int i=1;i<=n;i++)st.insert(i);
        for(int i=1;i<=n;i++){
            int j=i;
            while(st.count(j)){
                cout<<j<<" ";
                st.erase(j);
                j*=2;
            }
        }
        cout<<'\n';
    }
 
}