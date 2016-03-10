/* Counting the no of BstNodes in a BST and the height of a BST */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int MAX(int a, int b)
{
    return (a>b ? a : b);
}

class BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;

public:
    //Function to find minimum in a tree.
    int FindMin(BstNode* root)
    {
        while(root->left != NULL) root = root->left;
        return root->data;
    }

    //Function to find maximum in a tree.
    int FindMax(BstNode* root)
    {
        while(root->right != NULL) root = root->right;
        return root->data;
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
                5
    		   / \
    		  3   10
    		 / \   \
    		1   4   11
    */
    BstNode test;
    BstNode* root = NULL;
    root = test.Insert(root,5);
    root = test.Insert(root,10);
    root = test.Insert(root,3);
    root = test.Insert(root,4);
    root = test.Insert(root,1);
    root = test.Insert(root,11);

    cout<<"Minimum element of the BST: ";
    cout<<test.FindMin(root)<<endl;
    cout<<"Maximum element of the BST: ";
    cout<<test.FindMax(root)<<endl;
    cout<<"\n";
}


