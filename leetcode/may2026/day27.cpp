// Question Link : https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/?envType=daily-question&envId=2026-05-27

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> freq(26,0);
        vector<int> freq1(26,0);
        for(int i=0;i<n;++i) {
            if(word[i]>='A' && word[i]<='Z') {
                freq[word[i]-'A']++;
            }
            else if(word[i]>='a' && word[i]<='z') {
                freq1[word[i]-'a']++;
            }
        }
        int cnt = 0;
        for(int i=0;i<26;++i) {
            if(freq[i]>0 && freq1[i]>0) {
                char c = i+'a';
                char c1 = i+'A';
                int idxc = 0;
                int idxc1 =0;
                for(int i=0;i<n;++i) {
                    if(word[i]==c){
                        idxc = i;
                    }
                }
                for(int i=0;i<n;++i) {
                    if(word[i]==c1){
                        idxc1 = i;
                        break;
                    }
                }
                if(idxc<idxc1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
