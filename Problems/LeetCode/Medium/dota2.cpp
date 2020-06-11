class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        int count = 0;
        
        int D = 0;
        int R = 0;
        int once = 1;
        bool clearWinner = false;
        while(!clearWinner)
        {
            for(int i = 0; i < senate.size(); i++)
            {
                if( senate[i] == 'D')
                {
                    count++;
                    if( count <=0 )
                    {
                        senate[i] = 'B';
                        D--;
                    }
                     D += once;
                       
                }
                else if( senate[i] == 'R')
                {
                    count--;
                    if( count >= 0)
                    {
                        senate[i] = 'B';
                        R--;
                    }
                    R += once ;
                    
                }
            }
            once = 0;        
               if( D <= 0 || R <= 0)
                   clearWinner = true;
                
        }
        
        
        
        if( D <= 0)
            return "Radiant";
        
        return "Dire";
        
    }
};
