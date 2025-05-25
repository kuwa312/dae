#include<stdio.h>
#include<stdlib.h>
#define NIL NULL

struct node {
    struct node *left;
    struct node *right;
    struct node *parent;
    int key;
};

typedef struct node * Node; //Nodeはnodeへのポインタ型

Node root; //rootは根へのポインタ

void insert(int key) {
    Node parentNode = NIL; //挿入位置の親
    Node currentNode = root; //探索中の現在のノード
    Node newNode; // 挿入する新しいノード

    newNode = (Node)malloc(sizeof(struct node)); // 新しいノードのメモリを確保
    newNode->key = key; 
    newNode->left = NIL;// 新しいノードの左の子はNIL
    newNode->right = NIL;

    while(currentNode != NIL) { //currentNodeを挿入位置まで移動
        parentNode = currentNode;
        if (newNode->key < currentNode->key) { 
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    newNode->parent = parentNode; // 親ノードを設定
    if (parentNode == NIL) { // 親が存在しないとき，つまり木が空のとき
        root = newNode; // 新しいノードを根に設定
    } else if (newNode->key < parentNode->key) { // 左の子として挿入
        parentNode->left = newNode;
    } else { // 右の子として挿入
        parentNode->right = newNode;
    }
}

// 中間順巡回でprint
void printInorder(Node node) {
    if (node == NIL) return; // 空のノードのとき，何もしない
    // 左の子（再帰）→自分→右の子（再帰）
    printInorder(node->left); 
    printf(" %d", node->key);
    printInorder(node->right);
}

// 先行順巡回でprint
void printPreorder(Node node) {
    if (node == NIL) return; // 空のノードのとき，何もしない
    // 自分→左の子（再帰）→右の子（再帰）
    printf(" %d", node->key);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main (void) {
    int i;
    int n; // ノード数
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        char cmd[10];
        scanf("%s", cmd);
        if (cmd[0] == 'i') { //1文字目がi，つまりinsert
            int key;
            scanf("%d", &key);
            insert(key); 
        } else if (cmd[0] == 'p') { // 1文字目がp，つまりprint
            printInorder(root); // 中間順巡回
            printf("\n");
            printPreorder(root); // 先行順巡回
            printf("\n");
        }
        
    }
    return 0;
}