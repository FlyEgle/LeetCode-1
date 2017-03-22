/* INT_MAX 2147483647 */

class Solution {
public:
    int myAtoi(string str) {
        int result = 0, sign = 1;
        int i = str.find_first_not_of(' ');
        int base = INT_MAX / 10;

        if (str[i] == '+' || str[i] == '-')
            sign = (str[i++] == '+') ? 1 : -1;

        while (isdigit(str[i])) {
            if (result > base || (result == base && str[i] - '0' > 7))
                return sign > 0 ? INT_MAX : INT_MIN;
            result = result * 10 + (str[i++] - '0');
        }

        return sign * result;
    }
};
