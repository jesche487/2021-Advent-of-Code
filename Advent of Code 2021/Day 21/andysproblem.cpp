#include <bits/stdc++.h>
using namespace std;
/*
long long fib(long long n, unordered_map<int,long long> &memo) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(!memo.count(n)) {
    memo[n] = fib(n-1,memo) + fib(n-2,memo);
    }

    return memo[n];
}
*/



int main(){
    // unordered_map<int,long long> memo;
    int n = 50;
    vector<long long> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i < dp.size(); i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[50];


    // cout << fib(50, memo);

}