class Spreadsheet {
public:
    int n;
    unordered_map<string, int> map;
    Spreadsheet(int rows) { n = rows; }

    void setCell(string cell, int value) { map[cell] = value; }

    void resetCell(string cell) { map[cell] = 0; }

    int getValue(string cell) {
        string c1 = "";
        string c2 = "";
        int i = 1;
        bool c1_d = true;
        bool c2_d = true;
        while (i < cell.size() && cell[i] != '+') {
            if (!isdigit(cell[i]))
                c1_d = 0;
            c1 += cell[i++];
        }
        i++;
        while (i < cell.size() && cell[i] != '+') {
            if (!isdigit(cell[i]))
                c2_d = 0;
            c2 += cell[i++];
        }
        int d1 = map[c1];
        int d2 = map[c2];
        if (c1_d) {
            d1 = stoi(c1);
        }
        if (c2_d) {
            d2 = stoi(c2);
        }

        return d1 + d2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */