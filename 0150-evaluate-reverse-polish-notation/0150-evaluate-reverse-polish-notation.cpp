class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk ; 
        for(int i =0 ; i<tokens.size() ; i++)
        {
            
          if(tokens[i] != "+" &&tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "/")
          {
            stk.push(stoi(tokens[i]));
          }
          else
          {
            int a = stk.top();
            stk.pop();
            int b = stk.top() ;
            stk.pop();
            int t = 0 ; 
            if(tokens[i] == "+")
            t = a+b ;
            else if (tokens[i] == "-")
            {
                t = b -a ; 
            }
            else if (tokens[i] == "*")
            t= a *b ; 
            else  t = b/a ;
            stk.push(t);
          }
        }

        return stk.top() ; 
    }
};