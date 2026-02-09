#include<iostream>
#include<climits>
#include<queue>
using namespace std;
struct node{
    int vertex;
    node *next;
};
struct graph{
    int numVertex;
    node**adjlist;
};
enum COLOR{white,gray,black};
node *end=new node;
end->next=end;
end->numVertex=-1;
graph* creategraph(int n){
    graph*G=new graph;
    G->numVertex=n;
    G->adjlist=new node*[n];
    for(int i=0;i<n;i++){
        G->adjlist[i]=end;
    }
    return G;
}
node* createnode(int v){
    node*newnode=new node;
    newnode->vertex=v;
    newnode->next=end;
    return newnode;
}

void addEdge_Bi(graph*g,int s,int d){
    node*newnode=createnode(d);
    newnode->next=g->adjlist[s];
    g->adjlist[s]=newnode;
    newnode=createnode(s);
    newnode->next=g->adjlist[d];
    g->adjlist[d]=newnode;   
}
void addEdge_Dir(graph*g,int s,int d){
    node*newnode=createnode(d);
    newnode->next=g->adjlist[s];
    g->adjlist[s]=newnode; 
}
void BFS(graph*g,int s,int*p,int*d){
    int n=g->numVertex;
    for(int i=0;i<n;i++){
        p[i]=-1;
        d[i]=INT_MAX;
    }
    queue<int>Q;
    d[s]=0;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        node*temp=g->adjlist[u];
        while(temp!=end){
            int v=temp->vertex;
            if(d[v]==INT_MAX){
                p[v]=u;
                d[v]=d[u]+1;
                Q.push(v);
            }
            temp=temp->next;
        }
    }
}
void dfs_visit(graph*g,int u,int*p,int*d,int*f,COLOR *color,int&time){
    time=time+1;
    d[u]=time;
    color[u]=gray;
    cout<<"("<<u<<" ";
    node *temp=g->adjlist[u];
    while(temp!=end){
        int v=temp->vertex;
        if(color[v]==white){
            p[v]=u;
            dfs_visit(g,v,p,d,f,color,time);
        }
        temp=temp->next;
    }
    time=time+1;
    f[u]=time;
    color[u]=black;
    cout<<u<<") ";
}
void DFS(graph*g,int*p,int*d,int*f,COLOR *color,int&time){
    int n=g->numVertex;
    for(int i=0;i<n;i++){
        color[i]=white;
        p[i]=-1;
    }
    time=0;
    for(int i=0;i<n;i++){
        if(color[i]==white){
            dfs_visit(g,i,p,d,f,color,time);
        }
    }
}
void print(graph*g){
    int n=g->numVertex;
    for(int i=0;i<n;i++){
        cout<<"Vertex  "<<i<<":";
        node*temp=g->adjlist[i];
        while(temp!=end){
            int v=temp->vertex;
            cout<<v<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
void printPath(int s, int v, int* p) {
    if (v == s) {
        cout << s;
    } else if (p[v] == -1) {
        cout << "No path";
    } else {
        printPath(s, p[v], p);
        cout << " -> " << v;
    }
}
void deleteGraph(graph*g){
    for(int i=0;i<g->numVertex;i++){
        node*temp=g->adjlist[i];
        while(temp!=end){
            node*pre=temp;
            temp=temp->next;
            delete pre;
        }
    }
    delete []g->adjlist;
    delete end;
    delete g;
}
int main() {
    int n = 6;
    graph* G = creategraph(n);
    addEdge_Bi(G, 0, 1);
    addEdge_Bi(G, 0, 2);
    addEdge_Bi(G, 1, 3);
    addEdge_Bi(G, 2, 4);
    addEdge_Bi(G, 3, 5);

    cout << "Adjacency List:\n";
    print(G);

    int* parent = new int[n];
    int* dist = new int[n];

    cout << "\nBFS starting from vertex 0:\n";
    BFS(G, 0, parent, dist);
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": distance = " << dist[i] << ", parent = " << parent[i] << "\n";
    }

    int* dtime = new int[n];
    int* ftime = new int[n];
    COLOR* color = new COLOR[n];
    int time = 0;

    cout << "\nDFS traversal:\n";
    DFS(G, parent, dtime, ftime, color, time);
    cout << "\n";

    delete[] parent;
    delete[] dist;
    delete[] dtime;
    delete[] ftime;
    delete[] color;
    deleteGraph(G);

    return 0;
}