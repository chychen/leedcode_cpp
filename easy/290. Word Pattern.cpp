// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

// my solution
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> table;
        std::string delimiter = " ";
        istringstream f(str);
        string token;  
        for(auto p: pattern){  
            if(!getline(f, token, ' '))return false;
            auto iter = table.find(p);
            if(iter==table.end()){
                table.insert(pair<char, string>(p, token));
            }else{
                if(iter->second!=token)return false;
            }
        }
        if(getline(f, token, ' '))return false;
        
        for(auto iter:table){
            for(auto iter2:table){
                if(iter.first!=iter2.first){
                    if(iter.second==iter2.second)return false;
                }
            }
        }
        return true;
    }
};
