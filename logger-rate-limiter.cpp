// map

class Logger {
public:
    unordered_map<string, int> ts;
    /** Initialize your data structure here. */
    Logger() {
        ts.clear();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (ts.count(message)) {
            if (ts[message] + 10 <= timestamp) {
                ts[message] = timestamp;
                return true;
            } else {
                return false;
            }
        } else {
            ts[message] = timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */