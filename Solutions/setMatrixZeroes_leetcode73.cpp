/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place. 
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]] */

// solution

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        queue<pair<int,int>> q;
        
        vector<int> row(n,0); // initialize a row vector to keep track of visited rows.
        vector<int> col(m,0); //  initialize a col vector to keep track of visited columns.
        
        for(int i=0; i<n; i++)      // run a nested for loop to traverse the whole matrix and push all pairs of row,col with 0 value to a queue.
        {
          for(int j=0; j<m; j++)
          {
             if(matrix[i][j] == 0)
                 q.push({i,j});
          }
        }
        
        while(!q.empty())  // run  a loop till queue is empty.
        {
         auto val = q.front();
         q.pop();
            
         if(row[val.first] != 1)    // check whether the row is visited or not.
         {
         for(int k=0; k<m; ++k)     // if not visited then make all its elements as zeros.
         {
          matrix[val.first][k] = 0;
         }
         row[val.first] =1;          // set the row as visited in row vector.
         }
            
         if(col[val.second] != 1)     // check whether the column is visited or not.
         {
         for(int k=0; k<n; ++k)         // if not visited then make all its elements as zeros.
         {
          matrix[k][val.second] = 0;
         }
         col[val.second] = 1;           // set the row as visited in col vector.
         }
            
        }
    }
};


