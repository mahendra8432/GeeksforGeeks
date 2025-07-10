class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string longest = "";

        for (const string& word : words) {
            if (word.size() == 1 || built.count(word.substr(0, word.size() - 1))) {
                built.insert(word);
                if (word.size() > longest.size()) longest = word;
            }
        }

        return longest;
    }
};
