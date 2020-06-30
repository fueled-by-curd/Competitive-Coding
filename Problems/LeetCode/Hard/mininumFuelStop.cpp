class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        priority_queue<int> maxFuelStation;
        int stops = 0;
        int stopNumber = 0;
        int tank = startFuel;
        while( tank < target)
        {
            while(stopNumber < stations.size() && stations[stopNumber][0] <= tank)
                maxFuelStation.push(stations[stopNumber++][1]);
            
            if(maxFuelStation.empty())
                return -1;
            
            tank += maxFuelStation.top();
            maxFuelStation.pop();
            stops++;
        }
        
        return stops;
    }
};
