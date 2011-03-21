#ifndef RBTREE_H
#define RBTREE_H 1

template class<typename value_t > {
  public:
typedef enum {RBT_BLACK = 0,RBT_RED}RBTree_Color;
 typedef value_t value_type;

  RBTree();
  RBTree(value_type data);

  RBTree* root()const;
  RBTree* begin()const;
  RBTree* end()const;{return NULL;}
  RBTree* insert(RBTree *x);
  RBTree* find(const value_type key);
  RBTree* remove(RBTree *node);
  size_t size()const;
  
  value_type data;
  RBTree *left,*right,*parent;

 private:
  static short RBTDirection(const RBTree *lhs, value_type rhs);
  static RBTree* RightRotate(RBTree *tree);
  static RBTree* LeftRotate(RBTree *tree);
  static void insertBST(RBTree *rootnode, RBTree *x);
  static RBTree* RBTSuccessor(RBTree *node);
  static int RBTIsBlack(RBTree *node);
  static void CleanRBT(RBTree *root, RBTree *node);

};

template<typename value_t> 
RBTree<value_t>*  InitRBTree(RBTree<value_t> *node,value_t data)
{
	if(node == NULL)
		node = (RBTree<value_t>*)malloc(sizeof(RBTree<value_t>));
	node->key = key;
	node->data = data;
	node->left = node->parent = node->right = NULL;
	node->color = RBT_BLACK;
	
	return node;
}

template<typename value_t> 
RBTree<value_t>* RBTree<value_t>::RightRotate(RBTree<value_t> *tree)
{
	RBTree<value_t> *left, *right;
	if(tree == NULL)
		return NULL;;
	if(tree->left == NULL)
		return NULL;;

	//Rotate
	left = tree->left;
	right = left->right;
	left->right = tree;
	tree->left = right;

	//Update parenthood
	left->parent = tree->parent;
	if(tree->parent != NULL)//double-check that tree is not a root
	{
		if(tree->parent->left == tree)
			tree->parent->left = left;
		else
			tree->parent->right = left;
	}

	tree->parent = left;
	if(right != NULL)
		right->parent = tree;
	return left;
}

template<typename value_t> 
RBTree<value_t>* RBTree<value_t>::LeftRotate(RBTree<value_t> *tree)
{
	RBTree<value_t> *left, *right;
	if(tree == NULL)
		return NULL;
	if(tree->right == NULL)
		return NULL;

	//Rotate
	right = tree->right;
	left = right->left;
	tree->right = left;
	right->left = tree;

	//Update parenthood
	right->parent = tree->parent;
	if(tree->parent != NULL)//double-check that tree is not a root
		if(tree->parent != NULL)
		{
			if(tree->parent->left == tree)
				tree->parent->left = right;
			else
				tree->parent->right = right;
		}
	tree->parent = right;
	if(left != NULL)
		left->parent = tree;
	return right;
}

template<typename value_t>
short RBTree<value_t>::RBTDirection(const RBTree<value_t> *lhs, RBTree_key_t rhs)
{
	if(lhs->key > rhs)
		return -1;
	if(lhs->key < rhs)
		return 1;
	return 0;
}

template<typename value_t> 
void RBTree<value_t>::insertBST(RBTree<value_t> * rootnode, RBTree<value_t> *x)
{
	int direction;
	if(rootnode == NULL)
	{
		rootnode = x;
		x->parent = NULL;
		return;
	}

	direction = RBTDirection(rootnode,x->key);
	if(direction < 0)//goes to the left
	{
		if(rootnode->left == NULL)
		{
			rootnode->left = x;
			x->parent = rootnode;
			return;
		}
		return insertBST(rootnode->left,x);
	}
	else if(direction > 0)//goes to the right
	{
		if(rootnode->right == NULL)
		{
			rootnode->right = x;
			x->parent = rootnode;
			return;
		}
		return insertBST(rootnode->right,x);
	}
}

/**
 * Inserts x into the Red-Black tree, whose root pointer
 * is located in rootaddr.
 *
 * Returns: new root node
 */
