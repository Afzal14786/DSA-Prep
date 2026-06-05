// Question Link : https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/?envType=daily-question&envId=2026-06-05

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    string S;
    // Memoization Table
    // Dimensions: [index][prev_digit][prev_prev_digit][tight_constraint][leading_zeros_flag][type]
    // type 0 = count of ways
    // type 1 = sum of waviness
    long long memo[20][11][11][2][2][2];

    void dp(int idx, int prev, int pprev, bool tight, bool leading_zeros,
            long long& ret_count, long long& ret_sum) {
        
        // Base Case: We have filled all positions. 
        // We found 1 valid number with 0 additional waviness to add at this exact step.
        if (idx == S.size()) {
            ret_count = 1;
            ret_sum = 0;
            return;
        }

        // Return cached result if computed.
        // We must manually assign cached values to the reference parameters.
        if (memo[idx][prev][pprev][tight][leading_zeros][0] != -1) {
            ret_count = memo[idx][prev][pprev][tight][leading_zeros][0];
            ret_sum = memo[idx][prev][pprev][tight][leading_zeros][1];
            return;
        }

        long long total_count = 0;
        long long total_sum = 0;
        int limit = tight ? (S[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; ++digit) {
            // Update constraints for the next state
            bool next_tight = tight && (digit == limit);
            bool next_lz = leading_zeros && (digit == 0);
            
            // 10 is used as a dummy value for "no digit yet"
            int next_prev = next_lz ? 10 : digit;
            int next_pprev = next_lz ? 10 : prev;

            long long sub_count = 0, sub_sum = 0;

            // Recursive call using pass-by-reference
            dp(idx + 1, next_prev, next_pprev, next_tight, next_lz, sub_count,
               sub_sum);

            total_count += sub_count;
            total_sum += sub_sum;

            // Check if the 'prev' digit forms a Peak or Valley based on 'pprev' and current 'digit'
            if (!leading_zeros && prev != 10 && pprev != 10) {
                bool isPeak = (prev > pprev && prev > digit);
                bool isValley = (prev < pprev && prev < digit);
                
                // If 'prev' is a peak/valley, it contributes +1 to the waviness 
                // of ALL 'sub_count' numbers that follow this path.
                if (isPeak || isValley) {
                    total_sum += sub_count;
                }
            }
        }

        // Cache and update the reference parameters
        memo[idx][prev][pprev][tight][leading_zeros][0] = ret_count = total_count;
        memo[idx][prev][pprev][tight][leading_zeros][1] = ret_sum = total_sum;
    }

    long long solve(string s) {
        S = s;
        memset(memo, -1, sizeof(memo));
        long long count, sum;
        // Initial call: index 0, dummy prev digits (10), tight=true, leading_zeros=true
        dp(0, 10, 10, true, true, count, sum);
        return sum;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        // Standard range query logic: Ans(R) - Ans(L-1)
        long long ans2 = solve(to_string(num2));
        long long ans1 = solve(to_string(num1 - 1));
        return ans2 - ans1;
    }
};
