class Solution {
public:
    vector<int> ans;
    bool iscycle(int idx,vector<vector<int>>& adj,vector<int>& vis){
        
        vis[idx]=2;
        for(int i=0;i<adj[idx].size();i++){
            if(vis[adj[idx][i]]==2){
                return true;
            }
            else if(vis[adj[idx][i]]==0){
                if(iscycle(adj[idx][i],adj,vis)){
                    return true;
                }
            }
        }
        
        ans.push_back(idx);
        vis[idx]=1;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        for(auto i:pre){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(iscycle(i,adj,vis))
                    return {};
            }
        }
        return ans;
    }
};
