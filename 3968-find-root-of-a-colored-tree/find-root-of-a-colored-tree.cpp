class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        
        vector<int> indegree(colors.size(),0);
        vector<int> outdegree(colors.size(),0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            if(colors[u] == 'R'){
                if(colors[v] == 'W'){
                    
                    indegree[u]++;
                    outdegree[v]++;
                }
                else if(colors[v] == 'B'){
                    
                    indegree[v]++;
                    outdegree[u]++;
                }
                else return -1;
            }
            else if(colors[u] == 'W'){
                if(colors[v] == 'R'){
                    
                    indegree[v]++;
                    outdegree[u]++;
                }
                else if(colors[v] == 'B'){
                    
                    indegree[u]++;
                    outdegree[v]++;
                }
                else return -1;
            }
            else if(colors[u] == 'B'){
                if(colors[v] == 'R'){
                    
                    indegree[u]++;
                    outdegree[v]++;
                }
                else if(colors[v] == 'W'){
                    
                    indegree[v]++;
                    outdegree[u]++;
                }
                else return -1;
            }
        }
        int ans = -1;
        for(int i=0;i<colors.size();i++){
            if(indegree[i] == 0 && ans == -1) ans = i;
            else if(indegree[i] == 0 && ans != -1) return -1;
            if(outdegree[i] >= 3) return -1;
        }
        return ans;
    }
};