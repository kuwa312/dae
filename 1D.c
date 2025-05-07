#include<stdio.h>
#include<stdlib.h>

int maxProfit(int *a, int n) {
    int minv;
    int maxv;
    int j;
    minv = a[0];

    // minvはa[0]で良いが,maxvの初期化が必要なので，a[0]とa[1]の小さいほうにした．
    if (a[0] > a[1]) {
        minv = a[1];
    }
    maxv = a[1] - a[0];

    for (j=2; j<n; j++) {
        if (maxv < (a[j]-minv)) {
            maxv = a[j] - minv;
        }
        if (a[j] < minv) {
            minv = a[j];
        }

    }
    return maxv;

}

int main(void) {
    int *a = NULL;
    int n;
    int i;
    int x;
    int maxv;
    scanf("%d", &n);
    a = malloc(sizeof(int)*n);
    if (a==NULL) {
        fprintf(stderr, "aのmallocが失敗\n");
        exit(1);
    }
    for (i=0; i<n; i++) {
        scanf("%d", &x);
        a[i] = x;
    }
    maxv = maxProfit(a, n);
    printf("%d\n", maxv);
    free(a);
    a = NULL;

    return 0;
}