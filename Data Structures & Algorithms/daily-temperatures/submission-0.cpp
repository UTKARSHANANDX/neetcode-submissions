class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[i] > st.top().first){
                auto p = st.top();
                st.pop();
                result[p.second] = i - p.second;

            }
            st.push({temperatures[i],i});
            
        }
        
        return result;
        
        
    }
};