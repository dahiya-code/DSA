#include <bits/stdc++.h>
using namespace std;
 
#define modulo 10000007
#define int long long 
#define N 200005
#define INF 1e9
#define endl "\n"

std::vector<pair<int,int> > adj[N];
int visited[N], parent[N], distance[N];

void djikstra(int curr){
    for(int i=1;i<=5;i++)distance[i]=INF;
    distance[curr]=0;
    priority_queue<pair<int, int> >q;
    q.push({0, curr});
    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if (visited[a]) continue;
        for(int i:adj[a]){
            int b = i.first, w = i.second;
            if (distance[a] + w < distance[b]){
                distance[b] = distance[a] + w;
                parent[b] = a;
                q.push({ -distance[b], b});
            }
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
        int n=5;
        for(int i=0;i<n+1;i++){
            int a,b,w;
            cin>>a>>b>>w;
            adj[a].push_back({b,w});
        }
    }
}