template<typename value_t> 
RBTree<value_t>* RBTree<value_t>::insert(RBTree<value_t> *x)
{
	int direction;
	RBTree<value_t>* root;
	insertBST(this,x);
	if(this == x)
	{
		return x;
	}
	root = this;
	x->color = RBT_RED;
	while(x != root && x->parent->color == RBT_RED)
	{
		if(x->parent == x->parent->parent->left)
		{
			RBTree *uncle = x->parent->parent->right;
			if(uncle != NULL && uncle->color == RBT_RED)
			{
				x->parent->color = uncle->color = RBT_BLACK;
				x->parent->parent->color = RBT_RED;
				x = x->parent->parent;
			}
			else
			{
				if(x == x->parent->right)
				{
					x = x->parent;
					LeftRotate(x);
				}
				x->parent->color = RBT_BLACK;
				x->parent->parent->color = RBT_RED;
				RightRotate(x->parent->parent);
			}
		}
		else
		{
			RBTree<value_t> *uncle = x->parent->parent->left;
			if(uncle != NULL && uncle->color == RBT_RED)
			{
				x->parent->color = uncle->color = RBT_BLACK;
				x->parent->parent->color = RBT_RED;
				x = x->parent->parent;
			}
			else
			{
				if(x == x->parent->left)
				{
					x = x->parent;
					RightRotate(x);
				}
				x->parent->color = RBT_BLACK;
				x->parent->parent->color = RBT_RED;
				LeftRotate(x->parent->parent);
			}
		}
	}

	//Make sure the real root of the tree is black
	while(root->parent != NULL)
		root = root->parent;
	root->color = RBT_BLACK;
	*ptrRoot = root;
	return root;
}

template<typename value_t> 
RBTree<value_t>* find(const value_t& key)
{
	short direction;
	if(tree == NULL)
		return NULL;

	direction = RBTDirection(tree,key);
	if(direction == 0)
		return tree;
	if(direction > 0)
		return find(tree->right,key);

	return find(tree->left,key);
}

