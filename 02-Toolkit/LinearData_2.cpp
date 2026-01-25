#include <iostream>
#include <climits>
#include <vector>
using namespace std;
void enqueue(vector<int>& Q, int& head, int& tail, int key) {//0 indexing
    int n = Q.size();
    if ((tail + 1) % n == head) { // overflow
        cout << "overflow\n";
        return;
    }
    Q[tail] = key;
    tail = (tail + 1) % n; // wrap-around
}
int dequeue(vector<int>& Q, int& head, int& tail) {
    int n = Q.size();
    if (head == tail) { // underflow
        cout << "underflow\n";
        return INT_MIN;
    }
    int r = Q[head];
    head = (head + 1) % n; // wrap-around
    return r;
}
void displayQueue(vector<int>& Q, int head, int tail) {
    int n = Q.size();
    if (head == tail) {
        cout << "Queue is empty\n";
        return;
    }
    int i = head;
    while (i != tail) {
        cout << Q[i] << " ";
        i = (i + 1) % n;
    }
    cout << "\n";
}
int main() {
    int n = 5; // capacity
    vector<int> Q(n);
    int head = 0, tail = 0;
    enqueue(Q, head, tail, 10);
    enqueue(Q, head, tail, 20);
    enqueue(Q, head, tail, 30);
    enqueue(Q, head, tail, 40);
    enqueue(Q, head, tail, 50); // overflow
    displayQueue(Q, head, tail);
    cout << dequeue(Q, head, tail) << "\n"; // 10
    cout << dequeue(Q, head, tail) << "\n"; // 20
    cout << dequeue(Q, head, tail) << "\n"; // 30
    cout << dequeue(Q, head, tail) << "\n"; // 40
    cout << dequeue(Q, head, tail) << "\n"; // 50
    cout << dequeue(Q, head, tail) << "\n"; // underflow
    return 0;
}