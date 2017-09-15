/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search
 *
 * algorithms
 * Medium (26.63%)
 * Total Accepted:    138.7K
 * Total Submissions: 514.2K
 * Testcase Example:  '["ABCE","SFCS","ADEE"]\n"ABCCED"'
 *
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * 
 * 
 * For example,
 * Given board = 
 * 
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (exist(board, i, j, word.c_str())) return true;

        return false;
    }

private:
    bool exist(vector<vector<char>>& board, int x, int y, const char* word) {
        if (!word[0]) return true;
        if (0 > x || x == board.size() || 0 > y || y == board[x].size()) return false;
        if (board[x][y] != word[0]) return false;

        board[x][y] ^= 511;
        if (exist(board, x - 1, y, word + 1)
            || exist(board, x + 1, y, word + 1)
            || exist(board, x, y - 1, word + 1)
            || exist(board, x, y + 1, word + 1))
            return true;
        board[x][y] ^= 511;

        return false;
    }
};
