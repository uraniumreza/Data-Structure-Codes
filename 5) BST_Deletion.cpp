/* Deleting a BstNode from Binary search tree */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;

public:
    //Function to find minimum in a tree.
    BstNode* FindMin(BstNode* root)
    {
        while(root->left != NULL) root = root->left;
        return root;
    }

    // Function to search a delete a value from tree.
    struct BstNode* Delete(BstNode *root, int data) {
        if(root == NULL) return root;
        else if(data < root->data) root->left = Delete(root->left,data);
        else if (data > root->data) root->right = Delete(root->right,data);
        // Wohoo... I found you, Get ready to be deleted
        else {
            // Case 1:  No child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
            }
            //Case 2: One child
            else if(root->left == NULL) {
                struct BstNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL) {
                struct BstNode *temp = root;
                root = root->left;
                delete temp;
            }
            // case 3: 2 children
            else {
                struct BstNode *temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right,temp->data);
            }
        }
        return root;
    }

    //Function to visit BstNodes in Inorder
    void Inorder(BstNode *root) {
        if(root == NULL) return;

        Inorder(root->left);       //Visit left subtree
        printf("%d ",root->data);  //Print data
        Inorder(root->right);      // Visit right subtree
    }

    // Function to Insert BstNode in a Binary Search Tree
    BstNode* Insert(BstNode *root,char data) {
        if(root == NULL) {
            root = new BstNode();
            root->data = data;
            root->left = root->right = NULL;
        }
        else if(data <= root->data)
            root->left = Insert(root->left,data);
        else
            root->right = Insert(root->right,data);
        return root;
    }
};


int main() {
	/*Code To Test the logic
	  Creating an example tree
                5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
    BstNode test;
	BstNode* root = NULL;
	root = test.Insert(root,5); root = test.Insert(root,10);
	root = test.Insert(root,3); root = test.Insert(root,4);
	root = test.Insert(root,1); root = test.Insert(root,11);

	// Deleting BstNode with value 5, change this value to test other cases
	root = test.Delete(root,5);

	//Print BstNodes in Inorder
	cout<<"Inorder: ";
	test.Inorder(root);
	cout<<"\n";
}
