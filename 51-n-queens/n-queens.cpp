class Solution {
public:
//!This checkDiagonal func used in way-1
    //  bool checkDiagonal(int row,int col,int n,vector<string>&Board){
    //     int i=row;
    //     int j=col;
    //     //for checking left upper diagonel
    //     //col will decrese and row also decrease
    //     while(i>-1 && j>-1){
    //         if(Board[i][j]=='Q') return 0; //queen already present in diagonal    
    //         i--;
    //         j--;
    //     }

    //     i=row; j=col;
    //     //for checking Right upper diagonel
    //     //col will increase and row  decrease
    //     while(i>-1 && j<n){
    //         if(Board[i][j]=='Q') return 0; //queen already present in diagonal
    //         j++;//col increase
    //         i--;
    //     }

    //     return 1; //else true no quuen in diagonal

    //  }

//!way-1 where we use checkDiagonal func for diagonal safety
    //  void find(int row,int n,vector<vector<string>>&ans,vector<string>&Board,vector<bool>&column){

    //  //!base condition
    // //  suppose for n=4 so 4 queen will place at row 0 , 1 , 2 and 3
    //  //now if we not able to place queen in any of above row , we return back from that row
    //  //but if we reach row==n measn we have successfully place all queens in respective row
    //  //thats why base condition if row===n (menas queen placed in all rows) than we push board in ans and return
    //  if(row==n){
    //     ans.push_back(Board);
    //     return;
    //  }


    //  for(int col=0;col<n;col++){
         
    //      //!for way-1 where we use checkDiagonal Func for diagonal checking
    //     if( column[col]==0 && checkDiagonal(row,col,n,Board)){
    //         //?if all condtion met for placing queen
    //         //place queen
    //         Board[row][col]='Q';
    //         //mark column reserved for that quuen
    //         column[col]=1;
    //         //make call for next row queen
    //         find(row+1 , n , ans, Board, column);

    //         //?during backtracking
    //         //remove queen form place
    //         Board[row][col]='.';
    //          // unmark column reserved for that quuen
    //         column[col]=0;

    //     }
    //  }
    //  }

//!way-2 we not use check_diagonal func 
//but still the overall time complexity will be same to way-1
     void find_2(int row,int n,vector<vector<string>>&ans,vector<string>&Board,vector<bool>&column,vector<bool>&leftDiagonal,vector<bool>&rightDiagonal){

     //!base condition
    //  suppose for n=4 so 4 queen will place at row 0 , 1 , 2 and 3
     //now if we not able to place queen in any of above row , we return back from that row
     //but if we reach row==n measn we have successfully place all queens in respective row
     //thats why base condition if row===n (menas queen placed in all rows) than we push board in ans and return
     if(row==n){
        ans.push_back(Board);
        return;
     }


     for(int col=0;col<n;col++){
         
        int ind_for_leftDiag_Arr=(n-1)+col-row;
        int ind_for_rightDiag_Arr=row+col;
        //see .tldr file for why?

        if( column[col]==0 && leftDiagonal[ind_for_leftDiag_Arr]==0 && rightDiagonal[ind_for_rightDiag_Arr]==0){
            //?if all condtion met for placing queen
            //place queen
            Board[row][col]='Q';
            //mark column reserved for that quuen
            column[col]=1;
            //mark left diagonal reserved for queen
            leftDiagonal[ind_for_leftDiag_Arr]=1 ;
            //mark right diagonal reserved
             rightDiagonal[ind_for_rightDiag_Arr]=1;

            //make call for next row queen
            find_2(row+1 , n , ans, Board, column,leftDiagonal,rightDiagonal);

            //?during backtracking
            //remove queen form place
            Board[row][col]='.';
             // unmark column reserved for that quuen
            column[col]=0;
             // unmark left diagonal reserved for queen
            leftDiagonal[ind_for_leftDiag_Arr]=0;
            //unmark right diagonal reserved
             rightDiagonal[ind_for_rightDiag_Arr]=0;

        }
     }
     }
    vector<vector<string>> solveNQueens(int n) {

        //!time -> O(N!) 
        //as for row 1 we check for N col , row 2 we check for N-1 col, row 3 we check for N-2 col
        //so N*(N-1)*(N-2)*.....*1 => N!
        //!Space - O( N*N ) due to  vector<string>Board(n); 1-D arr of str consider as 2d arr of char

        //in way-2 for checking for diagonals still the overall complexity will still be same  //!time -> O(N!) 
        //but we reduced the time for checking diagonal safety to O(1)
        //so code will optimised little bit

        vector<vector<string>>ans; //which we will return

        vector<string>Board(n);
        //arr of string can be visualize as 2d arr of char
        //initializing borad wit "." and repalce "." with "Q" where Q can be fit
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        Board[i].push_back('.');

        //this can be done like this Board[i]="...." //suppose for n=4
        //means we first genrate string af length n and than Board[i]=that_str

        vector<bool>column(n,0); //to ensure in each col only one queen present
        //!This below two vector will use in way-2 where instead of using check() func for diagonal we will use this two arrays
        vector<bool>leftDiagonal(n,0);
        vector<bool>rightDiagonal(n,0);
        
        int row=0;//start form row=0
        // find(row,n,ans,Board,column);
          find_2(row , n , ans, Board, column,leftDiagonal,rightDiagonal);

        return ans;

    }
};