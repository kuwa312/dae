#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node {
    int parent;
    int left; // 左の子
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
    int hl = 0;
    int hr = 0;
    if (T[id].left != NIL) {
        hl = set_height(T[id].left) + 1; // 左の子の高さ
    }
    if (T[id].right != NIL) {
        hr = set_height(T[id].right) + 1; // 右の子の高さ
    }
    return H[id] = hl > hr ? hl : hr; // 高さは大きい方を返す
}

int get_sibling(int id) { // 兄弟の接点番号を返す
    if (T[id].parent == NIL) return NIL; // 親がいないときはNILを返す．（自信が根なので兄弟はいない）
    if (T[T[id].parent].left == id) { // idが親の左の子のとき
        return T[T[id].parent].right; // 親の右の子を返す
    } else {
        return T[T[id].parent].left; // 親の左の子を返す
    }
    return NIL; // ここには来ないはず
}


void print(int id) {
    printf("node %d: ", id);
    printf("parent = %d, ", T[id].parent);
    printf("sibling = %d, ", get_sibling(id));
    int deg = 0; // 子の数，0 or 1 or 2
    if (T[id].left != NIL) {
        deg++;
    }
    if (T[id].right != NIL) {
        deg++;
    }
    printf("degree = %d, ", deg);
    printf("depth = %d, ", D[id]);
    printf("height = %d, ", H[id]);

    if (T[id].parent == NIL) { // 親がいない＝根
        printf("root\n"); // 
    } else if (T[id].left == NIL && T[id].right == NIL) { // 子がいない＝葉
        printf("leaf\n");
    } else {
        printf("internal node\n"); // その他＝内部ノード
    }
}

int main(void) {
    int id, l, r, root = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        T[i].parent = NIL;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &id, &l, &r);
        T[id].left = l;
        T[id].right = r;
        if (l != NIL) T[l].parent = id; // 左の子の親はid
        if (r != NIL) T[r].parent = id;
    }

    for ( int i = 0; i < n; i++ ) {
        if (T[i].parent == NIL) {
            root = i;
        }
    }

    set_depth(root, 0); 
    set_height(root);   

    for (int i = 0; i < n; i++) {
        print(i);
    }

    return 0;
}
