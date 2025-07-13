class Solution {
public:
    long long  db[101][101][207] ;
    bool vist[100][100] ;
    bool isvalid(vector<vector<int>>& grid , int x , int y)
    {
        if(x>=grid.size() || x<0 || y<0 || y>= grid[0].size() || grid[x][y] ==1 ) return 0; 

        return 1 ; 
    }
    int dir[5] = {1, 0 , -1 , 0  ,1} ;

    long long  solve(vector<vector<int>>& grid , int x , int y , int f)
    {
        if(x+1 == grid.size() && y+1 == grid[0].size()) return 1; 
       if(f>204) return INT_MAX; 
        if(x > grid.size()) return INT_MAX ;
        if(y > grid.size()) return INT_MAX ; 
        long long  ans =INT_MAX ; 
        if(db[x][y][f]  != -1)  return db[x][y][f]  ;
        for(int i  =0 ; i<4 ; i++)
        {
            int dx = x+dir[i] ; 
            int dy = y+dir[i+1] ; 

            if(isvalid(grid , dx ,dy))
            {
                grid[dx][dy] = 1; 
                ans =  min(ans , solve(grid , dx , dy , f+1)+1) ; 
                grid[dx][dy] = 0; 
                
            }
        }

        if(isvalid(grid , x+1 , y+1))
        {
            grid[x+1][y+1] = 1; 
             ans =  min(ans , solve(grid , x+1 ,  y+1 , f+1)+1) ; 
              grid[x+1][y+1] = 0; 
        }

         if(isvalid(grid , x-1 , y-1))
        {
             grid[x-1][y-1] = 1; 
             ans =  min(ans , solve(grid , x-1 ,  y-1  , f+1)+1) ;
              grid[x-1][y-1] = 0;  
        }

         if(isvalid(grid , x-1 , y+1))
        {
             grid[x-1][y+1] = 1; 
             ans =  min(ans , solve(grid , x-1 ,  y+1 , f+1)+1) ; 
              grid[x-1][y+1] = 0; 
        }
         if(isvalid(grid , x+1 , y-1))
        {
             grid[x+1][y-1] = 1; 
             ans =  min(ans , solve(grid , x+1 ,  y-1 , f+1)+1) ; 
               grid[x+1][y-1] = 0; 
        }

        return db[x][y][f] = ans ; 
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if (grid[0][0] == 1)
            return -1;

        long long  ans = INT_MAX;
        memset(db , -1 , sizeof db) ; 
      
        ans = min(ans, solve(grid, 0, 0 , 0));
        grid[0][0] =1 ; 
        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};