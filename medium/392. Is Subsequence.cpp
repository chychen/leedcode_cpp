class Solution {
public:
    bool isSubsequence(string s, string t) {
        int startIdx = 0;
        bool flg = false;
        for(auto it_s: s){
            for(int j = startIdx;j<t.size();j++){
                if(t[j] == it_s){
                    startIdx = j+1;
                    flg = true;
                    break;
                }
            }
            if(!flg)return false;
            flg = false;
        }
        return true;
    }
};
// cool sol in C
bool isSubsequence(char* s, char* t) {
    while (*t)
        s += *s == *t++;
    return !*s;
}