template<typename value_t> 
RBTree<value_t>* RBTree<value_t>::RBTSuccessor(RBTree<value_t> *node)
{
	RBTree<value_t> *temp;
	if(node == NULL)
		return NULL;
	temp = node->right;

	//If the node is already a right most child node,
	//move up the tree and to the right.
	if(temp == NULL)
	{
		if(node->parent == NULL)//If node is root, then it has no successor
			return NULL;
		temp = node->parent;
		while(temp->right == node)
		{
			node = temp;
			temp = temp->parent;
		}
		if(temp->parent == NULL)
			return NULL;
		return temp;
	}

	//If the node has right-children,
	//find the left most right child.
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

template<typename value_t>
int RBTree<value_t>::RBTIsBlack(RBTree<value_t> *node)
{
	return node == NULL || node->color == RBT_BLACK;
}

template<typename value_t>
void RBTree<value_t>::CleanRBT(RBTree<value_t> *root, RBTree<value_t> *node)
{
	if(node == NULL || root == NULL)
		return;

	while(node->color == RBT_BLACK && node != root)
	{
		if(node == node->parent->left)
		{
			RBTree *sibling = node->parent->right;
			if(sibling->color == RBT_RED)
			{
				sibling->color = RBT_BLACK;
				node->parent->color = RBT_RED;
				LeftRotate(node->parent);
				sibling = node->parent->right;
			}
			if(RBTIsBlack(sibling->right) && RBTIsBlack(sibling->left))
			{
				sibling->color = RBT_RED;
				node = node->parent;
			}
			else
			{
				if(RBTIsBlack(sibling->right))
				{
					sibling->left->color = RBT_BLACK;
					sibling->color = RBT_RED;
					RightRotate(sibling);
					sibling = node->parent->right;
				}
				sibling->color = node->parent->color;
				node->parent->color = sibling->right->color = RBT_BLACK;
				LeftRotate(node->parent);
				node = root;
			}
		}
		else
		{
			RBTree *sibling = node->parent->left;
			if(sibling->color == RBT_RED)
			{
				sibling->color = RBT_BLACK;
				node->parent->color = RBT_RED;
				RightRotate(node->parent);
				sibling = node->parent->left;
			}
			if(RBTIsBlack(sibling->right) && RBTIsBlack(sibling->left))
			{
				sibling->color = RBT_RED;
				node = node->parent;
			}
			else
			{
				if(RBTIsBlack(sibling->left))
				{
					sibling->right->color = RBT_BLACK;
					sibling->color = RBT_RED;
					LeftRotate(sibling);
					sibling = node->parent->left;
				}
				sibling->color = node->parent->color;
				node->parent->color = sibling->left->color = RBT_BLACK;
				RightRotate(node->parent);
				node = root;
			}
		}
	}
	node->color = RBT_BLACK;
	if(root->parent != 0)
	{
		root = node;
		while(root->parent != 0)
			root = root->parent;
		root->color = RBT_BLACK;
	}

}

/**
 * Will remove node from the tree. The node is
 * then returned, so that it can be freed from
 * memory or used in some other manner.
 */
template<typename value_t> 
RBTree<value_t>* RBTree<value_t>::remove(RBTree<value_t> *node)
{
	RBTree<value_t> *x,*y, *sentinal = 0, *root = *tree;

	if(this == node && node->left == NULL && node->right == NULL)//Is this node the only node in the tree.
		return node;

	if(node->left == NULL || node->right == NULL)
		y = node;
	else
		y = RBTSuccessor(node);

	if(y->left == NULL)
		x = y->right;
	else
		x = y->left;


	if(x == NULL)
	{
		sentinal = (RBTree*)malloc(sizeof(RBTree));
		sentinal->left = sentinal->right = NULL;
		sentinal->color = RBT_BLACK;
		x = sentinal;
	}
	x->parent = y->parent;

	/*if(root == y->parent)
	{
		root->left = x;
	}
	else */if(y->parent != NULL)
	{
		if(y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	if(y != node)
	{
		if(y->color == RBT_BLACK)
			CleanRBT(root,x);
		y->left = node->left;
		y->right = node->right;
		y->parent = node->parent;
		y->color = node->color;
		if(node->left != NULL)
			node->left->parent = y;
		if(node->right != NULL)
			node->right->parent = y;
		if(node->parent != NULL)
		{
			if(node == node->parent->left)
				node->parent->left = y;
			else
				node->parent->right = y;
		}
	}
	else
		if(y->color == RBT_BLACK)
			CleanRBT(root,x);

	//Ensure tree still holds the root node address.
	root = x;
	while(root->parent != NULL)
		root = root->parent;
	*tree = root;

	//For the purposes of cleaning the RB Tree, a dummy sentinal node
	//may be used for x. If this is the case, x should be a null pointer
	if(x == sentinal)
	{
		if(x == x->parent->left)
			x->parent->left = 0;
		if(x == x->parent->right)
			x->parent->right = 0;
	}
	if(sentinal != NULL)
		free(sentinal);

	return node;
}


template<typename value_t> 
size_t RBTree<value_t>::size()const
{
  size_t returnMe = 1;
  if(tree->left)
    returnMe += tree->left.size();
  if(tree->right)
    returnMe += tree->right.size();
  return returnMe;
}

template<typename value_t> 
RBTree<value_t>* RBTree<value_t>::begin()
{
	if(this->left == NULL)
		return this;
	return this->left.begin();
}

template<typename value_t> 
RBTree<value_t>* RBTree<value_t>::root()
{
  RBTree<value_t> *root = this;
  while(root->parent != NULL)
    root = root->parent;
  return root;
}

template<typename value_t> 
RBTree<value_t>::RBTree()
{
  value_type temp;
  InitRBTree(this,temp);
}

template<typename value_t> 
RBTree<value_t>::RBTree(value_t data)
{
  InitRBTree(this,data);
}



#endif
