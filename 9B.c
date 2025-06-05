#include<stdio.h>
#define MAX 2000000

int parent(int i) {
    return i/2;
}

int left(int i) {
    return i*2;
}

int right(int i) {
    return i*2 + 1;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapify(int* A, int n, int i) {
    int l, r, largest;
    l = left(i);
    r = right(i);

    if (l<=n && A[l]>A[i]) { // 左の子が存在．かつ，左の子が自分より大きい
        largest = l;
    } else {
        largest = i;
    }
    if (r<=n && A[r]>A[largest]) { // 右の子が存在．かつ，largestより大きい
        largest = r;
    }

    if (largest != i) { // iの子の方が大きいとき
        swap(&A[i], &A[largest]);
        maxHeapify(A, n, largest); // 入れ替えた子に対して，再帰呼び出し
    }   
}

void buildMaxHeap(int* A, int n) {
    int i;
    for (i=n/2; i>=1; i--) { // 葉を除く最下位層から実行
        maxHeapify(A, n, i); 
    }
}

int main(void) {
    int i, n;
    int A[MAX+1];

    scanf("%d", &n);

    for (i=1; i<=n; i++) {
        scanf("%d", &A[i]);
    }

    buildMaxHeap(A, n);

    for (i=1; i<=n; i++) {
        printf("%d ", A[i]);
    }
}

