/**
  Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 . };
 */
class Solution {
public:
    void heapify(ListNode** heap, int i, int n) {
        while (true) {
            int smallest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n && heap[left]->val < heap[smallest]->val) smallest = left;
            if (right < n && heap[right]->val < heap[smallest]->val) smallest = right;

            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    void buildHeap(ListNode** heap, int n) {
        for (int i = n/2 - 1; i >= 0; i--) {
            heapify(heap, i, n);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = 0;
        ListNode* heap[10005]; // assume max k <= 10000
        for (auto node : lists) {
            if (node) heap[n++] = node;
        }
        if (n == 0) return nullptr;

        buildHeap(heap, n);

        ListNode dummy(0), *tail = &dummy;
        while (n > 0) {
            ListNode* minNode = heap[0];
            tail->next = minNode;
            tail = tail->next;

            if (minNode->next) {
                heap[0] = minNode->next;
            } else {
                heap[0] = heap[n-1];
                n--;
            }
            if (n > 0) heapify(heap, 0, n);
        }
        return dummy.next;
    }
};