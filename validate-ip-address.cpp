class Solution {
public:
    string validIPAddress(string IP) {
        if (check(IP)) return check_ipv4(IP);
        else return check_ipv6(IP);
    }
    
    bool check(string ip) {
        for (int i = 0; i < ip.length(); i ++) {
            if (ip[i] == '.') return true;
            if (ip[i] == ':') return false;
        }
        return true;
    }
    
    string check_ipv4(string ip) {
        int x = 0, w = 0;
        int res = 0;
        for (int i = 0; i <= ip.length(); i ++) {
            if (i == ip.length() || ip[i] == '.') {
                if (w == 0) return "Neither";
                if (w > 1 && x < pow(10, w - 1)) return "Neither";
                res ++;
                x = 0;
                w = 0;
            } else if (ip[i] >= '0' && ip[i] <= '9') {
                w ++;
                x = x * 10 + ip[i] - '0';
                if (w > 3 || x >= 256) return "Neither";
            } else {
                return "Neither";
            } 
        }
        return res == 4 ? "IPv4" : "Neither";
    }
    
    string check_ipv6(string ip) {
        int x = 0, w = 0;
        int res = 0;
        for (int i = 0; i <= ip.length(); i ++) {
            if (i == ip.length() || ip[i] == ':') {
                if (w == 0) return "Neither";
                res ++;
                x = 0;
                w = 0;
            } else if (ip[i] >= '0' && ip[i] <= '9') {
                w ++;
                x = x * 10 + ip[i] - '0';
                if (w > 4 || x >= (1 << 16)) return "Neither";
            } else if (ip[i] >= 'a' && ip[i] <= 'f') {
                w ++;
                x = x * 10 + ip[i] - 'a' + 10;
                if (w > 4 || x >= (1 << 16)) return "Neither";
            } else if (ip[i] >= 'A' && ip[i] <= 'F') {
                w ++;
                x = x * 10 + ip[i] - 'A' + 10;
                if (w > 4 || x >= (1 << 16)) return "Neither";
            } else {
                return "Neither";
            } 
        }
        return res == 8 ? "IPv6" : "Neither";
    }
};