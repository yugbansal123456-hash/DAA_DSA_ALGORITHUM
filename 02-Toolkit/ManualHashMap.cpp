//Use std::vector as your underlying storage.
//Chaining Version: Each bucket in your vector is a manual Linked List of std::pair<int, int>
#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
using namespace std;

struct Node {
    pair<int,int> obj;   // Key and Value
    Node* next = nullptr;
    Node* pre  = nullptr;
};

class HashTable {
private:
    vector<Node*> table;   // buckets

    int hashFunc(int k) {
        return abs(k) % table.size();
    }

public:
    // Constructor
    HashTable(int m) : table(m, nullptr) {}

    // Insert key-value pair
    void insert(int k, int v) {
    int bucket = hashFunc(k);
    Node* curr = table[bucket];
    
    // Optional: Check if key already exists to update value
    while (curr) {
        if (curr->obj.first == k) {
            curr->obj.second = v; // Update existing
            return;
        }
        curr = curr->next;
    }

    // Otherwise, insert new node at head
    Node* a = new Node{{k,v}, table[bucket], nullptr};
    if (table[bucket]) table[bucket]->pre = a;
    table[bucket] = a;
}

    // Search by key, return value or INT_MIN if not found
    int search(int k) {
        int bucket = hashFunc(k);
        Node* curr = table[bucket];
        while (curr) {
            if (curr->obj.first == k) return curr->obj.second;
            curr = curr->next;
        }
        return INT_MIN;
    }

    // Delete by key
    bool deleteKey(int k) {
        int bucket = hashFunc(k);
        Node* curr = table[bucket];
        while (curr) {
            if (curr->obj.first == k) {
                if (curr->pre == nullptr) { // deleting head
                    table[bucket] = curr->next;
                    if (curr->next) curr->next->pre = nullptr;
                } else {
                    curr->pre->next = curr->next;
                    if (curr->next) curr->next->pre = curr->pre;
                }
                delete curr;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // Print hash table
    void print() {
        for (int i = 0; i < (int)table.size(); i++) {
            cout << "Bucket " << i << ": ";
            if (table[i] == nullptr) {
                cout << "NIL\n";
                continue;
            }
            Node* curr = table[i];
            while (curr) {
                cout << "(" << curr->obj.first << "," << curr->obj.second << ") -> ";
                curr = curr->next;
            }
            cout << "nullptr\n";
        }
    }

    // Cleanup memory
    void clear() {
        for (auto& head : table) {
            while (head) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
    }

    // Destructor
    ~HashTable() {
        clear();
    }
};

int main() {
    HashTable ht(6);

    ht.insert(44, 5);
    ht.insert(14, 56);
    ht.insert(144, 556);
    ht.insert(4, 96);

    ht.print();

    int val = ht.search(14);
    cout << "Search key 14: " << (val != INT_MIN ? to_string(val) : "Not Found") << endl;

    val = ht.search(2);
    cout << "Search key 2: " << (val != INT_MIN ? to_string(val) : "Not Found") << endl;

    ht.deleteKey(144);

    ht.print();
}