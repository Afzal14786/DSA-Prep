// You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

//     code[i]: a string representing the coupon identifier.
//     businessLine[i]: a string denoting the business category of the coupon.
//     isActive[i]: a boolean indicating whether the coupon is currently active.

// A coupon is considered valid if all of the following conditions hold:

//     code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
//     businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
//     isActive[i] is true.

// Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

// Example 1:

// Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]
// Output: ["PHARMA5","SAVE20"]

// Explanation:

//     First coupon is valid.
//     Second coupon has empty code (invalid).
//     Third coupon is valid.
//     Fourth coupon has special character @ (invalid).

// Example 2:

// Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]
// Output: ["ELECTRONICS_50"]

// Explanation:

//     First coupon is inactive (invalid).
//     Second coupon is valid.
//     Third coupon has invalid business line (invalid).

// Constraints:

//     n == code.length == businessLine.length == isActive.length
//     1 <= n <= 100
//     0 <= code[i].length, businessLine[i].length <= 100
//     code[i] and businessLine[i] consist of printable ASCII characters.
//     isActive[i] is either true or false.

// Question Link : https://leetcode.com/problems/coupon-code-validator/?envType=daily-question&envId=2025-12-13
// Solution Link : https://leetcode.com/problems/coupon-code-validator/submissions/1854795991/?envType=daily-question&envId=2025-12-13

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool isValid(string &s) {
        if (s.size() == 0) return false;
        for (char ch : s) {
            if (!isalnum(ch) && ch != '_') return false;
        }

        return true;
    }

    bool isValidBusiness(string &s) {
        if (s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant") {
            return true;
        }
        return false;
    }


    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, multiset<string>> mp;
        int n = code.size();
        for (int i = 0; i < n; ++i) {
            if (isActive[i] && isValid(code[i]) && isValidBusiness(businessLine[i])) {
                mp[businessLine[i]].insert(code[i]);
            }
        }

        vector<string> ans;
        for (auto i : mp) {
            for (string j : i.second) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};