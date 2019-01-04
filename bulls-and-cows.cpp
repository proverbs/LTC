class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> cow;
        int nb = 0, nc = 0;
        for (int i = 0; i < secret.length(); i ++) {
            if (guess[i] != secret[i]) {
                if (cow.count(secret[i])) cow[secret[i]] ++;
                else cow[secret[i]] = 1;
            }
        }
            
        for (int i = 0; i < secret.length(); i ++) {
            if (guess[i] == secret[i]) nb ++;
            else if (cow.count(guess[i])) {
                if (cow[guess[i]] > 0) nc ++, cow[guess[i]] --;
            }
        }
        string res = to_string(nb) + "A" + to_string(nc) + "B";
        return res;
    }
};