#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
    public:
        LRUCache(int capacity)
        {
            cp = capacity;
            head = NULL;
            tail = NULL;
        }
        
        void set(int key, int value) override
        {
            auto it = mp.find(key);
            if (it != mp.end())
            {
                it->second->value = value;
            }
            else
            {
                Node* newNode = new Node(NULL, head, key, value);
                if (head) head->prev = newNode;
                head = newNode;
                if (tail == NULL) tail = head;
                
                mp.insert(std::make_pair(key, newNode));
                
                //reaches capacity. has to replace tail
                if (mp.size() > cp)
                {
                    mp.erase(tail->key);
                    tail = tail->prev;
                    tail->next = NULL;
                }
            }
        }
        
        int get(int key) override
        {
            auto it = mp.find(key);
            if (it != mp.end())
            {
                if (it->second == head)
                {
                    // No change here
                }
                else if (it->second == tail)
                {
                    tail = tail->prev;
                    it->second->next = head;
                    head->prev = it->second;
                }
                else 
                {
                    Node* prev = it->second->prev;
                    Node* next = it->second->next;
                    prev->next = next;
                    next->prev = prev;
                    it->second->next = head;
                    head->prev = it->second;
                    head = it->second;
                }
                
                return it->second->value;
            }
            return -1;
        }
};

int main() {
    std::ifstream infile("A.txt");
   int n = 500000, capacity = 644, i;
   //cin >> n >> capacity;
   LRUCache l(capacity);
   string command;
   int key, value;
   std::string line;
    while (std::getline(infile, line))
    {
        vector<string> words{};

        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (words.at(0).compare("get") == 0)
        {
            int key = std::stoi(words.at(1));
            cout << l.get(key) << endl;
        }
        else if (words.at(0).compare("set") == 0)
        {
            int key = std::stoi(words.at(1));
            int value = std::stoi(words.at(2));
            l.set(key, value);
        }
    }
   
   return 0;
}
