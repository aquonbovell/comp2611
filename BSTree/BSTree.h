//
//  BSTree.h
//  BST
//
//  Created by Dr. John Charlery on 03/01/2022.
//  Copyright (c) 2023 University of the West Indies. All rights reserved.
//

#ifndef BST_BSTree_h
#define BST_BSTree_h

class BSTNode
{
private:
	int data;
	BSTNode *left;
	BSTNode *right;

public:
	// Constructor functions
	BSTNode()
	{
		right = left = NULL;
		data = -99;
	}
	BSTNode(int val)
	{
		data = val;
		right = left = NULL;
	}

	// Accessor functions
	BSTNode *getLeft() { return left; };
	BSTNode *getRight() { return right; }
	int getData() { return data; }

	// Mutator functions
	void setData(int val) { data = val; }
	void setLeft(BSTNode *ptr) { left = ptr; }
	void setRight(BSTNode *ptr) { right = ptr; }
};

class BSTree
{
private:
	BSTNode *root;

	// Recursive counterpart for inserting a node
	BSTNode *insertHelper(BSTNode *, int);

	// Recursive counterpart for deleting a node
	BSTNode *deleteHelper(BSTNode *, int);

	// Recursive counterpart of preorder traversal
	string preOrderHelper(BSTNode *);

	// Recursive counterpart of postorder traversal
	string postOrderHelper(BSTNode *);

	// Recursive counterpart of inorder traversal
	string inOrderHelper(BSTNode *);

public:
	//  Constructor function
	BSTree() { root = NULL; }

	// Mutator functions
	void purge() { root = NULL; }
	void insert(int val) { root = insertHelper(root, val); }
	void remove(int val) { root = deleteHelper(root, val); }

	// Accessor functions
	BSTNode *getRoot() { return root; }
	string preOrder() { return preOrderHelper(root); }
	string postOrder() { return postOrderHelper(root); }
	string inOrder() { return inOrderHelper(root); }
};

BSTNode *BSTree::insertHelper(BSTNode *ptr, int val)
{
	if (ptr == NULL) // The tree is empty - new first node!
	{
		ptr = new BSTNode(val);
	}
	else // choose which sub-tree to follow
	{
		if (val >= ptr->getData()) // insert in right subtree - Operational defn.
			ptr->setRight(insertHelper(ptr->getRight(), val));
		else // insert in left subtree
			ptr->setLeft(insertHelper(ptr->getLeft(), val));
	}
	return ptr;
}

BSTNode *BSTree::deleteHelper(BSTNode *ptr, int val)
{
	BSTNode *successor;

	// Base condition
	if (ptr == NULL)
	{
		return NULL;
	}

	if (val > ptr->getData()) // Search for val in right sub-tree
		ptr->setRight(deleteHelper(ptr->getRight(), val));

	else if (val < ptr->getData()) // Search for val in left sub-tree
		ptr->setLeft(deleteHelper(ptr->getLeft(), val));

	else // Found it! ptr is the node to be deleted
	{
		if (ptr->getRight() != NULL)
		{																			 // Seek out the succesor in the right sub-tree
			successor = ptr->getRight();				 // Go right...
			while (successor->getLeft() != NULL) // ...and then go deep left
				successor = successor->getLeft();

			// Transfer data from successor to ptr (ptr is the node to be deleted)
			ptr->setData(successor->getData());

			// Now reset ptr's right child
			ptr->setRight(deleteHelper(ptr->getRight(), ptr->getData()));
		}
		else
			return (ptr->getLeft());
	}
	return ptr;
}

string BSTree::inOrderHelper(BSTNode *ptr)
{
	string str = "";

	if (ptr != NULL)
	{
		str.append(inOrderHelper(ptr->getLeft()));

		str.append(to_string(ptr->getData()));
		str.append("  ");

		str.append(inOrderHelper(ptr->getRight()));
	}
	return str;
}

string BSTree::preOrderHelper(BSTNode *ptr)
{
	string str = "";

	if (ptr != NULL)
	{
		str.append(to_string(ptr->getData()));
		str.append("  ");

		str.append(preOrderHelper(ptr->getLeft()));
		str.append(preOrderHelper(ptr->getRight()));
	}
	return str;
}

string BSTree::postOrderHelper(BSTNode *ptr)
{
	string str = "";

	if (ptr != NULL)
	{
		str.append(postOrderHelper(ptr->getLeft()));
		str.append(postOrderHelper(ptr->getRight()));

		str.append(to_string(ptr->getData()));
		str.append("  ");
	}
	return str;
}

#endif
