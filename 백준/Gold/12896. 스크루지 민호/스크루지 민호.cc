/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int dist[100001];
queue<int> Q;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    fill(dist + 1, dist + n + 1, -1);
    
    dist[1] = 0;
    Q.push(1);
    while(!Q.empty()) {
        int k = Q.front();
        Q.pop();
        for (int e: adj[k]) {
            if (dist[e] >= 0) continue;
            dist[e] = dist[k] + 1;
            Q.push(e);
        }
    }
    
    int p = max_element(dist + 1, dist + n + 1) - dist;
    
    fill(dist + 1, dist + n + 1, -1);
    
    dist[p] = 0;
    Q.push(p);
    while(!Q.empty()) {
        int k = Q.front();
        Q.pop();
        for (int e: adj[k]) {
            if (dist[e] >= 0) continue;
            dist[e] = dist[k] + 1;
            Q.push(e);
        }
    }
    
    int mx = *max_element(dist + 1, dist + n + 1);
    cout << mx / 2 + mx % 2;

    return 0;
}
