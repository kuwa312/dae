#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node {
    int parent; // 親
    int left; // 左の子
    int right; // 右の子
};

struct Node T[MAX];
int n; // ノード数

// 先行順巡回
void preParse(int id) {
    if (id == NIL) { // 空のノードのとき，何もしない
        return;
    }
    // 自分→左の子（再帰）→右の子（再帰）
    printf(" %d", id); 
    preParse(T[id].left); 
    preParse(T[id].right);
}

// 中間順巡回
void inParse(int id) {
    if (id == NIL) {
        return;
    }
    // 左の子（再帰）→自分→右の子（再帰）
    inParse(T[id].left);
    printf(" %d", id);
    inParse(T[id].right);
}

// 後行順巡回
void postParse(int id) {
    if (id == NIL) {
        return;
    }
    // 左の子（再帰）→右の子（再帰）→自分
    postParse(T[id].left);
    postParse(T[id].right);
    printf(" %d", id);
}

int main(void) {
    int i, id, left, right, root; // rootは根
    scanf("%d", &n);

    // Tの初期化
    for (i=0; i<n; i++) {
        T[i].parent = NIL;
    }

    for (i=0; i<n; i++) {
        scanf("%d %d %d", &id, &left, &right);
        T[id].left = left;
        T[id].right = right;
        if (left != NIL) { // 左の子が存在する時
            T[left].parent = id; // 左の子の親をidにする
        }
        if (right != NIL) { // 右の子が存在する時
            T[right].parent = id; // 右の子の親をidにする
        }
    }

    for (i=0; i<n; i++) {
        if (T[i].parent == NIL) { // 親が存在しない時，そのノードを根にする
            root = i;
        }
    }

    printf("Preorder\n");
    preParse(root);
    printf("\n");
    printf("Inorder\n");
    inParse(root);  
    printf("\n");
    printf("Postorder\n");
    postParse(root);
    printf("\n");
    return 0;
}