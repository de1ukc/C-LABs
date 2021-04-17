#include<bits.h>
const int n = 8;
int step = 0;
void make(int **dp, int i, int j, int value) {
    for(int x = -n; x < n; x++)
    {
        if(j + x >= 0 && j + x < n && x != 0) dp[i][j + x] += value;
        if(i + x >= 0 && i + x < n){
            if(x != 0) dp[i + x][j] += value;
            if(j + x >= 0 && j + x < n) {
                dp[i + x][j + x] += value;
                if(i - x >= 0 && i - x < n) dp[i - x][j + x] += value;
            }
        }
    }
    dp[i][j] -= value;
}
void rec(int x, int y, int **dp, char ** f) {
    f[x][y] = 'X';
    make(dp, x, y, 1);
    step++;
    if(step == 8) {
        for(int i= 0; i < n; i++) {
            for(int j = 0; j < n; j++) printf("%c%c", f[i][j], ' ');
            printf("%c", '\n');
        }
        exit(0);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) if(dp[i][j] == 0) {
            rec(i, j, dp, f);
        }
    make(dp, x, y, -1);
    f[x][y] = '.';
    step--;
}
int main() {
    char **f = (char **)malloc(8 * sizeof(char *));
    for(int i = 0; i < 8; i++) {
        f[i] = (char *)malloc(8*sizeof(char));
        for(int j = 0; j < n; j++) f[i][j] = '.';
    }
    int **dp = (int **)malloc(8 * sizeof(int *));
    for(int i = 0; i < 8; i++) {
        dp[i] = (int *)malloc(8 * sizeof(int));
        for(int j = 0; j < n; j++) dp[i][j] = 0;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            rec(i, j, dp, f);
        }

    for(int i= 0; i < n; i++) {
        free(f[i]);
        free(dp[i]);
    }
    free(f);
    free(dp);


}
