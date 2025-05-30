#include<stdio.h>
#define MAX_N 100


int arrayScan(int *a) //整数ｎ，ｎ個のデータをスキャン，ｎを返す
{
    int n;
    int i;
    scanf("%d", &n);
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
        while (j >= 0&& a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        arrayPrint(n, a);

    }

}

int main(void) {
    int n;
    int a[MAX_N];
    n = arrayScan(a);
    arrayPrint(n, a);
    insertionSort(a, n);
    return 0;
}