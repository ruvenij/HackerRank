#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};


/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) 
{
    DoublyLinkedListNode* currentNode = llist;
    DoublyLinkedListNode* prevNode = nullptr;
    DoublyLinkedListNode* nextNode = nullptr;
    
    while(currentNode->next)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode; 
        currentNode->prev = nextNode;
        prevNode = currentNode;
        currentNode = nextNode;   
    }
    
    currentNode->next = prevNode;
    currentNode->prev = nullptr;
    return currentNode;
}

void printList(DoublyLinkedListNode* node)
{
    while(node)
    {
        std::cout << node->data << " ";
        node = node->next;
    }

    std::cout << std::endl;
}

int main()
{
    DoublyLinkedListNode* head = new DoublyLinkedListNode(1);
    DoublyLinkedListNode* two = new DoublyLinkedListNode(2);
    DoublyLinkedListNode* three = new DoublyLinkedListNode(3);
    DoublyLinkedListNode* four = new DoublyLinkedListNode(4);
    DoublyLinkedListNode* five = new DoublyLinkedListNode(5);

    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = nullptr;

    printList(head);
    auto node = reverse(head);
    printList(node);
    
    return 0;
}