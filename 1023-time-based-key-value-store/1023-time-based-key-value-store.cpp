class TimeMap {
    private:
        unordered_map<string, vector<pair<int, string>>> time_map;
        int max_timestamp;
    public:
        TimeMap() {}
        

        void set(string key, string value, int timestamp) {
            time_map[key].push_back({timestamp, value});
        }
        

        string get(string key, int timestamp) {
            
            int left = 0, right = time_map[key].size() - 1;

            while (left <= right) 
            {
                int mid = (left + right)/2;
                int dummy = time_map[key][mid].first;

                if (dummy == timestamp) 
                {
                    return time_map[key][mid].second;
                }

                if (dummy > timestamp)
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            if (right == -1) return "";
            
            return time_map[key][right].second;

        }   
};