#include<bits/stdc++.h>
using namespace std;

const int D = 1000;
int t[D][D];

// Recursive Solution
int knapSack(int wt[], int val[], int cap, int n) {
    if(n == 0 || cap == 0) return 0;


    if(wt[n - 1] <= cap) {
        // We have 2 choices now

        /*         return max(Include, Not Include); 

                                    Include                                           Not Include         */
        return max(val[n - 1] + knapSack(wt, val, cap - wt[n - 1], n - 1), knapSack(wt, val, cap, n - 1));
    }
    else if(wt[n - 1] > cap) 
    return knapSack(wt, val, cap, n - 1);
}

// Memoizisation Technique
int KnapSack(int wt[], int val[], int W, int n) {
    if(n == 0 || W == 0) return 0;

    if(t[n][W] != -1) {
        return t[n][W];
    }
    else {
        if(wt[n - 1] <= W) {
            t[n][W] = max(val[n - 1] + KnapSack(wt, val, W - wt[n - 1], n - 1), KnapSack(wt, val, W, n - 1));
        }
        else if(wt[n - 1] > W) {
            t[n][W] = KnapSack(wt, val, W, n - 1);
        }
        else {
            return t[n][W];
        }
    }
}



// Top - Down Approach
int KNAPSACK(int wt[], int val[], int W, int n) {
    int dp[n + 1][W + 1];
    for(int i = 0 ; i < n + 1 ; i++) {
        for(int j = 0 ; j < W + 1 ; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if(wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else if(wt[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, cap;
    cin >> n >> cap;
    int wt[n];
    int val[n];
    for(int i = 0 ; i < n ; i++) cin >> wt[i];
    for(int i = 0 ; i < n ; i++) cin >> val[i];
    for(int i = 0 ; i < n + 1 ; i++) {
        for(int j = 0 ; j < cap + 1 ; j++) {
            t[i][j] = -1;
        }
    }
    cout << knapSack(wt, val, cap, n) << endl; // Recursion 
    cout << KnapSack(wt, val, cap, n) << endl; // Recursion + Memoizisation
    cout << KNAPSACK(wt, val, cap, n) << endl; // Top - Down Approach
}