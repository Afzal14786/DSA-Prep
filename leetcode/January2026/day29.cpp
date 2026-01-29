/**
 * Question Link : https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29
 * Solution Link : 
 */

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>

using namespace std;

/**
 * Shortest Path Algorithm  ~ Dijkstra's Algorithm
 */

class Solution {
public:

    void dijistra(int source,vector<pair<int,int>> adj[],vector<vector<int>> &dis){
        dis[source][source]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;

        q.push({0,source});

        while(!q.empty()){
            
            int node = q.top().second;
            q.pop();

            for(auto i: adj[node]){
                int ne = i.second;
                int wt = i.first;

                if(dis[source][ne]>dis[source][node]+wt){
                    dis[source][ne]=dis[source][node]+wt;
                    q.push({dis[source][ne],ne});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        vector<pair<int,int>> adj[26];

        for(int i=0;i<original.size();i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';

            adj[u].push_back({cost[i],v});
        }

        vector<vector<int>> dis(26,vector<int>(26,1e9));
        for(int i=0;i<26;i++){
            dijistra(i,adj,dis);
        }

        long long ans =0;
        for(int i=0;i<source.size();i++){

            int u = source[i]-'a';
            int v = target[i]-'a';

            if(dis[u][v]!=1e9){
                ans+=dis[u][v];
            }else{
                return -1;
            }
        }
        return ans;
        
    }
};


class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> min_size(26,vector<long long>(26,INT_MAX));
        int n=original.size();

        for(int i=0;i<n;i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int w=cost[i];

            if(w<min_size[u][v]){
                min_size[u][v]=w;
            }
        }

        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(min_size[i][via]!= INT_MAX && min_size[via][j]!= INT_MAX){
                        if(min_size[i][via]+min_size[via][j]<min_size[i][j]){
                            min_size[i][j]=min_size[i][via]+min_size[via][j];
                        }
                    }
                }
            }
        }

        int size=source.size();
        long long total_cost=0;

        for(int i=0;i<size;i++){
            if(source[i]!=target[i] ){
                long long cost=min_size[source[i]-'a'][target[i]-'a'];
                if(cost==INT_MAX){
                    return -1;
                }
                total_cost+=cost;
            }
        }
        return total_cost;
    }
};