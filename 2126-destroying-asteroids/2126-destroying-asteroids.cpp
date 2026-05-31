class Solution {
public:
    bool asteroidsDestroyed(int s, vector<int>& asteroids) {
        long long mass = s;
        sort(asteroids.begin(), asteroids.end());

        for (int i = 0; i < asteroids.size(); i++) {
            if (mass < 0)
                return 0;
            if (mass >= asteroids[i]) {
                mass += asteroids[i];
            } else
                mass -= asteroids[i];
        }

        return mass >= 0;
    }
};