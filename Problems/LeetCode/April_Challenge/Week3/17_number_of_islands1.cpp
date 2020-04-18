
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j] == '1')
                {
                    count++;
                    dfs_expand(i,j,grid);
                    
                }
                
        }
        
        /*
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
        */
        
        return count;
        
    }

   
    void dfs_expand(int u,int v, vector<vector<char>>& grid ) 
    {
        int r = grid.size();
        int c = grid[0].size();
        if(u<0 || u>=r || v >= c || v<0 || grid[u][v] != '1')
            return;
        
        //cout << "H" << endl;
        grid[u][v] = 'X';
        
        dfs_expand(u,v+1,grid);
        dfs_expand(u,v-1,grid);
        dfs_expand(u+1,v,grid);
        dfs_expand(u-1,v,grid);
        
            
    } 
};
