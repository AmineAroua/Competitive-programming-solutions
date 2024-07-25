#include "gondola.h"
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
int valid(int n, int inputSeq[])
{
    bool acc = 1;
    set<int> s;
    for(int i = 0 ; i< n ; i++)
    {
        inputSeq[i]--;
        s.insert(inputSeq[i]);
        if(inputSeq[i] < n)
            acc = 0;
    }
    if((int)s.size() != n)
        return 0;
    if(acc)
        return 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(inputSeq[i] < n)
        {
            int j = i;
            int ok = 1;
            do {
                j = (j + 1) % n;
                if (inputSeq[j] >= n)
                    continue;
                if (inputSeq[j] != (inputSeq[i] + j - i + n) % n) {
                    ok = 0;
                    break;
                }
            }
            while(i != j);
            return ok;
        }
    }
}
 
//----------------------
 
int replacement(int n, int gondolaSeq[], int replacementSeq[])
{
    vector<pair<int, int>> s;
    vector<int> perm(n);
    for(int i = 0 ; i < n ; i++)
        perm[i] = i;
    for(int i = 0 ; i < n ; i++)
        gondolaSeq[i]--;
    for(int i = 0 ; i <  n ; i++)
    {
        if(gondolaSeq[i] >= n)
            continue;
        perm[i] = gondolaSeq[i];
        int j = i;
        do
        {
            j = (j + 1)%n;
            perm[j] = (gondolaSeq[i] + j - i + n)%n;
        } while (i != j);
        break;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(gondolaSeq[i] >= n)
            s.push_back({gondolaSeq[i] , i});
    }
    sort(s.begin() , s.end());
    int t = 0;
    int cnt = n - 1;
    for(auto [x , i] : s)
    {
        int last = perm[i];
        while (cnt < x)
        {
            cnt++;
            replacementSeq[t++] = last + 1;
            assert(t <= 250000);
            last = cnt;
        }
    }
    return t;
}
 
//----------------------
const int M = 1e9 + 9;
long long bpow(int x , int p)
{
    if(p == 0)
        return 1;
    long long u = bpow(x , p/2);
    u = (u * u)%M;
    if(p%2)
        u = (u * x)%M;
    return u;
}
int countReplacement(int n, int gondolaSeq[])
{
    vector<pair<int, int>> s;
    vector<int> all(n);
    vector<int> perm(n);
    for(int i = 0 ; i < n ; i++)
        perm[i] = i;
    for(int i = 0 ; i < n ; i++)
    {
        gondolaSeq[i]--;
        all[i] = gondolaSeq[i];
    }
    sort(all.begin() , all.end());
    all.erase(unique(all.begin() , all.end()) , all.end());
    if((int)all.size() != n)
        return 0;
    for(int i = 0 ; i <  n ; i++)
    {
        if(gondolaSeq[i] >= n)
            continue;
        perm[i] = gondolaSeq[i];
        int j = i;
        do
        {
            j = (j + 1)%n;
            if(gondolaSeq[j] < n && gondolaSeq[j] != (gondolaSeq[i] + j - i + n)%n)
                return 0;
            perm[j] = (gondolaSeq[i] + j - i + n)%n;
        } while (i != j);
        break;
    }
    int t = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(gondolaSeq[i] >= n)
        {
            t++;
            s.push_back({gondolaSeq[i] , i});
        }
    }
    long long nbWays =1;
    if(t == n)
        nbWays = n;
    sort(s.begin() , s.end());
    int cnt = n - 1;
    for(auto [x , i] : s)
    {
        int k = x - cnt - 1;
        nbWays = (nbWays * bpow(t , k))%M;
        cnt = x;
        t--;
    }
    return (int)nbWays;
}
