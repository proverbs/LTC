class Solution {
public:
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        mp.clear();
        for (int i = 0; i < paths.size(); i ++) {
            string path;
            vector<string> filenames, contents;
            interpret(paths[i], path, filenames, contents);
            for (int i = 0; i < contents.size(); i ++) {
                string &content = contents[i];
                string &filename = filenames[i];
                // cout << path << " " << filename << "  " << content << endl;
                if (!mp.count(content)) mp[content] = vector<string>();
                mp[content].push_back(path + "/" + filename);
            }
        }
        unordered_map<string, vector<string>>::iterator it;
        vector<vector<string>> res;
        for (it = mp.begin(); it != mp.end(); it ++) {
            if (it->second.size() > 1) res.push_back(it->second);
        }
        return res;
    }
    
    void interpret(string &s, string &path, vector<string> &filenames, vector<string> &contents) {
        int lt = 0;
        while (s[lt] != ' ') path.push_back(s[lt ++]);
        lt ++;
        while (lt < s.length()) {
            string filename, content;
            while (s[lt] != '(') filename.push_back(s[lt ++]);
            lt ++;
            while (s[lt] != ')') content.push_back(s[lt ++]);
            lt += 2;
            filenames.push_back(filename);
            contents.push_back(content);
        }
    }
};