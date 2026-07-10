class Solution {
public:
    string minWindow(string s, string t) {
        if(!t.size())return "";
        unordered_map<char,int> freqT;
        unordered_map<char,int> window;
        for(auto c:t){
            freqT[c]++;
        }
        int have = 0;
        int need = freqT.size();
        pair<int,int> res = {-1,-1};
        int resLen = INT_MAX;
        int l = 0;
        for(int r = 0; r < s.length() ; r++){
            char c = s[r];
            window[c]++;
            if(freqT.count(c) && window[c] == freqT[c]){
                have++;
            }
            while(have == need){
                if((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l,r};

                }
                window[s[l]]--;
                if(freqT.count(s[l]) && window[s[l]] < freqT[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ?"":s.substr(res.first,resLen);

    }
};
