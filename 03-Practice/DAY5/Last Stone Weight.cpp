class Solution {
public:
    void Hmax(vector<int>& a, int i) {
        int hs = a.size();
        int lc = 2*i + 1, rc = 2*i + 2, largest = i;
        if (lc < hs && a[lc] > a[largest]) largest = lc;
        if (rc < hs && a[rc] > a[largest]) largest = rc;
        if (largest != i) {
            swap(a[i], a[largest]);
            Hmax(a, largest);
        }
    }

    void Bhmax(vector<int>& a) {
        int hs = a.size();
        for (int i = hs/2 - 1; i >= 0; i--) {
            Hmax(a, i);
        }
    }

    int extractMax(vector<int>& a) {
        int maxVal = a[0];
        swap(a[0], a.back());
        a.pop_back();
        if (!a.empty()) Hmax(a, 0);
        return maxVal;
    }

    int lastStoneWeight(vector<int>& stones) {
        Bhmax(stones);
        while (stones.size() > 1) {
            int s1 = extractMax(stones);
            int s2 = extractMax(stones);
            if (s1 != s2) {
                stones.push_back(abs(s1 - s2));
                int i=stones.size()-1;
                while(i>0 && stones[i/2]<stones[i]){
                    swap(stones[i/2],stones[i]);
                    i=i/2;
                }
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};