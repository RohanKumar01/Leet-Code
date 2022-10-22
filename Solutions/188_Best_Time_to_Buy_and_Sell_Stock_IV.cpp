#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// Naive Method

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k == 0)
            return 0;
        if (prices.size() == 0 || prices.size() == 1)
            return 0;

        vector<vector<int>> dp(k + 1, vector<int>(prices.size()));
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[i].size(); j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 0;
                else
                {
                    int x;
                    int mx = INT_MIN;
                    for (int k = 0; k < j; k++)
                    {
                        x = prices[j] - prices[k] + dp[i - 1][k];
                        mx = max(x, mx);
                    }
                    dp[i][j] = max(dp[i][j - 1], mx);
                }
            }
        }
        return dp[dp.size() - 1][prices.size() - 1];
    }
};

// Optimized
class Solution
{
public:
    int maxProfit(int k, vector<int> &price)
    {

        vector<int> dp(2 * k + 1, INT_MIN);
        dp[0] = 0;

        for (int j = 0; j < price.size(); j++)
        {

            for (int i = 0; i + 2 <= 2 * k; i += 2)
            {

                dp[i + 1] = max(dp[i + 1], dp[i] - price[j]);
                dp[i + 2] = max(dp[i + 2], dp[i + 1] + price[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};