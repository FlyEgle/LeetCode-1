/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku
 *
 * algorithms
 * Medium (35.57%)
 * Total Accepted:    122.2K
 * Total Submissions: 343.5K
 * Testcase Example:  '[".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]'
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only
 * the filled cells need to be validated.
 * 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool usedRow[9][9] = {0};
        bool usedCol[9][9] = {0};
        bool usedBox[9][9] = {0};

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if ('.' != board[i][j]) {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;

                    if (usedRow[i][num] || usedCol[j][num] || usedBox[k][num])
                        return false;

                    usedRow[i][num] = usedCol[j][num] = usedBox[k][num] = true;
                }
            }
        }

        return true;
    }
};
