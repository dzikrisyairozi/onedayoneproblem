#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        
        vector<int> count(26);
        
        for(int i=0; i<s.size(); i++){
            count[s[i] - 'a']++;
        }
        
        for(int j=0; j<s.size(); j++){
            count[t[j] - 'a']--;
            if(count[t[j] - 'a'] < 0){
                return false;
            }
        }
        return true;        
    }
};