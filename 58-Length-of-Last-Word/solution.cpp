class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream in(s);
        string last_word;
        while(in >> last_word)
        {}
        return last_word.size();
    }
};