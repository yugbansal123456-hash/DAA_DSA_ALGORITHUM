struct node{
    int v;
    node*next;
};
class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        node**adjlist=new node*[n];
        for(int i=0;i<n;i++)adjlist[i]=nullptr;
        int*p=new int[n];
        int*d=new int[n];
        for(auto&x:edges){
            int u=x[0],v=x[1];
            adde(adjlist,u,v);
        }
        bfs(adjlist,n,source,p,d);
        return Path(p,source,destination);
    }
    bool Path(int*p,int s,int v){
        if(s==v)return true;
        else if(p[v]==-1)return false;
        else return Path(p,s,p[v]);
    }
    node* createnode(int v){
        node* nn=new node;
        nn->v=v;
        nn->next=nullptr;
        return nn;
    }
    void adde(node**adjlist,int s,int d){
        node*n=createnode(d);
        n->next=adjlist[s];
        adjlist[s]=n;
        n=createnode(s);
        n->next=adjlist[d];
        adjlist[d]=n;
    }
    void bfs(node**adjlist,int n,int s,int *p,int *d){
        for(int i=0;i<n;i++){
            p[i]=-1;
            d[i]=INT_MAX;
        }
        d[s]=0;
        queue<int>Q;
        Q.push(s);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            node*temp=adjlist[u];
            while(temp){
                int v=temp->v;
                if(d[v]==INT_MAX){
                    d[v]=d[u]+1;
                    p[v]=u;
                    Q.push(v);
                }
                temp=temp->next;
            }
        }
    }
};