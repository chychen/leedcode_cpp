// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Note: In the string, each word is separated by single space and there will not be any extra space in the string.

class Solution {
public:
    string reverseWords(string s) {
        string result = " "+s+" ";
        int spaceIdx=0,oldSpaceIdx=0;
        for(int i =0;i<result.length();i++){
            if(result[i]==' '){
                oldSpaceIdx=spaceIdx;
                spaceIdx=i;
                int startIdx = oldSpaceIdx+1;
                int endIdx = spaceIdx-1;
                for(int j=0;j<(endIdx-startIdx+1)/2;j++){
                    char temp = result[j+startIdx];
                    result[j+startIdx] = result[endIdx-j];
                    result[endIdx-j] = temp;
                }
            }
        }
        return result.substr(1,s.length());   
    }
};
// other's solution
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {   // when i is a non-space
                int j = i;
                for (; j < s.length() && s[j] != ' '; j++) { } // move j to the next space
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        
        return s;
    }
};