#include<bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<vector<int>> &v,int root){
    queue<int> q;
    vector<int> vis(v.size()+1,0);
    vector<int> bfs;
    q.push(root);
    vis[root]=1;
    while (!q.empty())
    {
        // cout<<"loop";
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto it:v[curr]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

void dfsTraversal(vector<vector<int>> &v,int root,int parent){
    cout<<root<<" ";
    for (auto it:v[root])
    {
        if(it!=parent) dfsTraversal(v,it,root);
    }
    
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>());
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfsTraversal(v,0);
    cout<<"\n";
    dfsTraversal(v,0,-1);
    




}