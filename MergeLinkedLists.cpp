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


SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    SinglyLinkedListNode* mergedListHead = nullptr;
    SinglyLinkedListNode* mergedListCurrent = nullptr;
    int index = 0;
    
    if (head1 == nullptr)
    {
        return head2;
    }
    else if (head2 == nullptr)
    {
        return head1;
    }
    
    while(head1 or head2)
    {
        if (head1 == nullptr)
        {
            mergedListCurrent->next = head2;
            break;
        }
        
        if (head2 == nullptr)
        {
            mergedListCurrent->next = head1;
            break;
        }
        
        if ((head1->data <= head2->data))
        {
            if (index == 0)
            {
                mergedListHead = head1;
            }
            else
            {
                mergedListCurrent->next = head1;    
            }
            
            mergedListCurrent = head1;
            head1 = head1->next;
        }
        else 
        {
            if (index == 0)
            {
                mergedListHead = head2;
            }
            else
            {
                mergedListCurrent->next = head2;    
            }    
            
            mergedListCurrent = head2;
            head2 = head2->next;
        }
    
        index++;
    }
    
    return mergedListHead;
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
    
    SinglyLinkedListNode* head2 = new SinglyLinkedListNode(2);
    SinglyLinkedListNode* two2 = new SinglyLinkedListNode(5);
    SinglyLinkedListNode* three2 = new SinglyLinkedListNode(6);
    SinglyLinkedListNode* four2 = new SinglyLinkedListNode(6);
    SinglyLinkedListNode* five2 = new SinglyLinkedListNode(8);

    head2->next = two2;
    two2->next = three2;
    three2->next = four2;
    four2->next = five2;
    five2->next = nullptr;

    printNode(head);
    printNode(head2);
    auto node = mergeLists(head, head2);
    printNode(node);

    return 0;
}
