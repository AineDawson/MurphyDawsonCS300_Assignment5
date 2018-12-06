
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
using namespace std;
//Dawson Murphy
//This program defines the methods and variables for implementing a binary search tree
//This tree has been slightly modified to work with HashTable.

template <class T>
struct node{
	T data;
	node<T>* left; //left child
	node<T>* right; //right child
};
template <class T>
class BinarySearchTree{
	public:
		BinarySearchTree(); //Constructor
		//Following methods only functions are to call other methods.
		//This prevents the user from accesing data they should not.
		void printInOrder(){printInOrder(root);}//Prints entire tree InOrder
		void printPreOrder(){printPreOrder(root);}//Prints entire tree PreOrder
		void printPostOrder(){printPostOrder(root);}//Prints entire tree PostOrder
		int height(){return height(root);}//Returns height of the tree
		void insert(T& item){insert(root, item);} //inserts item into tree
		T search(T& item){return search(root,item);} //searches tree for item
		bool checkTree(T& item){return checkTree(root,item);} //checks if item is in the tree
		T findMax(){return findMax(root);} //finds the largest item in tree
		T findMin(){return findMin(root);} //finds smalles item in tree
		T findRoot(){return root->data;} //Returns the root of the tree
		void deletenode(T& item){deletenode(root, item);} //Deletes a node from the tree
		T search(string key){ //Finds item based on a string, for use by HashTable
            return search(this->root,key);
        }
		~BinarySearchTree(){destroy(root);} //destructor
	protected:
		node<T>* root; //The root of the tree
	private:
		T search(node<T>* p, string key); //Searches tree for an item based on a string, for use by HashTable
		void printInOrder(node<T>*); //Prints a nodes subtree InOrder
		void printPreOrder(node<T>*); //Prints a nodes subtree PreOrder
		void printPostOrder(node<T>*); //Prints a nodes subtree PostOrder
		void destroy(node<T>*); //destroys a node
		int height(node<T>*); //Gets the height of a node
		void insert(node<T>*&, T&); //Inserts an item into a nodes subtree
		T search(node<T>*, T&); //Finds an item in a nodes subtree
		bool checkTree(node<T>*, T&); //Checks if an item is in a nodes subtree
		T findMax(node<T>*); //Finds the largest item in a nodes subtree
		T findMin(node<T>*); //Finds the smallest item in a nodes subtree
		void deletenode(node<T>*&, T&); //Deletes an item from a nodes subtree
};

//Constructor for the BST
template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root=NULL;
}

//Prints the Binary Search Tree InOrder (Left to Right)
//Private recursive function that takes any node and treats it as the root.
template <class T>
void BinarySearchTree<T>::printInOrder(node<T>* p){
	if(p!=NULL){ //Only attempts to print if the node treated as the root is not NULL
		printInOrder(p->left); //Print left child and its children
		cout<<p->data<<", "; //Prints current node
		printInOrder(p->right);//Prints right child and its children
	}
}

//Prints the Binary Search Tree PreOrder (Top to Bottom)
//Private recursive function that takes any node and treats it as the root.
template <class T>
void BinarySearchTree<T>::printPreOrder(node<T>* p){
	if(p!=NULL){ //Only attempts to print if the node treated as the root is not NULL
		cout<<p->data<<" "; //Prints current node
		printPreOrder(p->left); //Print left child and its children
		printPreOrder(p->right); //Prints right child and its children
	}
}

//Prints the Binary Search Tree PostOrder (Bottom to Top)
//Private recursive function that takes any node and treats it as the root.
template <class T>
void BinarySearchTree<T>::printPostOrder(node<T>* p){
	if(p!=NULL){ //Only attempts to print if the node treated as the root is not NULL
		printPostOrder(p->left); //Print left child and its children
		printPostOrder(p->right); //Prints right child and its children
		cout<<p->data<<" "; //Prints current node
	}
}

//Finds and returns the height of the node p in the tree.
template <class T>
int BinarySearchTree<T>::height(node<T>* p){
	if(p!=NULL){ //If p is not NULL, it exists in the tree
		return 1 + max(height(p->left), height(p->right));
	}
	return -1; //If node p is an empty child of a node in the tree
}

