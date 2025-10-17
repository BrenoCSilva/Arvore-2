#ifndef _arvore_
#define _arvore_

// ponteiros de funcoes

typedef int (*CmpFn)(void *, void *);


/// classes 


typedef struct BinaryTree BinaryTree;
typedef struct NodeTree NodeTree;


NodeTree* node_create(void *key, void *val);

BinaryTree* binary_tree_construct(CmpFn cmp);

void binary_tree_add(BinaryTree *tree, void *key, void *val);


void PrintSorted(BinaryTree *bt, void (*function_print)(void *data));

void printInOrderAux(NodeTree *node, void (*function_print)(void *data));


#endif