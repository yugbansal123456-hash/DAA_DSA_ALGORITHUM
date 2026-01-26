class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> list;
        for(auto &word:strs){
            string key=word;
            sort(key.begin(),key.end());
            list[key].push_back(word);
        }
        vector<vector<string>> ans;
        for(auto &i:list){
            ans.push_back(i.second);
        }
        return ans;
    }
};