/**
 * 
 * This file is part of libdnstd, a C++ utility library
 * This may be downloaded at http://libdnstd.davecoss.com
 * 
 * Copyright 2007, 2010 David Coss, PhD
 *
 * libdnstd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libdnstd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with libdnstd.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RBTREE_H
#define RBTREE_H 1

namespace utils{
typedef enum {RBT_BLACK = 0,RBT_RED}RBTree_Color;
template <typename value_t>
class RBTree {
  public:
  RBTree():left(0),right(0),parent(0){}
    RBTree(const value_t& val) : left(0),right(0),parent(0),data(val){}
 typedef value_t value_type;

	RBTree_Color color;//red or black.
	value_type data;
	RBTree<value_t> *left,*right,*parent;
};
}

template <typename value_t>
utils::RBTree<value_t>*  InitRBTree(utils::RBTree<value_t> *node,value_t data)
{
	if(node == NULL)
	  node = (utils::RBTree<value_t>*)malloc(sizeof(utils::RBTree<value_t>));
	node->data = data;
	node->left = node->parent = node->right = NULL;
	node->color = utils::RBT_BLACK;
	return node;
}

template <typename value_t>
utils::RBTree<value_t>* RightRotate(utils::RBTree<value_t> *tree)
{
	utils::RBTree<value_t> *left, *right;
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


template <typename value_t>
 utils::RBTree<value_t>* LeftRotate(utils::RBTree<value_t> *tree)
{
	utils::RBTree<value_t> *left, *right;
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


template <typename value_t>
short RBTDirection(const utils::RBTree<value_t> *lhs, value_t rhs)
{
	if(lhs->data > rhs)
		return -1;
	if(lhs->data < rhs)
		return 1;
	return 0;
}

template <typename value_t>
void insertBST(utils::RBTree<value_t> *rootnode,utils::RBTree<value_t> *x)
{
	int direction;
	if(rootnode == NULL)
	{
		rootnode = x;
		x->parent = NULL;
		return;
	}

	direction = RBTDirection(rootnode,x->data);
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
template <typename value_t>
utils::RBTree<value_t>* insertRBT(utils::RBTree<value_t> **ptrRoot,utils::RBTree<value_t> *x)
{
  using utils::RBTree;
	int direction;
	RBTree<value_t> *root = *ptrRoot;
	insertBST(root,x);
	if(root == NULL || root == x)
	{
		x->color = utils::RBT_BLACK;
		*ptrRoot = x;
		return x;
	}
	x->color = utils::RBT_RED;
	while(x != root && x->parent->color == utils::RBT_RED)
	{
		if(x->parent == x->parent->parent->left)
		{
			RBTree<value_t> *uncle = x->parent->parent->right;
			if(uncle != NULL && uncle->color == utils::RBT_RED)
			{
				x->parent->color = uncle->color = utils::RBT_BLACK;
				x->parent->parent->color = utils::RBT_RED;
				x = x->parent->parent;
			}
			else
			{
				if(x == x->parent->right)
				{
					x = x->parent;
					LeftRotate(x);
				}
				x->parent->color = utils::RBT_BLACK;
				x->parent->parent->color = utils::RBT_RED;
				RightRotate(x->parent->parent);
			}
		}
		else
		{
			RBTree<value_t> *uncle = x->parent->parent->left;
			if(uncle != NULL && uncle->color == utils::RBT_RED)
			{
				x->parent->color = uncle->color = utils::RBT_BLACK;
				x->parent->parent->color = utils::RBT_RED;
				x = x->parent->parent;
			}
			else
			{
				if(x == x->parent->left)
				{
					x = x->parent;
					RightRotate(x);
				}
				x->parent->color = utils::RBT_BLACK;
				x->parent->parent->color = utils::RBT_RED;
				LeftRotate(x->parent->parent);
			}
		}
	}

	//Make sure the real root of the tree is black
	while(root->parent != NULL)
		root = root->parent;
	root->color = utils::RBT_BLACK;
	*ptrRoot = root;
	return root;
}

template <typename value_t>
utils::RBTree<value_t>* FindRBTNode(utils::RBTree<value_t> *tree, value_t key)
{
	short direction;
	if(tree == NULL)
		return NULL;

	direction = RBTDirection(tree,key);
	if(direction == 0)
		return tree;
	if(direction > 0)
		return FindRBTNode(tree->right,key);

	return FindRBTNode(tree->left,key);
}

template <typename value_t>
utils::RBTree<value_t>* RBTSuccessor(utils::RBTree<value_t> *node)
{
	utils::RBTree<value_t> *temp;
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

template <typename value_t>
int RBTIsBlack(utils::RBTree<value_t> *node)
{
	return node == NULL || node->color == utils::RBT_BLACK;
}

template <typename value_t>
void CleanRBT(utils::RBTree<value_t> *root, utils::RBTree<value_t> *node)
{
	if(node == NULL || root == NULL)
		return;

	while(node->color == utils::RBT_BLACK && node != root)
	{
		if(node == node->parent->left)
		{
		  utils::RBTree<value_t> *sibling = node->parent->right;
			if(sibling->color == utils::RBT_RED)
			{
				sibling->color = utils::RBT_BLACK;
				node->parent->color = utils::RBT_RED;
				LeftRotate(node->parent);
				sibling = node->parent->right;
			}
			if(RBTIsBlack(sibling->right) && RBTIsBlack(sibling->left))
			{
				sibling->color = utils::RBT_RED;
				node = node->parent;
			}
			else
			{
				if(RBTIsBlack(sibling->right))
				{
					sibling->left->color = utils::RBT_BLACK;
					sibling->color = utils::RBT_RED;
					RightRotate(sibling);
					sibling = node->parent->right;
				}
				sibling->color = node->parent->color;
				node->parent->color = sibling->right->color = utils::RBT_BLACK;
				LeftRotate(node->parent);
				node = root;
			}
		}
		else
		{
			utils::RBTree<value_t> *sibling = node->parent->left;
			if(sibling->color == utils::RBT_RED)
			{
				sibling->color = utils::RBT_BLACK;
				node->parent->color = utils::RBT_RED;
				RightRotate(node->parent);
				sibling = node->parent->left;
			}
			if(RBTIsBlack(sibling->right) && RBTIsBlack(sibling->left))
			{
				sibling->color = utils::RBT_RED;
				node = node->parent;
			}
			else
			{
				if(RBTIsBlack(sibling->left))
				{
					sibling->right->color = utils::RBT_BLACK;
					sibling->color = utils::RBT_RED;
					LeftRotate(sibling);
					sibling = node->parent->left;
				}
				sibling->color = node->parent->color;
				node->parent->color = sibling->left->color = utils::RBT_BLACK;
				RightRotate(node->parent);
				node = root;
			}
		}
	}
	node->color = utils::RBT_BLACK;
	if(root->parent != 0)
	{
		root = node;
		while(root->parent != 0)
			root = root->parent;
		root->color = utils::RBT_BLACK;
	}

}

/**
 * Will remove node from the tree. The node is
 * then returned, so that it can be freed from
 * memory or used in some other manner.
 */
