#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *a, int n, int key) {//探索対象の配列，配列の長さ，目的の整数
    int left = 0;
    int right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        if (a[mid] == key) {
            return mid;
        } else if (key < a[mid]) {
            right = mid; //rightは末尾の次の要素の添字
        } else {
            left = mid + 1; //mid = keyでは無いので，mid+1をleftにする
        }
    }
    return 0;
}

int main(void) {
    int s[100000];
    int t[50000];

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
        if (binarySearch(s, n, key)) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}