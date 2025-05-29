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

Node getMinimum(Node node){ //接点nodeを根とする部分木の中で最小のキーを持つ接点を返す
    while (node->left != NIL) { // 左の子が存在する限り
        node = node->left; // 左の子に移動
    }
    return node; 
}

void treeDelete(Node node) {
    Node delNode; // 削除するノード
    Node childNode; // delNodeの親の子となるノード

    if (node->left == NIL || node->right == NIL) { // nodeが葉 or 1つの子をもつ
        delNode = node;
    } else { // 2つの子をもつ
        delNode = treeSuccessor(node); // delNodeはnodeの次接点
        }
    // childNodeを設定
    if (delNode->left != NIL) { // 左の子が存在する場合
        childNode = delNode->left; // childNodeは左の子
    } else { // 左の子が存在しない場合
        childNode = delNode->right; // childNodeは右の子
    }

    if (childNode != NIL) { // childNodeが存在する場合つまり，delNodeが子をもつとき
        childNode->parent = delNode->parent; // childNodeの親をdelNodeの親に設定
    }
    if (delNode->parent == NIL) { // delNodeが根の場合
        root = childNode; // 根をchildNodeに更新
    } else if (delNode == delNode->parent->left) { // delNodeが親の左の子の場合
        delNode->parent->left = childNode; // 親の左の子をchildNodeに更新
    } else { // delNodeが親の右の子の場合
        delNode->parent->right = childNode; // 親の右の子をchildNodeに更新
    }

    if (delNode != node) { 
        node->key = delNode->key; 
    }

}

Node find(Node node, int key) {
    while(node != NIL && key != node->key) {
        if (key < node->key) {
            node = node->left; // 左を探索
        } else {
            node = node->right; // 右を探索
        }
    }
    return node; // もし，keyが存在しないときは，NILを返す
}

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
    char cmd[10];
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
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
        } else if (cmd[0] == 'f') { // 1文字目がf，つまりfind
            int key;
            scanf("%d", &key);
            if (find(root, key) != NIL) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (cmd[0] == 'd') { // 1文字目がd，つまりdelete
            int key;
            scanf("%d", &key);
            Node nodeToDelete = find(root, key); // 削除するノードを探す
            if (nodeToDelete != NIL) {
                treeDelete(nodeToDelete); 
            } else {
                printf("no\n"); // ノードが見つからない場合
            }
        }                                               
        
    }
    return 0;
}