class Solution {
public:
    string winningPlayer(int x, int y) {

        bool ans = true;

        while (true) {
            if (y < 4 || x < 1) {
                if (ans)
                    return "Bob";
                else
                    return "Alice";
            }
            x--;
            y -= 4;
            ans = !ans;
        }
        return "Alice";
    }
};