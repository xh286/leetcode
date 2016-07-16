class ZigzagIterator {
int col;
int row;
int count;
int max_count;
vector<int> lengths;
vector<vector<int>> storage;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        lengths.push_back(v1.size());
        lengths.push_back(v2.size());
        storage.push_back(v1);
        storage.push_back(v2);
        max_count = v1.size()+v2.size();
        col = 0;
        row = -1;
        count = 0; // number of elements iterated.
    }

    int next() {
        bool found = false;
        // find next valid location
        while(!found)
        {
            if(row == 1) // already last row
            {
                col++;
                row = 0;
            }
            else
                row++;
            // check if valid
            if(col<lengths[row])
                found = true;
        }
        count++;
        return storage[row][col];
    }

    bool hasNext() {
        return (count<max_count);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */