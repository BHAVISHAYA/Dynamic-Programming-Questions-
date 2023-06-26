#include<bits/stdc++.h>
using namespace std;


// Recursive Solution
bool subSetSum(int n, int sum,  vector<int> &nums) {
    if(n == 0) {
        if(sum == 0) {
            return true;
        }
        return false;
    }

    bool op1 = subSetSum(n - 1, sum - nums[n - 1], nums);
    bool op2 = subSetSum(n - 1, sum, nums);

    return (op1 || op2);
}


// Top - Down Approach
bool SubSetSumProblem(int n, int sum, vector<int> &nums) {
    int dp[n + 1][sum + 1];
    for(int i = 0 ; i < n + 1 ; i++) {
        for(int j = 0 ; j < sum + 1 ; j++) {
            // Initialization
            if(i == 0 &&  j != 0) {
                dp[i][j] = false;
            }
            else if(j == 0) {
                dp[i][j] = true;
            }
            else if(nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}


int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++) cin >> nums[i];
    cout << subSetSum(nums.size(), sum, nums) << endl;
    cout << SubSetSumProblem(nums.size(), sum, nums) << endl;
}