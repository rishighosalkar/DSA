public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        
        List<int[]> ans = new();

        if(intervals.Length == 0){
            ans.Add(new int[] {newInterval[0], newInterval[1]});
            return ans.ToArray();
        }

        foreach(var interval in intervals)
        {
            if(newInterval[1] < interval[0])
            {
                ans.Add(newInterval);
                newInterval = interval;
            }
            else if(newInterval[0] > interval[1])
            {
                ans.Add(interval);
            }
            else
            {
                newInterval[0] = Math.Min(newInterval[0], interval[0]);
                newInterval[1] = Math.Max(newInterval[1], interval[1]);
            }
        }
        
        ans.Add(newInterval);
        return ans.ToArray();
    }
}