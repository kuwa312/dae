#include<stdio.h>
#include<math.h>


int isPrime(int x) { 
    int i;
    if (x == 2) {
        return 1;
    } 
    else if (x<2 || x%2==0) {
        return 0;
    }
    i = 3;
    while (i <= sqrt(x)) {
        if (x%i == 0) {
            return 0;
        }
        i = i + 2;
    }
    return 1;
}

int main(void) {
    int n;
    int i;
    int x;
    int count = 0;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &x);
        if (isPrime(x) == 1) {
            count++;
        }


    }
    printf("%d\n", count);

    return 0;
}