class Solution {
public:
void MinHeapify(vector<int> &nums,int i){
    int n=nums.size();
    int lc=2*i+1,rc=2*i+2,smallest=i;
    if(lc<n&&nums[lc]<nums[smallest]){smallest=lc;}
    if(rc<n&&nums[rc]<nums[smallest]){smallest=rc;}
    if(smallest!=i){
        swap(nums[smallest],nums[i]);
        MinHeapify(nums,smallest);//down going methord
    }
}
void BuildMinHeap(vector<int> &nums){
    int n=nums.size();
    for(int i=(n-2)/2;i>=0;i--){
        MinHeapify(nums,i);
    }
}
vector<int> a;
int K;
    int findKthLargest(vector<int>& nums, int k) {
        K=k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
        }
        return a[0];
    }
    void add(int val){
        int n=a.size();
        if(n<K){
            a.push_back(val);
            if(a.size()==K){
             BuildMinHeap(a);
            }
        }
        if(n==K&& a[0]<val){
            a[0]=val;
            MinHeapify(a,0);
        }
    }
};