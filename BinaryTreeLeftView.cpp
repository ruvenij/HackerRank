#include <iostream>

class Node
{
    public:
        Node(int nodeValue) : value(nodeValue) {};

        int value = 0;
        Node* left = nullptr;
        Node* right = nullptr;
};


void printLeftView(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    Node* currentNode = root;
    
    while (currentNode)
    {
        std::cout << currentNode->value << " ";

        if (currentNode->left)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }
}



int main()
{
    /*
                 5
                
              4        6
                8          3  

        left view -> 5 -> 4 -> 8

    */

    Node* root = new Node(5);
    Node* node1 = new Node(4);
    Node* node2 = new Node(6);
    //Node* node3 = new Node(2);
    Node* node4 = new Node(8);
    Node* node5 = new Node(3);

    root->left = node1;
    root->right = node2;
    //node1->left = node3;
    node1->right = node4;
    node2->right = node5;

    printLeftView(root);
}