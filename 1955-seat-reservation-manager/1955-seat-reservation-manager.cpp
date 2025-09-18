class SeatManager {
public:
    set<int> av;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            av.insert(i);
        }
    }

    int reserve() {

        int cur = *av.begin();
        av.erase(av.begin());
        return cur;
    }

    void unreserve(int seatNumber) { av.insert(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */