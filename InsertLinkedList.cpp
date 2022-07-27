#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) 
{
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    if (position == 0)
    {
        newNode->next = llist;
        return newNode;
    }
    
    int currentPos = 1;
    SinglyLinkedListNode* currentNode = llist;
    
    while(currentPos < position)
    {
        currentNode = currentNode->next;
        currentPos++;
    }
    
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return llist;
}

void printNode(SinglyLinkedListNode* node)
{
    std:: cout << "PRINT" << std::endl;
    while(node)
    {
        std::cout << node->data << " ";
        node = node->next;
    }

    std::cout << std::endl;
}

int main()
{
    SinglyLinkedListNode* head = new SinglyLinkedListNode(1);
    SinglyLinkedListNode* two = new SinglyLinkedListNode(2);
    SinglyLinkedListNode* three = new SinglyLinkedListNode(3);
    SinglyLinkedListNode* four = new SinglyLinkedListNode(4);
    SinglyLinkedListNode* five = new SinglyLinkedListNode(5);

    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = nullptr;

    printNode(head);
    auto node = insertNodeAtPosition(head, 8, 3);
    printNode(node);

    return 0;
}
