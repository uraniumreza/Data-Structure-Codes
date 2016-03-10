#include <bits/stdc++.h>
#include<iostream>
using namespace std;

//Definition of Node for Binary search tree
class BstNode
{
    char data;
    struct BstNode *left;
    struct BstNode *right;

public:
    //Function to visit BstNodes in Preorder
    void Preorder(struct BstNode *root)
    {
        // base condition for recursion
        // if tree/sub-tree is empty, return and exit
        if(root == NULL) return;

        printf("%c ",root->data); // Print data
        Preorder(root->left);     // Visit left subtree
        Preorder(root->right);    // Visit right subtree
    }

    //Function to visit BstNodes in Inorder
    void Inorder(BstNode *root)
    {
        if(root == NULL) return;

        Inorder(root->left);       //Visit left subtree
        printf("%c ",root->data);  //Print data
        Inorder(root->right);      // Visit right subtree
    }

    //Function to visit BstNodes in Postorder
    void Postorder(BstNode *root)
    {
        if(root == NULL) return;

        Postorder(root->left);    // Visit left subtree
        Postorder(root->right);   // Visit right subtree
        printf("%c ",root->data); // Print data
    }

    // Function to Insert BstNode in a Binary Search Tree
    BstNode* Insert(BstNode *root,char data)
    {
        if(root == NULL)
        {
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


int main()
{
    /*Code To Test the logic
      Creating an example tree
                M
    		   / \
    		  B   Q
    		 / \   \
    		A   C   Z
    */

    BstNode test;
    BstNode* root = NULL;
    root = test.Insert(root,'M');
    root = test.Insert(root,'B');
    root = test.Insert(root,'Q');
    root = test.Insert(root,'Z');
    root = test.Insert(root,'A');
    root = test.Insert(root,'C');
    //Print BstNodes in Preorder.
    cout<<"Preorder: ";
    test.Preorder(root);
    cout<<"\n";
    //Print BstNodes in Inorder
    cout<<"Inorder: ";
    test.Inorder(root);
    cout<<"\n";
    //Print BstNodes in Postorder
    cout<<"Postorder: ";
    test.Postorder(root);
    cout<<"\n";
}
