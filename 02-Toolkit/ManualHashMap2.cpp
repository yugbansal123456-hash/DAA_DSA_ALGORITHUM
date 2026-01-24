#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

enum slotstat { empty, fill, dele };

template<typename V>
struct node {
    int key;
    V value;
    slotstat status = slotstat::empty;
};

template<typename V>
class HashTable {
private:
    vector<node<V>> table;
    bool use_double;   // false = linear probing, true = double hashing
    int current;       // number of active elements

    double getload(int n, int m) {
        return static_cast<double>(n) / m;
    }

    void checkgrow() {
        if (getload(current, table.size()) > 0.7) {
            resize(2 * table.size());
        }
    }

    void checkshrink() {
        if (table.size() > 7 && getload(current, table.size()) < 0.2) {
            resize(table.size() / 2);
        }
    }

    void resize(int newSize) {
        vector<node<V>> oldtable = table;
        table.clear();
        table.resize(newSize);
        current = 0;

        for (auto &entry : oldtable) {
            if (entry.status == slotstat::fill) {
                insert(entry.key, entry.value);
            }
        }
    }

    int hash_linear(int k, int i, int m) {
        return (abs(k) % m + i) % m;
    }

    int hash_double(int k, int i, int m) {
        int h1 = abs(k) % m;
        int h2 = 1 + (abs(k) % (m - 1)); // step size
        return (h1 + i * h2) % m;
    }

    int probe(int k, int i) {
        return use_double ? hash_double(k, i, table.size())
                          : hash_linear(k, i, table.size());
    }

public:
    HashTable(int size, bool double_hashing=false) {
        table.resize(size);
        use_double = double_hashing;
        current = 0;
    }

    void insert(int k, V v) {
        node<V> entry;
        entry.key = k;
        entry.value = v;
        entry.status = slotstat::fill;

        int m = table.size(), block = -1, h;
        for (int i = 0; i < m; i++) {
            h = probe(k, i);

            if (table[h].status == slotstat::fill && table[h].key == k) {
                table[h].value = v; // update existing
                return;
            }
            if (table[h].status == slotstat::dele && block == -1) block = h;
            if (table[h].status == slotstat::empty) {
                if (block != -1) table[block] = entry;
                else table[h] = entry;
                current++;
                checkgrow();
                return;
            }
        }
        if (block != -1) {
            table[block] = entry;
            current++;
            checkgrow();
        } else {
            cout << "Hash table is full, consider rehashing.\n";
        }
    }

    V search(int k) {
        int m = table.size(), h;
        for (int i = 0; i < m; i++) {
            h = probe(k, i);
            if (table[h].status == slotstat::fill && table[h].key == k)
                return table[h].value;
            if (table[h].status == slotstat::empty)
                return INT_MIN; // not found
        }
        return INT_MIN;
    }

    void remove(int k) {
        int m = table.size(), h;
        for (int i = 0; i < m; i++) {
            h = probe(k, i);
            if (table[h].status == slotstat::fill && table[h].key == k) {
                table[h].status = slotstat::dele; // tombstone
                current--;
                checkshrink();
                return;
            }
            if (table[h].status == slotstat::empty) return;
        }
    }

    void print() {
        int m = table.size();
        for (int i = 0; i < m; i++) {
            cout << "Slot " << i << ": ";
            if (table[i].status == slotstat::empty) cout << "NIL\n";
            else if (table[i].status == slotstat::dele) cout << "DELETED\n";
            else cout << "(" << table[i].key << "," << table[i].value << ")\n";
        }
    }
};

int main() {
    cout << "=== Linear Probing Demo ===\n";
    HashTable<int> ht1(7); // linear probing

    ht1.insert(44, 5);
    ht1.insert(14, 56);
    ht1.insert(144, 556);
    ht1.insert(4, 96);

    ht1.print();

    int val = ht1.search(14);
    cout << "Search 14: " << (val != INT_MIN ? to_string(val) : "Not Found") << endl;

    val = ht1.search(2);
    cout << "Search 2: " << (val != INT_MIN ? to_string(val) : "Not Found") << endl;

    ht1.remove(144);
    ht1.print();

    cout << "\n=== Double Hashing Demo ===\n";
    HashTable<int> ht2(7, true); // double hashing

    ht2.insert(44, 5);
    ht2.insert(14, 56);
    ht2.insert(144, 556);
    ht2.insert(4, 96);

    ht2.print();

    val = ht2.search(14);
    cout << "Search 14 (double): " << (val != INT_MIN ? to_string(val) : "Not Found") << endl;

    ht2.remove(144);
    ht2.print();
}