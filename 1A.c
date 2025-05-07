#include<stdio.h>
#include<stdlib.h>

int arrayScan(int *a) //整数ｎ，ｎ個のデータをスキャン，ｎを返す
{
    int n;
    int i;
    scanf("%d", &n);
    *a = malloc(n * sizeof(int));
    if (*a == NULL) {
        exit(1);
    }
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    return n;
}

void arrayPrint(int n, int *a) {
    int i;
    for (i=0; i<n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[i]);
}

void insertionSort(int *a, int n) {
    int i;
    for (i=1; i<n; i++) {
        int v = a[i];
        int j=i-1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        arrayPrint(n, a);
    }
}

int main(void) {
    int n;
    int *a = NULL;
    n = arrayScan(a);
    arrayPrint(n, a);
    insertionSort(a, n);
    free(a);
    a = NULL;
    return 0;
}
