// Question Link : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/?envType=daily-question&envId=2026-07-08
//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (const auto query : queries) {
            int l = query[0], r = query[1];
            long long sum = 0;
            long long x = 0;

            for (int i = l; i <= r; ++i) {
                int digit = s[i] - '0';
                
                if (digit != 0) {
                    sum += digit;
                    x = (x * 10 + digit) % MOD;
                }
            }

            long long result = (sum * x) % MOD;
            ans.push_back(result);
        }

        return ans;
    }
};

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();

        // Precompute powers of 10 modulo MOD
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // Prefix arrays (1-indexed to avoid out-of-bounds checks)
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> pref_x(m + 1, 0);
        vector<int> non_zero_count(m + 1, 0);

        long long current_x = 0;

        for (int i = 0; i < m; ++i) {
            int digit = s[i] - '0';
            
            // Inherit previous states
            pref_sum[i + 1] = pref_sum[i];
            non_zero_count[i + 1] = non_zero_count[i];

            if (digit != 0) {
                pref_sum[i + 1] += digit;
                non_zero_count[i + 1]++;
                current_x = (current_x * 10 + digit) % MOD;
            }
            pref_x[i + 1] = current_x;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& query : queries) {
            // 1 based indexing 
            int l = query[0] + 1;
            int r = query[1] + 1;

            // Calculate the sum of non-zero digits in O(1)
            long long sum_val = pref_sum[r] - pref_sum[l - 1];

            // Calculate the non-zero sequence 'x' in O(1)
            int k = non_zero_count[r] - non_zero_count[l - 1];
            long long x_val = (pref_x[r] - (pref_x[l - 1] * pow10[k]) % MOD + MOD) % MOD;

            // Combine and apply final modulo
            long long result = (sum_val * x_val) % MOD;
            ans.push_back(result);
        }

        return ans;
    }
};

