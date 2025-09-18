class SeatManager {
public:
    set<int> av;
    set<int> unv;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            av.insert(i);
        }
    }

    int reserve() {

        int cur = *av.begin();
        av.erase(av.begin());
        unv.insert(cur);
        return cur;
    }

    void unreserve(int seatNumber) {

        unv.erase(seatNumber);
        av.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */