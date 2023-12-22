// name: Yao Chen   
// email: chen.yao2@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    long long int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;

    for (int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]*2;
    }
    return dp[n];

}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
