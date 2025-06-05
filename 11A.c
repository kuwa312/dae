#include <stdio.h>
#include <stdlib.h>
#define N 100

int main() {
	int n, u, k, v;
	int M[N][N]; // 隣接行列

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = 0;
		}
	}

	for (int i=0; i<n; i++) {
		scanf("%d %d", &u, &k); // u:接点番号,k:出次数
		u--; // 0オリジンに変換
		for (int j=0; j<k; j++) {
			scanf("%d", &v); // v:連節頂点の接点番号
			v--; // 0オリジンに変換
			M[u][v] = 1;
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (j) printf(" "); // 先頭のみ空白無し
			printf("%d", M[i][j]);
		}
		printf("\n");
	}
	return 0;
}