// Given an array of strings, group anagrams together.

// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:

// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note: All inputs will be in lower-case.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        map<string, vector<string>> mapSortedOri;
        for(auto iter: strs){
            string buffer=iter;
            sort(buffer.begin(), buffer.end());
            auto findedIter = mapSortedOri.find(buffer);
            if (findedIter == mapSortedOri.end()){
                vector<string> tempVector;
                tempVector.push_back(iter);
                mapSortedOri.insert(pair<string, vector<string>>(buffer, tempVector));
            }else{
                findedIter->second.push_back(iter);
            }
        }
        for(auto iter: mapSortedOri){
            result.push_back(iter.second);
        }
        
        return result;
    }
};

// wow, someone use prime instead!!!!!!!!!
// java code
public static List<List<String>> groupAnagrams(String[] strs) { 
    int[] prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};//最多10609个z

    List<List<String>> res = new ArrayList<>();
    HashMap<Integer, Integer> map = new HashMap<>();
    for (String s : strs) {
        int key = 1;
        for (char c : s.toCharArray()) {
            key *= prime[c - 'a'];
        }
        List<String> t;
        if (map.containsKey(key)) {
            t = res.get(map.get(key));
        } else {
            t = new ArrayList<>();
            res.add(t);
            map.put(key, res.size() - 1);
        }
        t.add(s);
    }
    return res;
}