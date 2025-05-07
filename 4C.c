#include<stdio.h>
#include<string.h>

#define M 1000000
#define L 14

char H[M][L]; //hash table [1000000][14]

// 文字列to数値
int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
}

// 文字列toKey
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){ return key % M; }
int h2(int key){ return 1 + (key % (M-1)); }
int h(int key, int i) {
    return (h1(key)+i*h2(key)) % M;
}

int find(char str[]){//存在しない0,存在1を返す
    long long key, i, h;
    key = getKey(str);
    for (i=0; ; i++) {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[h], str) == 0) return 1;
        else if (strlen(H[h]) == 0) return 0;//空
    }
    return 0;//理論上到達しない
}

int insert(char str[]){// 既に存在1を返す、空0を返す
    long long i, key, h;
    key = getKey(str);
    for (i=0; ; i++) { //常にTrue
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[h], str) == 0) {//hast tableに同じ値が存在
            return 1;
        } else if (strlen(H[h]) == 0) {//hash tableが空
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;//理論上到達しない
}

int main(){
    int i, n, h;
    char str[L], com[9];
    for ( i = 0; i < M; i++ ) H[i][0] = '\0';
    
    scanf("%d", &n);
    
    for ( i = 0; i < n; i++ ){
	scanf("%s %s", com, str);
	
	if ( com[0] == 'i' ){
	    insert(str);
	} else {
	    if (find(str)){
		printf("yes\n");
	    } else {
		printf("no\n");
	    }
	}
    }

    return 0;
}

