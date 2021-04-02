#include <bits/stdc++.h>
using namespace std;
//tree Node class to store each node in a tree with data and left and right pointer
class treeNode
{
public:
    string data;
    treeNode *left, *right;
    treeNode(string str) //constructor to initialize object of treeNode class with given value
    {
        data = str;
        left = NULL;
        right = NULL;
    }
};
//expressionTree class to perform different operation on expression Tree
class expressionTree
{
    treeNode *t; //treeNode pointer that will be used to store root of tree

public:
    expressionTree()
    {
        t = NULL;
    }
    expressionTree(treeNode *root)
    {
        t = root;
    }
    //evaluate Tree heler function to calculate/evaluate the gievn expression tree
    int evalTree_helper(treeNode *root)
    {
        //base case when root is NUll return 0
        if (root == NULL)
            return 0;

        //If root is leaf node then convert that node's data to integer and return
        if (root->left == NULL && root->right == NULL)
            return std::stoi(root->data);

        // root is neither leaf nor null 
        //recursive calls on left and right sub tree
        int left_ans = evalTree_helper(root->left);
        int right_ans = evalTree_helper(root->right);

        //if current root's data is an operator then we have to computer the result for its child
        if (root->data == "/") //if operator is / then we return left_ans/right_ans
            return left_ans / right_ans;

        if (root->data == "+") //if operator is + then we return left_ans+right_ans
            return left_ans + right_ans;

        if (root->data == "*") //if operator is * then we return left_ans*right_ans
            return left_ans * right_ans;

        return left_ans - right_ans; //else if operator is - then we return left_ans-right_ans
    }
    //evalTree function to check if root is not null,and call evalTree_helper function
    int evalTree()
    {
        //if current root is NULL we return 0
        if (this->t == NULL)
            return 0;
        return evalTree_helper(this->t);
    }
};
int main()
{
    //Creating an expression Tree for this tree structure
    //            *
    /*           / \          */
    //          +   7
    /*         / \            */
    //        2   3
    treeNode *root = new treeNode("*");
    root->left = new treeNode("+");
    root->left->left = new treeNode("2");
    root->left->right = new treeNode("3");
    root->right = new treeNode("7");
    expressionTree *tree = new expressionTree(root);
    cout << "Answer after Evaluating the Tree is : " << tree->evalTree();
    return 0;
}