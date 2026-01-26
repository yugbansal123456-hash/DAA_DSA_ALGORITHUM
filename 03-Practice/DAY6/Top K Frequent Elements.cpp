class Solution {
public:
    vector<pair<int,int>> ans;
    int s;
    void minheapify(vector<pair<int,int>> &a, int i) {
        int lc = 2*i + 1, rc = 2*i + 2, hs = a.size(), small = i;
        if(lc < hs && a[lc].second < a[small].second) small = lc;
        if(rc < hs && a[rc].second < a[small].second) small = rc;
        if(small != i) {
            swap(a[small], a[i]);
            minheapify(a, small);
        }
    }
    void buildminheap(vector<pair<int,int>> &a) {
        int hs = a.size();
        for(int i = (hs-1)/2; i >= 0; i--) {
            minheapify(a, i);
        }
    }
    void add(pair<int,int> a) {
        if(ans.size() < s) {
            ans.push_back(a);
            if(ans.size() == s) {
                buildminheap(ans);
            }
        } else {
            if(a.second > ans[0].second) {
                ans[0] = a;
                minheapify(ans, 0);
            }
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        s = k;
        for(auto &i : nums) {
            freq[i]++;
        }
        for(auto &p : freq) {
            add({p.first, p.second});
        }
        vector<int> result;
        for(auto &p : ans) {
            result.push_back(p.first);
        }
        return result;
    }
};