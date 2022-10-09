class Solution {
public:
    bool issafe(vector<vector<char>>&board, int row, int col, char &val){
        for(int i=0;i<9;i++){
            if(board[row][i]==val)
                return false;
            if(board[i][col]==val)
                return false;
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val)
                return false;
        }
        return true;
    }
    bool rec(vector<vector<char>>&board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char c='1';c<='9';c++){
                        if(issafe(board,row,col,c)){
                            board[row][col]=c;
                            if(rec(board))
                                return true;
                            else
                                board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        rec(board);
    }
};
