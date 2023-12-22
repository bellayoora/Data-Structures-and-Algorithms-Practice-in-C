// name: Yao Chen   
// email: chen.yao2@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    d[3] = 0;
    for(int i=4; i<=n; i++){
        int sum=0;
        for(int j=i-4; j>=0;j-=2){
            sum += d[j];
        }

        d[i] = 3*d[i-2]+sum*2;
    }
    
    return d[n];

}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}