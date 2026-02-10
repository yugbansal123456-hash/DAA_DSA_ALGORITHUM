class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visit(n,false);
        queue<int>Q;
        int c=n;
        Q.push(0);
        visit[0]=true;
        c--;
        while(!Q.empty()){
            int top=Q.front();
            Q.pop();
            for(auto&x:rooms[top]){
                if(visit[x])continue;
                visit[x]=true;
                c--;
                Q.push(x);
            }
        }
        return c==0?true:false;
    }
};