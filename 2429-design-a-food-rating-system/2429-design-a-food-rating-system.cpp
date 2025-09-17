
struct Compare {
    bool operator()(const pair<int, string>& a,
                    const pair<int, string>& b) const {

        if (a.first > b.first)
            return false;
        if (a.first < b.first)
            return true;

        return a.second > b.second;
    }
};

class FoodRatings {
public:
    // unordered_map<string, priority_queue<pair<int, string>, vector<pair<int,
    // string>>, Compare>> map;
    unordered_map<string, set<pair<int, string>>> st;
    unordered_map<string, int> map1;
    unordered_map<string, string> map2;
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {

        for (int i = 0; i < foods.size(); i++) {

            st[cuisines[i]].insert({-ratings[i], foods[i]});
            map1[foods[i]] = -ratings[i];
            map2[foods[i]] = cuisines[i];
        }
    }

    void changeRating(string food, int newRating) {
        string t = map2[food];
        st[t].erase({map1[food], food});
        map1[food] = -newRating;
        st[t].insert({map1[food], food});
    }

    string highestRated(string cuisine) { return st[cuisine].begin()->second; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */