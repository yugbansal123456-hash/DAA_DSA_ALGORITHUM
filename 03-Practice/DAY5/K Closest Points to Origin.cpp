class Solution {
public:
struct obj{
    vector<int>p;
    int d;
    obj( vector<int> a,int r){p=a;d=r;}
};
void HeapMaxify(vector<obj>& points,int i){//shift down
    int lc=2*i+1,rc=2*i+2,hs=points.size(),s=i;
    if(lc<hs&&points[lc].d>points[s].d){s=lc;}
    if(rc<hs&&points[rc].d>points[s].d){s=rc;}
    if(s!=i){
        swap(points[s],points[i]);
        HeapMaxify(points,s);
    }
}
void BuildHeapMax(vector<obj>& points){//shift up
    int hs=points.size();
    for(int i=hs/2-1;i>=0;i--){
        HeapMaxify(points,i);
    }
}
vector<obj> result;
int K;
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int d;
    K=k;
        for(int i=0;i<points.size();i++){
            d=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            obj n=obj(points[i],d);
            add(n);
        }
        vector<vector<int>> final;
        for(int i=0;i<result.size();i++){
            final.push_back(result[i].p);
        }
        return final;
}

void add(obj &a){
    if(result.size()<K){
        result.push_back(a);
        if(result.size()==K){
            BuildHeapMax(result);
        }
    }else{
        if(a.d<result[0].d){
            result[0]=a;
            HeapMaxify(result,0);
        }
    }

}

};