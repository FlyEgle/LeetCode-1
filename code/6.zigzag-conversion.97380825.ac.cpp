/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion
 *
 * Medium (26.53%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""\n1'
 *
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 */
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
