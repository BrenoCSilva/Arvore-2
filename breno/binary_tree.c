#include <stdlib.h>
#include "binary_tree.h"

struct NodeTree{

    void *val;
    void *key;
    struct NodeTree *left;
    struct NodeTree *right;

};

NodeTree* node_create(void *key, void *val){

    NodeTree *no = (NodeTree*) calloc (1, sizeof(NodeTree));

    //teste de sanidade

    no->key = key;
    no->val = val;
    no->left = NULL;
    no->right = NULL;

    return no;
}


struct BinaryTree{

    NodeTree *root;
    CmpFn function_compare;

    // funcoes para desalocar chave e valor

};

BinaryTree* binary_tree_construct(CmpFn cmp){

    BinaryTree *tree = (BinaryTree*) malloc (sizeof(BinaryTree));

    //teste de sanidade

    tree->root = NULL;
    tree->function_compare = cmp;

    return tree;
}

static NodeTree* binary_tree_add_recursive(BinaryTree *tree, NodeTree *root , void *key, void *val){

    // verificar se a arvore esta vazia
    if(root == NULL){
        return node_create(key,val);
    }


    // verificar atraves da funcao de comparacao se a chave atual esta a esquerda ou a direta da raiz

    int resultado = tree->function_compare(key, root->key);


    if(resultado > 0){

        root->right = binary_tree_add_recursive(tree, root->right, key, val);
    }

    else if (resultado < 0){

         root->left = binary_tree_add_recursive(tree, root->left, key, val);
    }

    else{

        // tem que destruir porque o nó já existe
    }

    return root;

}

void binary_tree_add(BinaryTree *tree, void *key, void *val){


    tree->root = binary_tree_add_recursive(tree, tree->root, key, val);
}


void printInOrderAux(NodeTree *node, void (*function_print)(void *data)) {
    if (node == NULL) return;

    printInOrderAux(node->left, function_print);
    function_print(node->val);
    printInOrderAux(node->right, function_print);
}

void PrintSorted(BinaryTree *bt, void (*function_print)(void *data)) {
    printInOrderAux(bt->root, function_print);
}