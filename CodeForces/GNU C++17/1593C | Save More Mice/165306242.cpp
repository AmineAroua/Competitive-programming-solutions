#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        int k;cin>>k;
        vector<long long> v(k);
        for(int i=0;i<k;i++){
            long long a;
            cin>>a;
            v[i]=n-a;
        }
        sort(v.begin(),v.end());
        long long sum=0;
        long long  i=0;
        while(sum<n-v[i]&&i<k)
        {
            sum+=v[i];
            i++;
        }
        cout<<i<<'\n';
    }
}