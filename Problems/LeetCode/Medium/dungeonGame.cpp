class Solution {
public:
    map<pair<int,int>,int> pos;
    int X;
    int Y;
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        X = dungeon.size()-1;
        Y = dungeon[0].size()-1;
        //cout<< X << " " << Y << endl;
        int ans = travel(dungeon, 0 ,0);
        
        if( ans > 0)
            return 1;
        return -ans + 1;
        
        
        
    }
    int travel(vector<vector<int>>& dungeon, int i, int j)
    {
        if( i == X && j == Y)
            return dungeon[X][Y];
        
        if(pos.find({i,j}) != pos.end())
        {
            //cout<< i << " " << j << endl;
            return pos[{i,j}];
        }
        
        int ans = 0;
        if( i == X && j < Y)
            ans = min(dungeon[X][j],dungeon[X][j]+ travel(dungeon,X,j+1));
        else if( i < X && j == Y)
            ans = min(dungeon[i][Y],dungeon[i][Y] + travel(dungeon,i+1,Y));
        else
        {
            int ans1 = min(dungeon[i][j], dungeon[i][j] + travel(dungeon,i+1,j));
            int ans2 = min(dungeon[i][j],dungeon[i][j] + travel(dungeon,i,j+1));
            ans = max(ans1,ans2);
        }
        
        pos[{i,j}] = ans;
        //cout<< i << " " << j << endl;
            
        return ans;
        
    }
    
};
