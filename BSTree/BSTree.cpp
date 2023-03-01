//
//  BSTree.cpp
//  BST
//
//  Created by Dr. John Charlery on 03/01/2023.
//  Copyright (c) 2023 University of the West Indies. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "BSTree.h"
#include "VisualizeTree.h"

int main()
{
	BSTree *bst = new BSTree();

	// Display the tree
	cout << displayTree(bst) << "\n\n";

	cout << "After 6 is inserted in the tree:\n";
	bst->insert(6);
	cout << displayTree(bst) << "\n\n";

	cout << "After 9 is inserted in the tree:\n";
	bst->insert(9);
	cout << displayTree(bst) << "\n\n";

	cout << "After 4 is inserted in the tree:\n";
	bst->insert(4);
	cout << displayTree(bst) << "\n\n";

	cout << "After 2 is inserted in the tree:\n";
	bst->insert(2);
	cout << displayTree(bst) << "\n\n";

	cout << "After 7 is inserted in the tree:\n";
	bst->insert(7);
	cout << displayTree(bst) << "\n\n";

	cout << "After 8 is inserted in the tree:\n";
	bst->insert(8);
	cout << displayTree(bst) << "\n\n";

	cout << "After 5 is inserted in the tree:\n";
	bst->insert(5);
	cout << displayTree(bst) << "\n\n\n";

	cout << "\n\nDeleting now:\n";
	cout << "After 2 is deleted from the tree:\n";
	bst->remove(2);
	cout << displayTree(bst) << "\n\n";

	cout << "\n\nDeleting now:\n";
	cout << "After 4 is deleted from the tree:\n";
	bst->remove(4);
	cout << displayTree(bst) << "\n\n";

	cout << "\n\nDeleting now:\n";
	cout << "After 6 is deleted from the tree:\n";
	bst->remove(6);
	cout << displayTree(bst) << "\n\n";

	cout << "Inorder:\n"
			 << bst->inOrder() << "\n\n";
	cout << "Preorder:\n"
			 << bst->preOrder() << "\n\n";
	cout << "Postorder:\n"
			 << bst->postOrder() << "\n\n";

	/*

	bst->insert(8);
	bst->insert(16);
	bst->insert(15);
	bst->insert(4);

	bst->insert(2);
	bst->insert(5);
	bst->insert(1);
	bst->insert(13);

	bst->insert(12);
	bst->insert(14);

	bst->insert(9);
	bst->insert(7);
	bst->insert(11);
	bst->insert(6);
	bst->insert(3);
	bst->insert(10);

	cout << displayTree(bst);
	// cout << "Inorder: \n" << bst->inOrder();
	// cout << "\nPreorder: \n" << bst->preOrder();
	// cout << "\nPostorder: \n" << bst->postOrder();

	 */

	return 0;
}
