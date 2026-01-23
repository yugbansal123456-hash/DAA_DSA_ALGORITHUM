class KthLargest {
public:
    vector<int> f; // min-heap
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int val : nums) {
            add(val);
        }
    }

    void Hmin(vector<int>& a, int i) {
        int hs = a.size();
        int lc = 2*i + 1, rc = 2*i + 2, s = i;
        if (lc < hs && a[lc] < a[s]) s = lc;
        if (rc < hs && a[rc] < a[s]) s = rc;
        if (s != i) {
            swap(a[i], a[s]);
            Hmin(a, s);
        }
    }

    void Bhmin(vector<int>& a) {
        int hs = a.size();
        for (int i = hs/2 - 1; i >= 0; i--) {
            Hmin(a, i);
        }
    }

    int add(int val) {
        if (f.size() < k) {
            f.push_back(val);
            if (f.size() == k) {
                Bhmin(f); // build heap once
            }
        } else {
            if (val > f[0]) {
                f[0] = val;
                Hmin(f, 0); // re-heapify
            }
        }
        return f[0]; // kth largest is root of min-heap
    }
};