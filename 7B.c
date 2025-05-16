#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node {
    int parent;
    int left;//左の子
    int right;
};

struct Node T[MAX];
int n, D[MAX], H[MAX]; 


void set_depth(int id, int depth) { 
    if (id == NIL) return; // idがNILのときは何もしない
    D[id] = depth;
    set_depth(T[id].left, depth + 1); // 子のdepthは親のdepth+1
    set_depth(T[id].right, depth + 1); 
}

int set_height(int id) {
    int 
}

int main(void) {
    return 0;
}

// int get_depth(int id) {
//     int depth = 0;
//     while (T[id].parent != NIL) {//接点の親がNILでない限り
//         id = T[id].parent;
//         depth ++;
//     }
//     return depth;
// }



// n
// id(接点番号) k(子の次数) c_1 c_2 ... c_k
// id k c_0 c_1 ... c_{k-1}


// void print_child(int id) {
//     printf("[");
//     if (T[id].left_child != NIL) {
//         printf("]\n");
//         return;
//     }
//     printf("%d",T[id].left_child);
//     int c = T[id].left_child;
//     while(T[c].right_bro != NIL) {
//         c = T[c].right_bro;
//         printf(",%d", c);
//     }
//     printf("]\n");

// }


// void print(int id) {
//     printf("node %d: ", id);
//     printf("parent = %d, ", T[id].parent);
//     printf("depth = %d, ", get_depth(id));
//     if (T[id].parent == NIL) {
//         printf("root, ");
//     } else if (T[id].left_child == NIL) {
//         printf("leaf, ");
//     } else {
//         printf("internal node, ");
//     }
//     print_child(id);
// }



// int main(void) {
//     int i, n, id, k, j, c;
//     int pre_c = NIL;
//     scanf("%d", &n);
//     // 初期化
//     for (i=0; i<n; i++) {
//         T[i].parent = T[i].left_child = T[i].right_bro = NIL;
//     }

//     for (i=0; i<n; i++) {
//         scanf("%d", &id);
//         scanf("%d", &k);
//         for (j=0; j<k; j++) { 
//             scanf("%d", &c); //c_j
//             if (j==0) {// 一つ目の子がleft_child
//                 T[id].left_child = c;
//             } else {
//                 T[pre_c].right_bro = c;
//             }
//             T[c].parent = id;
//             pre_c = c;
//         }
//     }    

//     for (i=0; i<n; i++) {
//         print(i);
//     }
//     return 0;
// }