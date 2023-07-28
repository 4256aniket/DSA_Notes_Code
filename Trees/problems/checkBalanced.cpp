#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int height(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return 0;
    int lh = 0, rh = 0;
    if (root->left)
        lh = height(root->left);
    if (root->right)
        rh = height(root->right);

    return (1 + max(lh, rh));
}

pair<int, bool> helper(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<int, bool> p = {0, true};
        return p;
    }
    pair<int, bool> p, l, r;
    p.first = height(root);
    p.second = true;
    l.first = r.first = 0;
    l.second = r.second = true;
    if (root->left)
        l = helper(root->left);
    if (root->right)
        r = helper(root->right);

    if ((abs(l.first - r.first) <= 1) && (l.second && r.second))
        p.second = true;
    else
        p.second = false;

    return p;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return true;
    pair<int, bool> p;
    p = helper(root);
    return p.second;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}