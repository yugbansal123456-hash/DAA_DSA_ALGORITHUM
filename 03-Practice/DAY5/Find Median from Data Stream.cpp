class MedianFinder {
public:
    vector<int> maxHeap; // lower half (max-heap)
    vector<int> minHeap; // upper half (min-heap)

    // Heapify down for maxHeap
    void heapifyDownMax(vector<int>& a, int i) {
        int n = a.size();
        int lc = 2*i+1, rc = 2*i+2, largest = i;
        if (lc < n && a[lc] > a[largest]) largest = lc;
        if (rc < n && a[rc] > a[largest]) largest = rc;
        if (largest != i) {
            swap(a[i], a[largest]);
            heapifyDownMax(a, largest);
        }
    }

    // Heapify down for minHeap
    void heapifyDownMin(vector<int>& a, int i) {
        int n = a.size();
        int lc = 2*i+1, rc = 2*i+2, smallest = i;
        if (lc < n && a[lc] < a[smallest]) smallest = lc;
        if (rc < n && a[rc] < a[smallest]) smallest = rc;
        if (smallest != i) {
            swap(a[i], a[smallest]);
            heapifyDownMin(a, smallest);
        }
    }

    // Heapify up for maxHeap
    void heapifyUpMax(vector<int>& a, int i) {
        while (i > 0) {
            int parent = (i-1)/2;
            if (a[i] > a[parent]) {
                swap(a[i], a[parent]);
                i = parent;
            } else break;
        }
    }

    // Heapify up for minHeap
    void heapifyUpMin(vector<int>& a, int i) {
        while (i > 0) {
            int parent = (i-1)/2;
            if (a[i] < a[parent]) {
                swap(a[i], a[parent]);
                i = parent;
            } else break;
        }
    }

    MedianFinder() {}

    void addNum(int num) {
        // Insert into maxHeap first
        maxHeap.push_back(num);
        heapifyUpMax(maxHeap, maxHeap.size()-1);

        // Balance: move root from maxHeap to minHeap
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap[0] > minHeap[0]) {
            int val = maxHeap[0];
            maxHeap[0] = maxHeap.back();
            maxHeap.pop_back();
            if (!maxHeap.empty()) heapifyDownMax(maxHeap, 0);

            minHeap.push_back(val);
            heapifyUpMin(minHeap, minHeap.size()-1);
        }

        // Balance sizes
        if (maxHeap.size() > minHeap.size() + 1) {
            int val = maxHeap[0];
            maxHeap[0] = maxHeap.back();
            maxHeap.pop_back();
            if (!maxHeap.empty()) heapifyDownMax(maxHeap, 0);

            minHeap.push_back(val);
            heapifyUpMin(minHeap, minHeap.size()-1);
        }
        else if (minHeap.size() > maxHeap.size()) {
            int val = minHeap[0];
            minHeap[0] = minHeap.back();
            minHeap.pop_back();
            if (!minHeap.empty()) heapifyDownMin(minHeap, 0);

            maxHeap.push_back(val);
            heapifyUpMax(maxHeap, maxHeap.size()-1);
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap[0] + minHeap[0]) / 2.0;
        } else {
            return maxHeap[0];
        }
    }
};