/**
 *  Check whether 
 */

#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

//////////////////////////////////
//        Check bst symmtry     //
//////////////////////////////////

//Recursive solution

bool is_mirror(Node *tree1, Node *tree2)
{
    if (!tree1 || !tree2)
        return !tree1 && !tree2;

    return tree1->data == tree2->data &&
           is_mirror(tree1->left, tree2->right) &&
           is_mirror(tree1->right, tree2->left);
}

bool check_palindrome(vector<int> &vec)
{
    if(vec.size() == 0 || vec.size() == 1) return true;

    int *first = &vec[0];
    int *last = &vec[vec.size() - 1];

    while (first <= last)
    {
        if (*first++ != *last--)
            return false;
    }

    return true;
}

bool is_mirror_iterative(Node *n)
{
    if (!n)
    {
        return true;
    }

    queue<Node *> tree;
    tree.push(n);
    int level_size;

    while (!tree.empty())
    {
        level_size = tree.size();
        vector<int> level;

        while (level_size)
        {
            Node *temp = tree.front();
            tree.pop();

            if (temp->left)
            {
                level.push_back(temp->left->data);
                tree.push(temp->left);
            }
            if (temp->right)
            {
                level.push_back(temp->right->data);
                tree.push(temp->right);
            }
            --level_size;
        }

        if(!check_palindrome(level)){
            return false;
        }
    }

    return true;
}

//left and right subtrees have to be mirror images
bool is_symmetric(Node *tree)
{
    if(!tree) { return true; }
    return is_mirror(tree->left, tree->right);
}

//Iterative Solution

///////////////////////////////////
//      Iterative solution       //
///////////////////////////////////

// Utility function to create new Node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

void printLevelOrder(Node *root)
{

    if (!root)
    {
        return;
    }

    deque<Node *> container;
    container.push_back(root);

    while (1)
    {
        int size = container.size();

        if (!container.size())
        {
            break;
        }

        while (size > 0)
        {
            Node *temp = container.front();
            cout << temp->data << " ";
            container.pop_front();

            if (temp->left)
            {
                container.push_back(temp->left);
            }
            if (temp->right)
            {
                container.push_back(temp->right);
            }
            --size;
        }
        std::cout << std::endl;
    }
}

Node *insert(Node *n, int a)
{
    if (n == NULL)
    {
        return newNode(a);
    }

    if (n->data < a)
    {
        n->right = insert(n->right, a);
    }
    else if (n->data > a)
    {
        n->left = insert(n->left, a);
    }

    return n;
}

// Driver program
int main()
{
    // Let us construct the Tree shown in the above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    Node *root3 = newNode(3);
    root3->left = newNode(2);
    root3->right = newNode(2);

    Node *root2 = NULL;
    root2 = insert(root2, 3);
    insert(root2, 8);
    insert(root2, 10);
    insert(root2, 15);
    insert(root2, -1);
    insert(root2, -2);
    insert(root2, -7);
    insert(root2, 12);

    Node *root4 = NULL;
    root4 = insert(root4, 3);

    Node *root5 = NULL;

    //printLevelOrder(root2);
    cout << "Symmetry 0 or 1: " << is_symmetric(root) << endl;
    cout << "Same as last" << is_mirror_iterative(root) << endl;
    cout << "Symmetry 0 or 1: " << is_symmetric(root2) << endl;
    cout << "Same as last" << is_mirror_iterative(root2) << endl;
    cout << "Symmetry 0 or 1: " << is_symmetric(root3) << endl;
    cout << "Same as last" << is_mirror_iterative(root3) << endl;
    cout << "Symmetry 0 or 1: " << is_symmetric(root4) << endl;
    cout << "Same as last" << is_mirror_iterative(root4) << endl;
    cout << "Symmetry 0 or 1: " << is_symmetric(root5) << endl;
    cout << "Same as last" << is_mirror_iterative(root5) << endl;

    return 0;
}