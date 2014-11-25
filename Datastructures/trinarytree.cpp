/**
 * @author Andy Vuong
 * This file contains my implementation for insert and delete in a trinary tree.
 *
 * General Assumptions:
 * 1. Other functions already implemented (constructor, etc)
 * 2. A global "Root" pointer exists.
 * 3. The tree is not a balanced tree so self-balancing will not occur.
 * 4. Multiple nodes of the same copy will always line up with their middle pointers.
 * 5. If there are multiple nodes with the same value, then the furthest child node for those nodes will be removed in my delete function. (i.e. (Root Node) 2 -> 2 -> 2 (Last child node). Far right removed.)
 * 
 * Note: See the header file for some details on how a Node is implemented.
 *
*/

#include "trinarytree.h"

#include <cmath>
#include <string>

using namespace std;

/**
 * This function will insert new nodes into a trinary tree
 *
 * @parameter t - The current node.
 * @parameter val - The value to insert.
 */
void TrinaryTree::insertNode(Node* & t, int & val) {
	if(t == NULL) {
		t = new Node(val);
	}
	else if(val == t->value) {
		insertNode(t->middle, val);
	}
	else if(val < t->value) {
		insertNode(t->left, val);
	}
	else if(val > t->value) {
		insertNode(t->right, val);
	}
}


/**
 * This function performs the deletion function for the trinary tree. 
 * It calls a series of helper functions to delete the correct node and maintain the structure of the tree.
 *
 * @parameter t - The current node.
 * @parameter val - The value to remove.
 */
void TrinaryTree::deleteNode(Node * & t, int & val) {
	if(t != NULL) {
		if(t->value == val && t->middle == NULL) { 	// Remove the middle node if it has no middle child.
			remove(t);
		}
		else if(val < t->value) { 					// Search left.
			deleteNode(t->left, val);
		}
		else if(val > t->value) {					// Search Right.
			deleteNode(t->right, val);
		}
		else {										// Find the last child of a series of nodes with matching children.
			deleteNode(t->middle, val); 
		}
	}
}


/**
 * This is a helper function called by the deleteNode function. It is only called when the node to be deleted has been found.
 * It needs to perform one of three operations: noChildRemove, twoChildRemove, oneChildRemove. The appropriate function is
 * called depending on how many children t has. The middle pointer for a node doesn't need to be checked because this function will
 * only be called from deleteNode if that middle pointer is NULL anyway.
 *
 * @paramter t - Node to be deleted.
 */
void TrinaryTree::remove(Node * & t) {
	if( (t->left == NULL) && (t->right == NULL)) {
		noChildRemove(t);
	}
	else if( (t->left != NULL) && (t->right != NULL)) {
		twoChildRemove(t);
	}
	else {
		oneChildRemove(t);
	}
}

/**
 * This helper function removes a node containing no children. It frees the memory held by that node
 * and sets the pointer of its parent to NULL.
 *
 * @parameter t - Node to be removed.
 */
void TrinaryTree::noChildRemove(Node * & t) {
	delete t;
	t = NULL;
}

/**
 * This helper function removes a node containing one child.
 *
 * @parameter t - Node to be removed.
 */
void TrinaryTree::oneChildRemove(Node * & t) {
	Node * temp = t;				// Temporary pointer will store the location of the node to be removed
	if(t->left == NULL)				// Sets t's parent pointer to t to point at the left or right node of t depending on where the child is.
		t = t->right;
	else
		t = t->left;
    
	delete temp;					// Delete can now be called on temp to remove the node.
}

/**
 * This helper function removes a node containing two children, either left or right. If this node is a part of a series of nodes with the same value (i.e. 2 2 2 2),
 * it will recusively travel to the furthest matching child and remove that one. 
 *
 * The default behavior of this function is to replace the node being removed with its inorder predecessor to maintain the structure of the tree. 
 *
 * @parameter t - Node to be removed.
 */
void TrinaryTree::twoChildRemove(Node * & t) {
	Node * temp;
	if(t->middle != NULL) {				// Replace the middle child with the top child. Essentially, remove will recursively run on this branch of children until the furthest one.
		temp = t->middle;
		t->value = temp->value;
	}
	else {
		temp = iop(t->left);			// Store a pointer to the IOP that will replace the node being removed.
		t->value = temp->value;
	}
	remove(temp);						// Delete the node that had "replaced" the current node by calling remove. Same deletion algorithm will run again for that node as it did this! 
}

/**
 * This helper function will find the in-order predecessor. In the previous function (twoChildRemove), it must be called on the left child of the node for which
 * the inorder predecessor is being searched for to return the correct node. The inorder predecessor is essentially the "rightmost" node of the left subtree
 * of the node where the inorder predecessor is being searched for.
 * @parameter t - Node.
 */
TrinaryTree::Node* TrinaryTree::iop(Node * & t) {
	if(t->right == NULL)
		return t;
	else if(t->right != NULL)
		return iop(t->right);
}

