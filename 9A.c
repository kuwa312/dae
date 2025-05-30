#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

int parent(int i) {
    return i/2;
}

int left(int i) {
    return i*2;
}

int right(int i) {
    return i*2 + 1;
}

int main() {
    int i;
    int n; // ノード数
    int A[MAX+1]; // 1オリジンのために+1

    scanf("%d", &n);

    for (i=1; i<=n; i++) {
        scanf("%d", &A[i]);
    }

    for (i=1; i<=n; i++) {
        printf("node %d: ", i);
        printf("key = %d, ", A[i]);
        if (parent(i) >= 1) {
            printf("parent key = %d, ", A[parent(i)]);
        }
        if (left(i) <= n) {
            printf("left key = %d, ", A[left(i)]);
        }
        if (right(i) <= n) {
            printf("right key = %d, ", A[right(i)]);
        }
        printf("\n");
    }
    
    return 0;
}