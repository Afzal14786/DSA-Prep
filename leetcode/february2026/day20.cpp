// Question Link : https://leetcode.com/problems/special-binary-string/?envType=daily-question&envId=2026-02-20

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        int count =0;
        int start =0;

        int n = s.size();
        vector<string> blocks;

        for(int i=0;i<n;i++){

            if(s[i]=='1'){
                count++;
            }else{
                count--;
            }

            //Found a valid special substring
            if(count==0){
                string subProblem = s.substr(start+1,i-start-1);
                string block = "1" + makeLargestSpecial(subProblem)+"0";
                blocks.push_back(block);
                start = i+1;
            }
        }


        sort(blocks.rbegin(),blocks.rend());
        string ans ="";
        for(string &t:blocks){
            ans+=t;
        }

        return ans;
    }
};
