// O(length)

class Solution {
public:
    long long tot;
    unordered_map<string, long long> s2l;
    unordered_map<long long, string> l2s;
    
    unordered_map<char, int> c2i;
    unordered_map<int, char> i2c;
    
    Solution() {
        tot = 0;
        int t = 0;
        for (int i = 0; i < 10; i ++) {
            c2i[i + '0'] = t;
            i2c[t] = i + '0';
            t ++;
        }
        for (int i = 0; i < 26; i ++) {
            c2i[i + 'a'] = t;
            i2c[t] = i + 'a';
            t ++;
        }
        for (int i = 0; i < 26; i ++) {
            c2i[i + 'A'] = t;
            i2c[t] = i + 'A';
            t ++;
        }
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        s2l[longUrl] = tot;
        l2s[tot] = longUrl;
        tot ++;
        string res = "";
        long long z = tot - 1;
        for (int i = 0; i < 6; i ++) {
            res.push_back(i2c[z % 62]);
            z /= 62;
        }
        return "http://tinyurl.com/" + res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl = shortUrl.substr(19);
        long long z = 0;
        for (int i = 5; i >= 0; i --) {
            z = z * 62 + c2i[shortUrl[i]];
        }
        return l2s[z];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));