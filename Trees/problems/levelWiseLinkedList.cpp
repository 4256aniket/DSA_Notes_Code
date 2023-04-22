#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> output;
    if (root == NULL)
    {

        return output;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if (front == NULL)
        {
            output.push_back(head);
            head = NULL;
            tail = NULL;

            if (!pendingNodes.empty())
                pendingNodes.push(NULL);
            else
            {
                break;
            }
        }
        else
        {
            Node<int> *n = new Node<int>(front->data);
            if (head == NULL && tail == NULL)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                tail = tail->next;
            }

            if (front->left)
                pendingNodes.push(front->left);
            if (front->right)
                pendingNodes.push(front->right);
        }
    }
    return output;
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
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            pendingNodes.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            pendingNodes.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
    }
}