template <typename value_t>
utils::RBTree<value_t>* removeRBT(utils::RBTree<value_t> **tree, utils::RBTree<value_t> *node)
{
	utils::RBTree<value_t> *x,*y, *sentinal = 0, *root = *tree;

	if(*tree == node && node->left == NULL && node->right == NULL)//Is this node the only node in the tree.
	{
		*tree = NULL;
		return node;
	}

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
	  sentinal = (utils::RBTree<value_t>*)malloc(sizeof(utils::RBTree<value_t>));
		sentinal->left = sentinal->right = NULL;
		sentinal->color = utils::RBT_BLACK;
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
		if(y->color == utils::RBT_BLACK)
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
		if(y->color == utils::RBT_BLACK)
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


template <typename value_t>
int CountNodes(const utils::RBTree<value_t> *tree)
{
	if(tree == NULL)
		return 0;

	return 1 + CountNodes(tree->left) + CountNodes(tree->right);
}

template <typename value_t>
utils::RBTree<value_t>* FirstRBTNode(utils::RBTree<value_t>* tree)
{
	if(tree == NULL || tree->left == NULL)
		return tree;
	return FirstRBTNode(tree->left);
}

template <typename value_t>
utils::RBTree<value_t>* LastRBTNode(utils::RBTree<value_t> *tree)
{
	if(tree == NULL || tree->right == NULL)
		return tree;
	return FirstRBTNode(tree->right);
}

#endif
