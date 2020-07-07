class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        //return mincostTicketsFullCalender(days, costs); 
        return mincostTicketsRollingMonth(days, costs);
        //return mincostTicketswithCouponQueues(days,costs);
    }
    int mincostTicketsFullCalender(vector<int>&days, vector<int>& costs)
    {
        
        vector<int> dp(366,0);
        int i = 0;
        for( int x = 1; x < 366 && i < days.size() ; x++)
        {
            if( x != days[i] )
                dp[x] = dp[x-1];
            else
            {
                dp[x] = min({ dp[x - 1] + costs[0], dp[max(0, x - 7)] + costs[1], dp[max(0, x - 30)] + costs[2]});
                if( i < days.size() -1 )
                    i++;
            }
        }
        int lastDay = days.back();
        return dp[lastDay];
    }
    int mincostTicketsRollingMonth(vector<int>& days, vector<int>& costs) 
    {
        vector<int> dp(30);
        int i = 0;
        for( int x = days.front(); x <= days.back() && i < days.size() ; x++)
        {
            if( x != days[i] )
                dp[x%30] = dp[(x-1)%30];
            else
            {
                
                dp[x % 30] = min({ dp[(x - 1) % 30] + costs[0],
                                  dp[max(0, x - 7) % 30] + costs[1],
                                  dp[max(0, x - 30) % 30] + costs[2] });
                if( i < days.size() -1 )
                    i++;
            }
        }
        return dp[days.back()%30];
        
    }
    int mincostTicketswithCouponQueues(vector<int>& days, vector<int>& costs, int cost = 0) 
    {
        queue<pair<int, int>> last7, last30;
        for (auto d : days) 
        {
          while (!last7.empty() && last7.front().first + 7 <= d)
              last7.pop();
          while (!last30.empty() && last30.front().first + 30 <= d)
              last30.pop();
          last7.push({ d, cost + costs[1] });
          last30.push({ d, cost + costs[2] });
            
          cost = min({ cost + costs[0], last7.front().second, last30.front().second });
        }
        return cost;
    }
};
