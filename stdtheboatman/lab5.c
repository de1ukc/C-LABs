#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b ? a : b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int time;
    scanf("%d", &time);

    int dp[time + 1];
    for(int i = 0; i <= time; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int curTime = time; curTime >= a[i]; curTime--) {
            dp[curTime] = max(dp[curTime], dp[curTime - a[i]] + 1);
        }
    }

    int ans = dp[time];
    ans = max(ans, 0);

    printf("%d", ans);
    return 0;
}
