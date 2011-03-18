#ifndef RBTREE_H
#define RBTREE_H 1

typedef int RBTree_key_t;
typedef job_t* RBTree_value_t;

typedef struct RBTreeNode {
  public:
typedef enum {RBT_BLACK = 0,RBT_RED}RBTree_Color;


	RBTree_Color color;//red or black.
	RBTree_value_t data;
	RBTree_key_t key;
	struct RBTreeNode *left,*right,*parent;
}RBTree;

RBTree*  InitRBTree(RBTree *node,RBTree_key_t key,RBTree_value_t data);
RBTree* FirstRBTNode(RBTree* tree);
RBTree* insertRBT(RBTree **ptrRoot,RBTree *x);

#endif
