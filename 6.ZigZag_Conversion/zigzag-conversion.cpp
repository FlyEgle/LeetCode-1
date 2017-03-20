class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> zigzag(numRows);
        int index = 0, length = s.length();

        while (index < length) {
            for (int i = 0; i < numRows; i++) {
                if (index >= length) break;
                zigzag[i] += s[index++];
            }
            for (int i = numRows - 2; i > 0; i--) {
                if (index >= length) break;
                zigzag[i] += s[index++];
            }
        }

        string result;
        for (int i = 0; i < zigzag.size(); i++) {
            result += zigzag[i];
        }

        return result;
    }
};
