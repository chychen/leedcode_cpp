// Given two strings s and t, write a function to determine if t is an anagram of s.

// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.

// Note:
// You may assume the string contains only lowercase alphabets.

// input:
// ""
// ""
// "anagram"
// "nagaram"
// output:
// true
// true

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        map<char, int> sss, ttt;
        for(auto it: s){
            if(sss.find(it)==sss.end()){
                sss[it] = 1;
            }else{
                sss[it]++;
            }
        }
        for(auto it: t){
            if(ttt.find(it)==sss.end()){
                ttt[it] = 1;
            }else{
                ttt[it]++;
            }
        }
        for(auto it: ttt){
            //cout<<"k:"<<it.first<<" v:"<<it.second<<endl;
            //cout<<"k:"<<it.first<<" v:"<<sss[it.first]<<endl;
            if(it.second != sss[it.first]){
                return false;
            }
        }
        return true;
    }
};

// better and neat
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};