#include<stdio.h>

int gcd(int x, int y) {
    int tmp;
    int r;
    if (x < y) {
        tmp = x;
        x = y;
        y = tmp;
    }
    // x > y
    while(y > 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}


int main(void) {
    int x;
    int y;
    int z;
    scanf("%d %d", &x , &y);
    z = gcd(x, y);
    printf("%d\n", z);
    return 0;
}