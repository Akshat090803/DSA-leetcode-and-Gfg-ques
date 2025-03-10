class Solution {
public:
  

bool checkPossible(int row, int col, int num, vector<vector<char>>& board) {

  char val = '0' + num;
  // check for row i.e,num must occur exactly once in each row.
  for (int j = 0; j < 9; j++) {
      if (board[row][j] == val)
          return false;
  }

  // check for col i.e,num must occur exactly once in each col.
  for (int i = 0; i < 9; i++) {
      if (board[i][col] == val)
          return false;
  }

  //! check in sub-box /block of size 3x3
  //?for getting starting ind of row for subbox
  int row_ind_subBox;
  int col_ind_subBox;
  // if (row >= 0 && row < 3) {
  //     row_ind_subBox = 0; // for row 0,1,2 subbox startinf row is 0
  // } else if (row >= 3 && row < 6) {
  //     row_ind_subBox = 3; // for row 3,4,5 subbox starting row is 3
  // } else if (row >= 6 && row < 9) {
  //     row_ind_subBox = 6; // for row 6,7,8 subbox starting row is 6
  // }
  // //?simialrly for columns
  // if (col >= 0 && col < 3) {
  //     col_ind_subBox = 0; // for col 0,1,2 subbox startinf col is 0
  // } else if (col >= 3 && col < 6) {
  //     col_ind_subBox = 3; // for col 3,4,5 subbox starting col is 3
  // } else if (col >= 6 && col < 9) {
  //     col_ind_subBox = 6; // for col 6,7,8 subbox starting col is 6
  // }

  //! or instead of above if else condiiton we can do

  row_ind_subBox = (row / 3) * 3;
  col_ind_subBox =
      (col / 3) * 3; // we will get same value as of if else if condition

  // subbox is of size 3x3
  for (int a = row_ind_subBox; a < row_ind_subBox + 3; a++)
      for (int b = col_ind_subBox; b < col_ind_subBox + 3; b++) {
          if (board[a][b] == val)
              return false;
      }

  return true;
}
bool find(int row, int col, vector<vector<char>>& board) {

  // base condiiton
  if (row == 9)
      return true; // means we have filled aposition with correct numbers
                   // in each row
           
        
    
  // we are assigning value col wise for each row i.e, for row 0 col 0 we
  // make call for row 0 col 1 than in row 0,col1 func call we make call
  // for row 0 col3. if we reached col 9 () menas all all col for that row
  // assigned a value so no move to next row .//?Thast why below condiiton
  if (col == 9)
      return find(row + 1, 0, board);

  if (board[row][col] != '.') {
        return find(row, col + 1, board); // Skip filled cells
    }    


  for (int x = 1; x <= 9; x++) {

      if (checkPossible(row, col, x, board)) {
          board[row][col] =
              '0' + x; // converting 9 to '9' as it is char arr
          // we are assigning value col wise for each row i.e, for row 0
          // col 0 we make call for row 0 col 1 than in row 0,col1 func
          // call we make call for row 0 col3.
          bool ret_val = find(row, col + 1, board);
          // if func return true menas the no. assign is  correct
          if (ret_val) { 
              return true;
          }
              

          // else
          board[row][col] = '.'; // backtrack
          // remove number and will check for new number
      }
  }

  return false; // after checking posssiblity of all no. we still not
                // assign a number return false;
}
void solveSudoku(vector<vector<char>>& board) { find(0, 0, board); }
};