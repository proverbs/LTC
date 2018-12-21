// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    string rm;
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        n -= rm.length();
        if (rm.length()) strncpy(buf, rm.c_str(), rm.length());
        int len = rm.length();
        while (n > 3) {
            int cnt = read4(buf + len);
            len += cnt;
            n -= 4;
        } 
        if (n) {
            int cnt = read4(buf + len);
            len += cnt;
            n -= cnt;
        }
        cout << n << endl;
        rm = "";
        while (n < 0) {
            rm.push_back(buf[len + n]);
            buf[len + n] = '\0';
            n ++;
        }
        return len;
    }
};