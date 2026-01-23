class Solution {
public:
    struct node {
        int val;
        int r;
        int c;
        node(int v, int ro, int co) : val(v), r(ro), c(co) {}
    };
    void heapifyDown(vector<node>& a, int i) {
        int n = a.size();
        int lc = 2*i + 1, rc = 2*i + 2, smallest = i;
        if (lc < n && a[lc].val < a[smallest].val) smallest = lc;
        if (rc < n && a[rc].val < a[smallest].val) smallest = rc;
        if (smallest != i) {
            swap(a[i], a[smallest]);
            heapifyDown(a, smallest);
        }
    }

    void buildHeap(vector<node>& a) {
        int n = a.size();
        for (int i = n/2 - 1; i >= 0; i--) {
            heapifyDown(a, i);
        }
    }
    node peekMin(vector<node>& heap) {
        return heap[0];
    }

    node extractMin(vector<node>& heap) {
        node root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(heap, 0);
        return root;
    }

    void replaceRoot(vector<node>& heap, node newNode) {
        heap[0] = newNode;
        heapifyDown(heap, 0);
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<node> heap;
        int hmax = INT_MIN, s = INT_MAX;
        int l = 0, h = 0;
        for (int i = 0; i < nums.size(); i++) {
            heap.push_back(node(nums[i][0], i, 0));
            hmax = max(hmax, nums[i][0]);
        }
        buildHeap(heap);

        while (true) {
            node mn = peekMin(heap);
            int hmin = mn.val;

            if (hmax - hmin < s) {
                s = hmax - hmin;
                l = hmin;
                h = hmax;
            }
            if (mn.c + 1 == nums[mn.r].size()) break;

            node next(nums[mn.r][mn.c + 1], mn.r, mn.c + 1);
            hmax = max(hmax, next.val);
            replaceRoot(heap, next);
        }

        return {l, h};
    }
};