#include <bits/stdc++.h>
using namespace std;
vector<int> j[3001];
int d[3001],mn,n,a,b,i;
void c(int a,int b){for(int e:j[b]){if(e==a){continue;}if(d[e]>=0){mn=min(mn,d[e]);}else{d[e]=d[b]+1;c(b,e);}}}
int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>n;for(i=1;i<=n;i++){cin>>a>>b;j[a].push_back(b);j[b].push_back(a);}for(i=1;i<=n;i++){mn=3002;fill(d,d+n+1,-1);d[i]=0;c(0,i);cout<<mn<<' ';}}