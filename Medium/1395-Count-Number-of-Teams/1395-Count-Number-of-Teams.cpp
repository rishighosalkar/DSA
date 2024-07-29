class Solution {
private:
    int recurrIncreasing(vector<int>& rating, int ind, int n, int teamSize, 
    vector<vector<int>>& dp){
        if(ind == n)
            return 0;

        if(teamSize == 3){
            return 1;
        }
        if(dp[ind][teamSize] != -1)
            return dp[ind][teamSize];
        int ans = 0;
        for(int i=ind+1; i<n; i++){
            if(rating[i] > rating[ind])
                ans += recurrIncreasing(rating, i, n, teamSize+1, dp);
        }

        return dp[ind][teamSize] = ans;
    }
    
    int recurrDecreasing(vector<int>& rating, int ind, int n, int teamSize, 
    vector<vector<int>>& dp){
        if(ind == n)
            return 0;

        if(teamSize == 3){
            return 1;
        }

        if(dp[ind][teamSize] != -1)
            return dp[ind][teamSize];
        
        int ans = 0;
        for(int i=ind+1; i<n; i++){
            if(rating[i] < rating[ind])
                ans += recurrDecreasing(rating, i, n, teamSize+1, dp);
        }

        return dp[ind][teamSize] = ans;
    }
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        vector<vector<int>> dp(rating.size()+1, vector<int>(rating.size()+1, -1));
        for(int i=0; i<rating.size(); i++){
            ans += recurrIncreasing(rating, i, rating.size(), 1, dp);
        }

        vector<vector<int>> dp1(rating.size()+1, vector<int>(rating.size()+1, -1));
        
        for(int i=0; i<rating.size(); i++){
            ans += recurrDecreasing(rating, i, rating.size(), 1, dp1);
        }

        return ans;
    }
};