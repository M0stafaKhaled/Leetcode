class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
          unordered_map<char , int>  box , col , row; 

          
        for(int i =0 ; i<board.size() ; i++)
        {
               row.clear();
            for(int j =0 ;j<board[i].size() ;j++)
            {
             
                    if(col.find(board[i][j]) != col.end() && board[i][j] !='.')
                    return false;
                    else
                    col[board[i][j]]++;
                 if(row.find(board[j][i]) != row.end() && board[j][i] !='.')
                    return false;
                    else
                    row[board[j][i]]++;
               
            }
            col.clear() ; 
        }

        int start =0 ; 
        int end =0 ; 
        int k =9 ;
        while(k--)
        {
            box.clear(); 
            for(int i =0 ; i<3 ;i++)
            {
               for(int j =0 ;j<3 ; j++)
               {
                    if(box.find(board[i+start][j+end])!= box.end() 
                    && board[i+start][j+end] !='.')
                    return false;
                    else
                    box[board[i+start][j+end]]++;
                    cout<<board[i+start][j+end];
               }
            }
         
         end+=3 ; 
         if(end >6)
         {
            start+=3;
            end =0 ;  
         }
            cout<<endl;

        }
        return true ;
    }
};