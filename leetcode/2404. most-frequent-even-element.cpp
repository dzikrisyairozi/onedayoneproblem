#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& A) {
        //For Runtime allocation in place of using array of size 10^5
        unordered_map<int,int> mp;
        int val=1e6,freq=0;
        for(auto i:A){
            //if even element
            if(i%2==0){
                //increase frequency in map
                mp[i]++;
                //Update smallest with greatest frequency
                if(mp[i]>freq or mp[i]==freq and i<val){
                    val=i;
                    freq=mp[i];
                }
            }
        }
        return freq==0? -1 : val;
    }
};
