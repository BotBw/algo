class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        mx = 0
        for st, en in intervals:
            mx = max(mx, st, en)
        diff = [0 for _ in range(mx + 2)]
        for st, en in intervals:
            diff[st] += 1
            diff[en] -= 1
        ans = cur = diff[0]
        for d in diff[1:mx + 1]:
            cur += d
            ans = max(ans, cur)
        return ans
