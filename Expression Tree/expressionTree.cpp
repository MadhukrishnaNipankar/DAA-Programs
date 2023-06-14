#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node()
    {
        this->data = '\0';
    }

    Node(char data)
    {
        this->data = data;
    }
};

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
    {
        return 1;
    }
    return 0;
}

class ExpressionTree
{
public:
    Node *constructExpressionTree(string expression)
    {
        /*
        ab+c-
        */

        int lengthOfExpression = expression.length();
        stack<Node *> st;

        for (int i = 0; i < lengthOfExpression; i++)
        {
            if (isOperator(expression[i]))
            {
                Node *operatorNode = new Node(expression[i]);
                Node *rightNode = st.top();
                st.pop();
                Node *leftNode = st.top();
                st.pop();
                operatorNode->left = leftNode;
                operatorNode->right = rightNode;
                st.push(operatorNode);
            }
            else
            {
                Node *operandNode = new Node(expression[i]);
                operandNode->left = NULL;
                operandNode->right = NULL;

                st.push(operandNode);
            }
        }

        return st.top();
    }

    void inorder(Node *root)
    {
        if (root)
        {
            inorder(root->left);
            std::cout << root->data;
            inorder(root->right);
        }

        return;
    }

    void preorder(Node *root)
    {
        if (root)
        {

            std::cout << root->data;
            preorder(root->left);
            preorder(root->right);
        }

        return;
    }

    void postorder(Node *root)
    {
        if (root)
        {
            postorder(root->left);
            postorder(root->right);
            std::cout << root->data;
        }

        return;
    }
};

int main()
{

    ExpressionTree *tree = new ExpressionTree();
    Node *root = tree->constructExpressionTree("ab+c-d*");
    tree->inorder(root);
    std::cout << endl;
    tree->preorder(root);
    std::cout << endl;
    tree->postorder(root);

    return 0;
}