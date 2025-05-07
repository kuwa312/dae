#include<stdio.h>
#include<stdlib.h>

int linearSearch(int *a, int n, int key) {//探索対象の配列，配列の長さ，目的の整数
    int i = 0;
    a[n] = key; //配列の末尾に目的の整数を格納．格納する値はなんでもいい．nに達するための番兵．
    while (a[i] != key) {
        i++;
    }
    if (i == n) {
        return 0;
    }
    return 1;
}

int main(void) {
    int s[10000];
    int t[500];

    int n, q, i;
    int count = 0;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
       scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    for (i=0; i<q; i++) {
       scanf("%d", &t[i]);
    }
    for (i=0; i<q; i++) {
        int key = t[i];
        if (linearSearch(s, n, key)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

