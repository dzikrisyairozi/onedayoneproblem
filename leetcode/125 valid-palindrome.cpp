#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j){
            while(!isalnum(s[i]) && i < j){
                i+=1;
            }
            while(!isalnum(s[j]) && j > i){
                j-=1;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i+=1; j-=1;
        }
        return true;
    }
};