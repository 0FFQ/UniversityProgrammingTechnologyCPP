#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
private:
    Node *root;

    void Insert(Node *&node, int value);
    void CopyTree(Node *&newNode, Node *oldNode);
    void InOrder(Node *node);
    void DeleteTree(Node *node);

public:
    Tree();
    Tree(const Tree &other);
    ~Tree();

    void Insert(int value);
    void Copy(const Tree &other);
    void Print();
};

Tree::Tree()
{
    root = NULL;
}

Tree::Tree(const Tree &other)
{
    root = NULL;
    CopyTree(root, other.root);
}

Tree::~Tree()
{
    DeleteTree(root);
}

void Tree::Insert(Node *&node, int value)
{
    if (node == NULL)
    {
        node = new Node;
        node->data = value;
        node->left = NULL;
        node->right = NULL;
    }
    else if (value < node->data)
    {
        Insert(node->left, value);
    }
    else if (value > node->data)
    {
        Insert(node->right, value);
    }
}

void Tree::Insert(int value)
{
    Insert(root, value);
}

void Tree::CopyTree(Node *&newNode, Node *oldNode)
{
    if (oldNode == NULL)
        return;

    newNode = new Node;
    newNode->data = oldNode->data;
    newNode->left = NULL;
    newNode->right = NULL;

    CopyTree(newNode->left, oldNode->left);
    CopyTree(newNode->right, oldNode->right);
}

void Tree::Copy(const Tree &other)
{
    DeleteTree(root);
    root = NULL;

    CopyTree(root, other.root);
}

void Tree::InOrder(Node *node)
{
    if (node == NULL)
        return;

    InOrder(node->left);
    cout << node->data << " ";
    InOrder(node->right);
}

void Tree::Print()
{
    InOrder(root);
    cout << endl;
}

void Tree::DeleteTree(Node *node)
{
    if (node == NULL)
        return;

    DeleteTree(node->left);
    DeleteTree(node->right);

    delete node;
}

int main()
{
    Tree tree;

    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);

    cout << "Исходное дерево:" << endl;
    tree.Print();

    Tree copyTree(tree);

    cout << "Скопированное дерево:" << endl;
    copyTree.Print();

    return 0;
}