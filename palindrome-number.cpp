class Solution {
public:
    bool isPalindrome(int x) {
        char arr[100];
        sprintf(arr, "%d", x);
        int len = strlen(arr);
        int lt = 0, rt = len - 1;
        while (lt < rt) {
            if (arr[lt ++] != arr[rt --]) return false;
        }
        return true;
    }
};