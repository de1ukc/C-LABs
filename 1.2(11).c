#include<bits.h>

int main() {
    int pos;
    scanf("%d", &pos);
    if(pos < 1) {
        printf("%s", "Incorrect Enter");
        return 0;
    }
    int step = 1;
    while(1) {
        int x = step * step;
        int k = 0;
        while(x) {
            k++;
            x /= 10;
        }
        if(k >= pos) {
            x = step * step;
            pos = k - pos;
            while(pos--) {
                x /= 10;
            }
            printf("%d", x % 10);
            return 0;
        }
        pos -= k;
        step++;
    }
}
