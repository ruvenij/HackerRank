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

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) 
{
    SinglyLinkedListNode* currentNaode = llist;
    SinglyLinkedListNode* nextNode = nullptr;
    SinglyLinkedListNode* prevNode = nullptr;
    
    while(currentNaode->next != nullptr)
    {
        nextNode = currentNaode->next;
        currentNaode->next = prevNode;
        prevNode = currentNaode;
        currentNaode = nextNode;
    }
    
    currentNaode->next = prevNode;
    return currentNaode;
}

void printNode(SinglyLinkedListNode* node)
{
    std:: cout << "PRINT" << std::endl;
    while(node)
    {
        std::cout << node->data << " ";
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
    auto node = reverse(head);
    printNode(node);
    
    return 0;
}