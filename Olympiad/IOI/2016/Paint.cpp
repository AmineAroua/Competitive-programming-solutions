#pragma once
#include <bits/stdc++.h>
using namespace std;
#define forr(i, x , y) for(int i = x ; i<=y;i++)
#define fore(i , x) for(int i = 0 ; i<x;i++)
#define forn(i , x ,y) for(int i = x; i>=y;i--)
vector<vector<int>> pref;
std::string solve_puzzle(std::string s, std::vector<int> c)
{
    int n = (int)s.size();
    int K = (int)c.size();
    s = '0' + s;
    pref.assign(2 , vector<int>(n + 1 , 0));
 
    forr(i , 1 , n)
    {
        pref[0][i] = pref[0][i - 1] + (s[i] == '_');
        pref[1][i] = pref[1][i - 1] + (s[i] == 'X');
    }
 
    vector<vector<int>> dpL(n + 3 , vector<int>(K + 3 , 0)) , dpR(n + 3 , vector<int>(K + 3 , 0));
    dpL[0][0] = 1;
    forr(i , 1 , n)
    {
        forr(j , 0 , K) {
            if(j - 1 >= 0 && c[j - 1] <= i && (pref[0][i] - pref[0][i - c[j - 1]] == 0) && (i - c[j - 1] <= 0 || s[i - c[j - 1]] != 'X'))
            {
                if(i - c[j - 1] == 0)
                {
                    if(j == 1)
                        dpL[i][j]|=1;
                }
                else
                {
                    dpL[i][j]|=dpL[i - c[j - 1] - 1][j - 1];
                }
            }
            if(s[i] != 'X')
                dpL[i][j]|=dpL[i - 1][j];
        }
    }
 
    dpR[n + 1][K] = 1;
    dpR[n + 2][K] = 1;
    forn(i , n , 1)
    {
        forr(j , 0 , K) {
            if(j < K && c[j] <= n - i + 1 && pref[0][i + c[j] - 1] - pref[0][i - 1] == 0 && (i + c[j] > n || s[i + c[j]] != 'X'))
            {
                if(i + c[j] == n + 1)
                {
                    if(j == K - 1)
                        dpR[i][j]=1;
                }
                else
                    dpR[i][j]|=dpR[i + c[j] + 1][j + 1];
            }
            if(s[i] != 'X')
                dpR[i][j]|=dpR[i + 1][j];
        }
    }
    vector<int> can_black(n +5 , 0);
 
    vector<int> val(n + 1 , 0);
    forr(i , 1 , n)
    {
            int cur = 0;
            forr(k , 0 , K)
            {
                if((dpL[i - 1][k] && dpR[i + 1][k])&& s[i] != 'X')
                    cur = 1;
            }
            if(cur == 1)
                val[i]|=1;
    }
    forr(i , 1 , n)
    {
            forr(k , 0 , K - 1)
            {
                if((i==1?(k==0):(dpL[i-2][k]&&s[i-1]!='X'))&&i+c[k]-1<=n&&dpR[i+c[k]+1][k+1]&&pref[0][i+c[k]-1]-pref[0][i-1]==0&&(i+c[k]>n||s[i+c[k]]!='X'))
                {
                    if(i + c[k] > n)
                    {
                        if(k + 1 == K)
                        {
                            can_black[i]++;
                            can_black[i + c[k]]--;
                        }
                    }
                    else
                    {
                        can_black[i]++;
                        can_black[i + c[k]]--;
                    }
                }
            }
    }
    forr(i , 1 , n)
    {
        can_black[i]+=can_black[i - 1];
        if(can_black[i])
            val[i]|=2;
    }
    string ans = "";
    forr(i , 1 ,n)
    {
        if(val[i] == 1)
            ans+='_';
        else if(val[i] == 2)
            ans+= 'X';
        else
            ans+='?';
    }
    return ans;
}
