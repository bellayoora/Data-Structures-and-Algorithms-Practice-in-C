// name: Yao Chen   
// email: chen.yao2@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    if (d[n] > 0) {
        return d[n];
    }
    long long int ans = dp(n-1) + dp(n-2);
    d[n] = ans;
    return ans;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
