#include <iostream>
using namespace std;

// Defining the TreeNode structure
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

// function just to make new Tree Node and allocate memory to it
TreeNode* newTreeNode(int data)
{
    TreeNode* temp = new TreeNode;
    temp->value = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp; //returns a pointer to this node
}

//insert a Node in the Tree
// root is a reference/alias to Treenode pointer.
// so we are changing the actual root
void insert(TreeNode* &rootRef, int data)
{
    //base case
    // inserts at a root if it is null
    if (rootRef == NULL)
    {
        rootRef = newTreeNode(data);
        return;
    }

    // first recursive case
    //inserts recusrively to the left side of the node after comparing values
    if (data<rootRef->value)
    {
        insert(rootRef->left,data);
    }

        // second recursive cae
        //inserts recusrively to the right side of the node after comparing values
    else
    {
        insert(root->right, data);
    }
}

// printing of tree using inorder traversal
void inorder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

// main function
int main()
{
    // create a root node.
    // root points to null
    TreeNode* root = NULL;

    insert(root,6);
    insert(root,4);
    insert(root,8);
    insert(root,2);
    insert(root,5);

    inorder(root);
    return 0;
}