//Destroys a node in the tree, if it is not NULL already
template <class T>
void BinarySearchTree<T>::destroy(node<T>* p){
	if(p!= NULL){ 
		destroy(p->left); //Destroys the nodes left child
		destroy(p->right); //Destroys the nodes right child
		delete p; 
		p= NULL;
	}
}

//Inserts an item into the tree, starting at node p.
template <class T>
void BinarySearchTree<T>::insert(node<T>*& p, T& item){
	if(p == NULL){ //If node is NULL, inserts item there
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if(item<p->data){ //If item is smaller than item at the node, moves to the nodes left child
		insert(p->left, item);
	}else{ //if the item is bigger thatn the item at the node, moves to the nodes right child
		insert(p->right, item);
	}
}

//Searches for an item at node p, recusively calling itself to search the nodes
//children. If found, returns the data of the node equal to the item.
template <class T>
T BinarySearchTree<T>::search(node<T>* p, T& item){
	if(p == NULL)
		throw 343; //Throws an int if the item is not found
	else if(item<p->data) //if item smaller than node, moves to left child
		return search(p->left, item);
	else if(item>p->data) //if item larger than node, moves to right child
		return search(p->right, item);
	return p->data; //If item is found, returns the data at the node
}

//Searches the tree for an item, an returns a boolean value for whether 
//the item is in the tree or not
template <class T>
bool BinarySearchTree<T>::checkTree(node<T>* p, T& item){
	if(p == NULL)
		return 0; //If not found, returns 0
	else if(item<p->data) //If item smaller than node, moves to left child
		return checkTree(p->left, item);
	else if(item>p->data) //IF item is larger than node, moves to right child
		return checkTree(p->right, item);
	return 1; //If found, returns 1
}

//Finds the largest starting at node p, and returns it.
//Since largest items are always on the left, this method 
//keeps checking the right child until there are no more right children,
//then returns the last right child.
template <class T>
T BinarySearchTree<T>::findMax(node<T>* p){
	if (p==NULL) //If p is NULL, there is no max. Throws an int. This step is only needed for the first node.
		throw 343; 
	else if(p->right==NULL) //If node has no right child, it is largest item
		return p->data; //Returns the item.
	else
		return findMax(p->right);//Moves to the nodes right child
}

//Finds smallest item starting at node p. Since smallest items are always on the left,
//this method keeps checking the left child until there are no more left children. It then 
//returns that last left child.
template <class T>
T BinarySearchTree<T>::findMin(node<T>* p){
	if (p==NULL) //If the node is empty, there is no min. Throws an int. Only needed to check first node.
		throw 343;
	else if(p->left==NULL) //If node has no left child, it is min. Returns the nodes data
		return p->data;
	else //Moves to the nodes left child
		return findMin(p->left);
}

//Deletes an item from the tree, starting the search at node p.
template <class T>
void BinarySearchTree<T>::deletenode(node<T>*& p, T& item){
	if(p==NULL) //If the node is empty, item was not found. Ends recursion
		return;
	else if (item<p->data) //If item is smaller than the node, moves to left child
		deletenode(p->left, item);
	else if (item>p->data)	//If the item is larger than the node, moves to right child
		deletenode(p->right, item);
    else{ //The node p is equal to the item, begins deleting
		if(p->left!= NULL){//If p has a left child
			p->data=findMax(p->left); //Finds the largest item in p's left childs subtree, and replaces p with it
			deletenode(p->left, p->data); //Recusively deletes the largest item in p's left subtree
		}else if(p->right != NULL){ //If p has a right child
			p->data=findMin(p->right); //Finds the smallest item in p's right childs subtree, and replaces p with it
			deletenode(p->right, p->data); //Recusively deletes the smallest item in p's left subtree
		}else{ //p has no children	
			p=NULL; //Sets p to NULL
		}
	}
}

//Finds an item based on a string. Recursively goes through array until it is found,
//and then returns the object. IF not found, throws an int.
template <class T>
T BinarySearchTree<T>::search(node<T>* p, string key){
	if(p == NULL) //item was not found
		throw 343;
	else if(key<p->data) //item is smaller than current node
		return search(p->left, key);
	else if(key>p->data) //item is larger than current node
		return search(p->right, key);
	return p->data; //The current node holds the item
}


#endif /* BINARYSEARCHTREE_H_ */

