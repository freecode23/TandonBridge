//===expressionTree.h=================

#ifndef EXPRESSIONTREE_H_
#define EXPRESSIONTREE_H_
#include <iostream>
#include <typeinfo>
using namespace std;
//________________________
class OperandNode
{
public:
    int data;
    void *left;
    void *right;
    OperandNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
//________________________
class OperatorNode
{
public:
    char data;
    void *left;
    void *right;
    OperatorNode(char data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
//_____________________
//______________________
class ExpressionTree
{
public:
    void *root;
    //_________________
    ExpressionTree()
    {
        root = nullptr;
    }

    //_____________________
    ExpressionTree(void *node)
    {
        this->root = node;
    }
    
    //______________________
    float CalculateValue(void *node)
    {
        OperatorNode *optor = (OperatorNode *)node;
        char ch = optor->data;

        if (node != nullptr)
        {
            //ASCII value of different operators
            //42 *
            //43 +
            //45 -
            //47 /
            if ((ch != 42) && (ch != 43) && (ch != 45) && (ch != 47))
            {
                //type cast
                OperandNode *N = (OperandNode *)node;
                return (float)N->data;
            }
            else
            {
                //type cast
                OperatorNode *N = (OperatorNode *)node;
                float A = CalculateValue(N->left);
                float B = CalculateValue(N->right);
                switch (N->data)
                {
                case '+':
                    return A + B;
                case '-':
                    return A - B;
                case '*':
                    return A * B;
                case '/':
                    return A / B;
                }
            }
        }
        return -1;
    }
    //_____________________
};
//______________________

#endif /* EXPRESSIONTREE_H_ */