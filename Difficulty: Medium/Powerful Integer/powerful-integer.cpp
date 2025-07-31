class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> events;
        for (auto& i : intervals) {
            events[i[0]]++;
            events[i[1] + 1]--;
        }
        int count = 0, result = -1;
        for (auto& e : events) {
            if (e.second > 0) {
                count += e.second;
                if (count >= k) result = e.first;
            } else {
                if (count >= k) result = e.first - 1;
                count += e.second;
            }
        }
        return result;
    }
};