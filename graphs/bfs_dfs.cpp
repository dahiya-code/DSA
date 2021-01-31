#include <bits/stdc++.h>
using namespace std;
 
#define modulo 10000007
#define int long long 
#define N 1000000001
#define cons 200001
#define endl "\n"


std::vector<int> adj[cons];
bool vis[cons];
queue<int>q;//contains nodes to be processed in inc order of their distance
int dist[cons];

void dfs(int curr){
    if(vis[curr])return;
    cout<<curr;
    vis[curr]=1;
    for(auto i:adj[curr])
        dfs(i);
}
void bfs(int start){
    vis[start]=true;
    dist[start]=0;
    q.push(start);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr;
        for(int i:adj[curr]){
            if(vis[i])continue;
            vis[i]=true;
            dist[i]=dist[curr]+1;
            q.push(i);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        int n=7;
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        bfs(0);
    }
}
