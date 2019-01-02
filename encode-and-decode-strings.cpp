// length + '#' + string

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (string& s : strs)
            res += to_string(s.length()) + "#" + s;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int lt = 0;
        while (lt < s.length()) {
            int n = 0;
            while (s[lt] != '#') n = n * 10 + s[lt ++] - '0';
            lt ++;
            res.push_back(s.substr(lt, n));
            lt += n;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));