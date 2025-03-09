class Solution {
// private:
    // int tle(vector<int>& colors, int k){
    //     int start = 0, ans = 0, n = colors.size();
    //     for(int i=0; i<n-1; i++) {
    //         if(colors[i] == colors[i+1]) {
    //             start = i+1;
    //             break;
    //         }
    //     }
    //     while(start<colors.size()) 
    //     {
    //         bool isAlternate = true;
    //         int end = start+k-1;
    //         for(int i=start; i<=end; i++) 
    //         {
    //             if(i>start && i < end && (colors[i%n] == colors[(i-1)%n]
    //             || colors[i%n] == colors[(i+1)%n])) 
    //             {
    //                 isAlternate = false;
    //                 break;
    //             }
    //             else if(i == start && colors[i%n] == colors[(i+1)%n]) 
    //             {
    //                 isAlternate = false;
    //                 break;
    //             }
    //             else if(i == end && colors[i%n] == colors[(i-1)%n]) 
    //             {
    //                 isAlternate = false;
    //                 break;
    //             }
    //         }
    //         if(isAlternate)
    //             ans++;
    //         start++;
    //     }

    //     return ans;
    // }
public:
int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0; i<k-1; i++) {
            colors.push_back(colors[i]);
        }
        int start = 0, end = 1, ans=0;
        while(end<colors.size()) {

            if(colors[end] == colors[end-1]) {
                start = end;
                end++;
                continue;
            }
            end++;
            if(end-start < k) continue;
            start++;
            ans++;
        }

        return ans;
    }
};