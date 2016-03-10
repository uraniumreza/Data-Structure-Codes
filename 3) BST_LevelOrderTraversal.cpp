/* Binary tree - Level Order Traversal */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class BstNode
{
    char data;
    BstNode *left;
    BstNode *right;

public:
    // Function to print BstNodes in a binary tree in Level order
    void LevelOrder(BstNode *root)
    {
        if(root == NULL) return;
        queue<BstNode*> Q;
        Q.push(root);
        //while there is at least one discovered BstNode
        while(!Q.empty())
        {
            BstNode* current = Q.front();
            Q.pop(); // removing the element at front
            cout<<current->data<<" ";
            if(current->left != NULL) Q.push(current->left);
            if(current->right != NULL) Q.push(current->right);
        }
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
        else if(data <= root->data) root->left = Insert(root->left,data);
        else root->right = Insert(root->right,data);
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
    BstNode* root = NULL;
    BstNode test;
    root = test.Insert(root,'M');
    root = test.Insert(root,'B');
    root = test.Insert(root,'Q');
    root = test.Insert(root,'Z');
    root = test.Insert(root,'A');
    root = test.Insert(root,'C');
    //Print BstNodes in Level Order.
    test.LevelOrder(root);
}
