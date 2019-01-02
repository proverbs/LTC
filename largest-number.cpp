class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int x : nums) v.push_back(to_string(x));
        sort(v.begin(), v.end(), cmp);
        string res;
        for (string& a : v) res += a;
        
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};