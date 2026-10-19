class Solution {
public:

    int row =0,col =0;

    void iter(vector<vector<bool>> &visited,vector<vector<char>> &grid,int l,int r){
        if(l<0 || r<0 || l>=grid.size() || r>=grid[0].size()) return;
        if(visited[l][r]) return;
        row = l;
        col = r;
        visited[row][col] = true;
        char dir = grid[l][r];
        if(dir == 'U') iter(visited,grid,l-1,r);
        else if(dir == 'D') iter(visited,grid,l+1,r);
        else if(dir == 'L') iter(visited,grid,l,r-1);
        else if(dir == 'R') iter(visited,grid,l,r+1);
        return;
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool> (grid[0].size(),false));
        iter(visited,grid,0,0);
        return {row,col};
    }
};