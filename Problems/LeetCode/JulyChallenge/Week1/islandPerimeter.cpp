class Solution {
public:
    vector<int> dr = { -1,1,0, 0};
    vector<int> dc = { 0, 0,1,-1};
    int R,C;
    int ans ;
    bool isOkay(int i,int j) // function to check if i,j is accessible( Here, used for edge detection as well)
    {
        if( i <0 || i >=R || j <0 || j >= C)
            return false;
        return true;
    }
    int surroundings(int i, int j,vector<vector<int>>& grid )
    {
        int ctr = 0;
        for( int k = 0; k < 4; k++)
        {
            if(!isOkay(i+dr[k],j + dc[k]))//edge detection for a piece of land
                ctr++;
            else
                ctr+= ((grid[i+dr[k]][j+dc[k]]) == 0) ? 1 : 0;//find number of surrounding water bodies
        }
        return ctr;
    }
    void floodFill(vector<vector<int>>& grid, int i, int j)
    {
        if(!isOkay(i,j))
            return;
        if( grid[i][j] != 1)
            return;
        grid[i][j] = 2;// coloring the land differently
        ans += surroundings(i,j,grid);// adding number of edges around land at i,j to global ans
        
        for(int k = 0 ; k < 4; k++)
            floodFill(grid,i+dr[k], j+dc[k]);
            
        
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        ans = 0;
        R  = grid.size();
        C = grid[0].size();
        int r = -1;
        int c = -1;
        // finding first occurrence of land and stopping since Q mentions only one piece of land
        for( int i = 0 ;i < grid.size(); i++)
        {
            for( int j = 0; j < grid[0].size(); j++)
                if( grid[i][j] == 1)
                {
                    //cout<< i << " " << j << endl;
                    r = i;
                    c = j;
                    break;
                }
            
            if( r > 0 && c  > 0)
                break;
        }
        floodFill(grid,r,c);
        
        return ans;
        
    }
    
    
};
