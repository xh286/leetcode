class Solution {
private:
    bool matched(vector<vector<char>>& board, int m, int n, int ii, int jj, string word)
    {
        int len = word.size();
        if(len == 1) return true;
        
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        visited[ii][jj] = true;
        stack<pair<pair<int,int>,int>> m_stack;
        m_stack.push({{ii,jj},0});
        int l = 1; //trying to match word[1] here.
        while(!m_stack.empty())
        {
            //probe all 4 directions
            pair<pair<int,int>,int>& cur = m_stack.top();
            int i = cur.first.first;
            int j = cur.first.second;
            if(cur.second >= 4)
            {// all directions probed, failed to match word[l].
                m_stack.pop();
                visited[i][j] = false;
                l--;
                continue;
            }
            if(cur.second == 0)
                i = i-1;
            else if(cur.second == 1)
                j = j-1;
            else if(cur.second == 2)
                i = i+1;
            else if(cur.second == 3)
                j = j+1;
            cur.second++;
            if(i>=0 && i<m && j>=0 && j<n && !visited[i][j] && board[i][j] == word[l])
            {
                m_stack.push({{i,j},0});
                visited[i][j] = true;
                l++;
                if(l==len) return true;
            }
        }
        assert(l==0);
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Brute force. Iterate through first char. Then for each matching first char, start from there and try to match. If any one matches, return true. If algorithm finishes, return false.
        // Try to match: using a stack, look into all directions, if all directions explored, still no match, give up (reset stack and visited map). If matched, set visited mark for the entry, and push. If next to match is \0, then success.
        if(word.size()==0) return true;
        int m = board.size();
        if(m==0) return false;
        int n = board[0].size();
        if(n==0) return false;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == word[0] && matched(board, m, n, i, j, word)) 
                    return true;
        return false;
    }
};