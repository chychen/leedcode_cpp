// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// For example,

// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].


//my solution
//EXCEED TIME LIMIT QQ
class Solution
{
  public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        //result list_of_sub-seq
        vector<string> result;
        if (s.length() <= 10)
            return result;
        //for loop travel along the whole string
        for (int i = 0; i <= s.length() - 11; i++)
        { //-20: double length of 10-letter-long seq
            //temp sub-seq = 10-chars-long-seq
            string temp = s.substr(i, 10);
            //for loop to compare each sub-seq to temp
            bool flag = true;
            for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
            {
                if (!(*it).compare(temp))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int j = i + 1; j <= s.length() - 10; j++)
                {
                    string cmp = s.substr(j, 10);
                    //if temp as same as any other seq
                    if (!temp.compare(cmp))
                    {
                        //append temp to list_of_sub-seq
                        result.push_back(temp);
                        break;
                    }
                }
            }
        }
        return result;
    }
};
//better solution
class Solution
{
  public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        char flag[262144] = {0};
        vector<string> result;
        int len, DNA = 0, i;
        if ((len = s.length()) < 11)
            return result;
        for (i = 0; i < 9; i++)
            DNA = DNA << 2 | (s[i] - 'A' + 1) % 5;
        for (i = 9; i < len; i++)
        {
            DNA = (DNA << 2 & 0xFFFFF) | (s[i] - 'A' + 1) % 5;
            if (!(flag[DNA >> 2] & (1 << ((DNA & 3) << 1))))
                flag[DNA >> 2] |= (1 << ((DNA & 3) << 1));
            else if (!(flag[DNA >> 2] & (2 << ((DNA & 3) << 1))))
            {
                result.push_back(s.substr(i - 9, 10));
                flag[DNA >> 2] |= (2 << ((DNA & 3) << 1));
            }
        }
        return result;
    }
};
