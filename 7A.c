#include<stdio.h>

// 次数＝子の数

#define MAX 100005
#define NIL -1

struct Node {
    int parent;
    int left_child;
    int right_bro;
};

struct Node T[MAX];

int get_depth(int id) {
    int depth = 0;
    while (T[id].parent != NIL) {//接点の親がNILでない限り
        id = T[id].parent;
    
        depth ++;
    }
    return depth;
}




// n
// id(接点番号) k(子の次数) c_1 c_2 ... c_k
// id k c_0 c_1 ... c_{k-1}


void print_child(int id) {
    int i, c;
    printf("[");
    for (i=0, c=T[id].left_child; c!=NIL; i++, c=T[c].right_bro) {
        if (i) {printf(", ");}// i=0のとき（先頭の子のとき）は「，」を表示しない
        printf("%d", c);
    }
    printf("]\n");
}


void print(int id) {
    printf("node %d: ", id);
    printf("parent = %d, ", T[id].parent);
    printf("depth = %d, ", get_depth(id));
    if (T[id].parent == NIL) {
        printf("root, ");
    } else if (T[id].left_child == NIL) {
        printf("leaf, ");
    } else {
        printf("internal node, ");
    }
    print_child(id);
}



int main(void) {
    int i, n, id, k, j, c;
    int pre_c = NIL;
    scanf("%d", &n);

    // 初期化
    for (i=0; i<n; i++) {
        T[i].parent = T[i].left_child = T[i].right_bro = NIL;
    }

    // 多分あってる
    for (i=0; i<n; i++) {
        scanf("%d", &id);
        scanf("%d", &k); // K:子の次数
        for (j=0; j<k; j++) { 
            scanf("%d", &c); //c_j
            if (j==0) {// 一つ目の子がleft_child
                T[id].left_child = c;
            } else {
                T[pre_c].right_bro = c;
            }
            T[c].parent = id;
            pre_c = c;
        }
    }    

    for (i=0; i<n; i++) {
        print(i);
    }
    return 0;
}