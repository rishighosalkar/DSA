You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Intuition

The problem is to insert a new interval into an already sorted, non-overlapping list of intervals, and merge if needed.

Instead of inserting first and then merging later, this solution does everything in one pass.

Key Idea

While iterating through existing intervals, we compare each interval with newInterval and handle three cases:

1. New interval comes completely before the current interval

  -No overlap

  -Add newInterval to the result

  -Treat the current interval as the new interval to process next

2. New interval comes completely after the current interval

  -No overlap

  -Add the current interval to the result

3. Intervals overlap

  -Merge them by expanding newInterval

  -Do NOT add anything yet (keep merging)

At the end, add the final merged newInterval.

This ensures:

*Single pass

*No extra sorting

*Clean merging logic

Step-by-Step Dry Run

Input
```
intervals = [[1,3], [6,9]]
newInterval = [2,5]
```

Initialization
```
ans = []
newInterval = [2,5]
```

Iteration 1 → interval = [1,3]

Check overlap conditions:

*newInterval[1] < interval[0] → 5 < 1 ❌

*newInterval[0] > interval[1] → 2 > 3 ❌

Overlap detected

Merge:
```
newInterval[0] = min(2, 1) = 1
newInterval[1] = max(5, 3) = 5
```

Now:
```
newInterval = [1,5]
ans = []
```

Iteration 2 → interval = [6,9]

Check conditions:

*newInterval[1] < interval[0] → 5 < 6 ✅

New interval ends before current interval starts

Actions:
```
ans.add([1,5])
newInterval = [6,9]
```

Now:
```
ans = [[1,5]]
```

After Loop Ends

Add remaining newInterval:
```
ans.add([6,9])
```

Final Output
```
[[1,5], [6,9]]
```

Why This Works Well

*Only one pass through the intervals → O(n) time

*No additional space except the result list → O(n) space

*Merges intervals on the fly

*Handles all edge cases:

  -Empty intervals

  -New interval before all

  -New interval after all

  -Full overlap

Complexity Analysis
```
Time Complexity	O(n)
Space Complexity	O(n)
```