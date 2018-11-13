// the total number of <prefix, suffix> is not too large
// time complexity: WordFilter: O(NL^2), f: O(1)
// space complexity: O(NL^2)

#include <map>

class WordFilter {
public:
    unordered_map<string, int> score;
    WordFilter(vector<string> words) {
        score.clear();
        for (int i = 0; i < words.size(); i ++) {
            for (int j = 0; j <= words[i].size(); j ++) {
                for (int k = 0; k <= words[i].size(); k ++) {
                    string prefix = words[i].substr(0, j);
                    string suffix = words[i].substr(k);
                    prefix += "@" + suffix;
                    score[prefix] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        prefix += "@" + suffix;
        if (score.count(prefix)) return score[prefix];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */