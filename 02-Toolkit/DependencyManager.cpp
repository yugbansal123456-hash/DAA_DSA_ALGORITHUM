#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
struct node{
    int vertex;
    node*next;
};
struct graph{
    int numver;
    node**adjlist;
};
enum COLOR{white,gray,black};
node*createNode(int v){
    node*n=new node;
    n->next=nullptr;
    n->vertex=v;
    return n;
}
graph*createGraph(int nv){
    graph*G=new graph;
    G->numver=nv;
    G->adjlist=new node*[nv];
    for(int i=0;i<nv;i++){
        G->adjlist[i]=nullptr;
    }
    return G;
}
void addEdgeBIDir(graph*G,int s,int d){
    node*nn=createNode(d);
    nn->next=G->adjlist[s];
    G->adjlist[s]=nn;
    nn=createNode(s);
    nn->next=G->adjlist[d];
    G->adjlist[d]=nn;
}
void addEdgeDir(graph*G,int s,int d){
    node*nn=createNode(d);
    nn->next=G->adjlist[s];
    G->adjlist[s]=nn;
}
void DFS_VISIT(graph*G,int*p,COLOR*c,int u,int*d,int*f,int&time){
    time++;
    d[u]=time;
    cout<<"("<<u<<" ";
    c[u]=gray;
    node*temp=G->adjlist[u];
    while(temp){
        int v=temp->vertex;
        if(c[v]==white){
            p[v]=u;
            DFS_VISIT(G,p,c,v,d,f,time);
        }
        temp=temp->next;
    }
    time++;
    f[u]=time;
    c[u]=black;
    cout<<u<<") ";
}
void DFS(graph*G,int*p,COLOR*c,int*d,int*f){
    int n=G->numver;
    for(int i=0;i<n;i++){
        p[i]=-1;
        c[i]=white;
    }
    int time=0;
    for(int i=0;i<n;i++){
        if(c[i]==white){
            DFS_VISIT(G,p,c,i,d,f,time);
        }
    }
}
bool TS_VISIT(graph*G,COLOR*c,int u,vector<int>&TS){
    c[u]=gray;
    node*temp=G->adjlist[u];
    while(temp){
        int v=temp->vertex;
        if(c[v]==gray){
            return false;
        }
        if(c[v]==white){
            if(!TS_VISIT(G,c,v,TS)){
                return false;
            }
        }
        temp=temp->next;
    }
    c[u]=black;
    TS.push_back(u);
    return true;
}
vector<int> Topological_sort(graph*G,COLOR*c){
    int n=G->numver;
    for(int i=0;i<n;i++){
        c[i]=white;
    }
    vector<int>TS;
    for(int i=0;i<n;i++){
        if(c[i]==white){
            if(!TS_VISIT(G,c,i,TS)){
                cout<<"CYCLE FORMED SO TS UNABLE";
                return {};
            }
        }
    }
    reverse(TS.begin(),TS.end());
    return TS;
}
void cleanUp(graph*G){
    int n=G->numver;
    for(int i=0;i<n;i++){
        node*temp=G->adjlist[i];
        while(temp){
            node*prev=temp;
            temp=temp->next;
            delete prev;
        }
    }
    delete[]G->adjlist;
    delete G;
}
void print(graph*G){
    int n=G->numver;
    for(int i=0;i<n;i++){
        cout<<"Vertex "<<i<<" : ";
        node*temp=G->adjlist[i];
        while(temp){
            cout<<temp->vertex<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
vector<int>Khan(graph*G){
    int n=G->numver;
    vector<int>din(n,0);//in-degree
    for(int i=0;i<n;i++){
        node*temp=G->adjlist[i];
        while(temp){
            din[temp->vertex]++;
            temp=temp->next;
        }
    }
    queue<int>Q;
    vector<int>ts;
    for(int i=0;i<n;i++){
        if(din[i]==0)Q.push(i);
    }
    while(!Q.empty()){
        int u=Q.front();
        ts.push_back(u);
        Q.pop();
        node*temp=G->adjlist[u];
        while(temp){
            int v=temp->vertex;
            din[v]--;
            if(din[v]==0)Q.push(v);
        }
    }
    if(ts.size()!=n){
        cout<<"Cycle formed";
        return {};
    }
    return ts;
}
node**reverseList(graph*G){
    int n=G->numver;
    node**revlist=new node*[n];
    for(int i=0;i<n;i++){
        revlist[i]=nullptr;
    }
    for(int u=0;u<n;u++){
        node*temp=G->adjlist[u];
        while(temp){
            int v=temp->vertex;
            node*nn=createNode(u);
            nn->next=revlist[v];
            revlist[v]=nn;
            temp=temp->next;
        }
    }
    return revlist;
}
void DFS1_scc(node**adjlist,vector<bool>&visit,vector<int>&f,int u){
    visit[u]=true;
    node*temp=adjlist[u];
    while(temp){
        int v=temp->vertex;
        if(!visit[v])DFS1_scc(adjlist,visit,f,v);
        temp=temp->next;
    }
    f.push_back(u);
}
void DFS2_scc(node**adjlist,vector<bool>&visit,vector<int>&f,int u){
    visit[u]=true;
    f.push_back(u);
    node*temp=adjlist[u];
    while(temp){
        int v=temp->vertex;
        if(!visit[v])DFS2_scc(adjlist,visit,f,v);
        temp=temp->next;
    }
}
vector<vector<int>>SCC(graph*G){
    int n=G->numver;
    vector<bool>visit(n,false);
    vector<int>f;
    for(int i=0;i<n;i++){
        if(!visit[i])DFS1_scc(G->adjlist,visit,f,i);
    }
    reverse(f.begin(),f.end());
    node**revlist=reverseList(G);
    vector<vector<int>>c;
    for(int i=0;i<n;i++)visit[i]=false;
    for(auto&u:f){
        if(!visit[u]){
            vector<int>g;
            DFS2_scc(revlist,visit,g,u);
            c.push_back(g);
        }
    }
    for (int i = 0; i < n; i++) {
        node* temp = revlist[i];
        while (temp) {
            node* prev = temp;
            temp = temp->next;
            delete prev;
        }
    }
    delete[] revlist;
    return c;
}
void S_DFS1_scc(node**adjlist,vector<bool>&visit,stack<int> &S,int u){
    visit[u]=true;
    node*temp=adjlist[u];
    while(temp){
        int v=temp->vertex;
        if(!visit[v])S_DFS1_scc(adjlist,visit,S,v);
        temp=temp->next;
    }
    S.push(u);
}
void S_DFS2_scc(node**adjlist,vector<bool>&visit,vector<int>&comp,int u){
    visit[u]=true;
    comp.push_back(u);
    node*temp=adjlist[u];
    while(temp){
        int v=temp->vertex;
        if(!visit[v]){
            S_DFS2_scc(adjlist,visit,comp,v);
        }
        temp=temp->next;
    }
}
vector<vector<int>>S_SCC(graph*G){
    int n=G->numver;
    stack<int>s;
    vector<bool>visit(n,false);
    for(int i=0;i<n;i++){
        if(!visit[i])S_DFS1_scc(G->adjlist,visit,s,i);
    }
    node**revlist=reverseList(G);
    vector<vector<int>>c;
    for(int i=0;i<n;i++)visit[i]=false;
    while(!s.empty()){
        int u=s.top();
        s.pop();
        if(!visit[u]){
            vector<int>g;
            S_DFS2_scc(revlist,visit,g,u);
            c.push_back(g);
        }
    }
    for (int i = 0; i < n; i++) {
        node* temp = revlist[i];
        while (temp) {
            node* prev = temp;
            temp = temp->next;
            delete prev;
        }
    }
    delete[] revlist;
    return c;
}
int main() {
    // Create a graph with 6 vertices
    graph* G = createGraph(6);

    // Add directed edges
    addEdgeDir(G, 5, 2);
    addEdgeDir(G, 5, 0);
    addEdgeDir(G, 4, 0);
    addEdgeDir(G, 4, 1);
    addEdgeDir(G, 2, 3);
    addEdgeDir(G, 3, 1);

    cout << "Adjacency List:\n";
    print(G);

    // Run DFS
    COLOR c[6];
    int p[6], d[6], f[6];
    cout << "\nDFS:\n";
    DFS(G, p, c, d, f);

    // Topological Sort (DFS-based)
    cout << "\nTopological Sort (DFS): ";
    vector<int> ts = Topological_sort(G, c);
    for (int v : ts) cout << v << " ";
    cout << "\n";

    // Topological Sort (Kahn’s Algorithm)
    cout << "Topological Sort (Kahn): ";
    vector<int> ts2 = Khan(G);
    for (int v : ts2) cout << v << " ";
    cout << "\n";

    // Strongly Connected Components (Kosaraju)
    cout << "SCC (Kosaraju):\n";
    auto comps = SCC(G);
    for (auto &comp : comps) {
        for (int v : comp) cout << v << " ";
        cout << "\n";
    }

    // Strongly Connected Components (Stack-based variant)
    cout << "SCC (Stack-based):\n";
    auto comps2 = S_SCC(G);
    for (auto &comp : comps2) {
        for (int v : comp) cout << v << " ";
        cout << "\n";
    }

    // Clean up memory
    cleanUp(G);

    return 0;
}