/**
 * @author Andy Vuong
 * This file describes the trinarytree implementation. Although I only have to implement insert and delete
 * I included a class declaration because I feel it would make the solution easier to follow.
 */


#ifndef TRINARYTREE_H
#define TRINARYTREE_H

#include <cmath>
#include <string>

using namespace std;

class TrinaryTree {
	private:

		struct Node {
			int value;
			Node * left;
			Node * middle;
			Node * right;
			
			Node(int val) : value(val), left(NULL), right(NULL), middle(NULL) {
			}

		};
		
		Node * root;

	public:

		/* *********************************************************************
		 * Other implementation details such as a constructor, destructor,
		 * copy constructor, etc.
		 *
		 *
		 * These functions are not included but are assumed to be here.
		 * *********************************************************************/	

		/**
		 * Recursive function that inserts a new node into a tree.
		 */
		void insertNode(Node * & t, int & val);
		
		/**
		 * Recursive function that removes a node by calling helper functions.
		 */
		void deleteNode(Node * & t, int & val);


	private:
		/**
		 * Helper function that calls one of the remove child functions below.
		 */
		void remove(Node * & t);
		
		/**
		 * Remove a node when it has no children.
		 */
		void noChildRemove(Node * & t);
		
		/**
		 * Remove a node when it only has one child (left or right(
		 */
		void oneChildRemove(Node * & t);
		
		/**
		 * Remove a node when it has atleast two children (left and right).
		 */
		void twoChildRemove(Node * & t);
		
		/**
		 * Recursively finds the inorder predecessor when called from twoChildRemove. Only functions correctly called from twoChildRemove.
		 */
		Node* iop(Node * & t);

};

#endif

