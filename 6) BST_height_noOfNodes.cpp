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
    BstNode *left;
    BstNode *right;

public:
    //Function to find no of BstNodes in a tree.
    int countBstNodes(BstNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return countBstNodes(root->right) + countBstNodes(root->left) + 1;
    }

    //Function to find the height of a tree
    int findHeight(BstNode* root)
    {
        if(root == NULL)
        {
            return -1;
        }
        return MAX(findHeight(root->right), findHeight(root->left)) + 1;
    }

    //Function to visit BstNodes in Inorder
    void Inorder(BstNode *root)
    {
        if(root == NULL) return;

        Inorder(root->left);       //Visit left subtree
        printf("%d ",root->data);  //Print data
        Inorder(root->right);      // Visit right subtree
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

    cout<<"No of BstNodes in the BST: ";
    cout<<test.countBstNodes(root)<<endl;
    cout<<"Height of the BST: ";
    cout<<test.findHeight(root)<<endl;
    cout<<"\n";
}

