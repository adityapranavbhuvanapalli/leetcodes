class SnapshotArray {
public:
    int snaps = 0;
    vector<vector<pair<int, int>>> snapshotArray;
    SnapshotArray(int length) {
        snapshotArray = vector<vector<pair<int, int>>>(length, {{0, 0}});
    }
    
    void set(int index, int val) {
        if(snapshotArray[index].back().first < snaps) {
            snapshotArray[index].push_back({snaps, val});
            return;
        }

        snapshotArray[index].back().second = val;
    }
    
    int snap() {
        return snaps++;
    }
    
    int get(int index, int snap_id) {
        // Find the id which is the greatest id <= snap_id
        // i.e., the last good element

        auto& array = snapshotArray[index];
        int n = array.size(), l = 0, r = n - 1, mid;

        while(l < r) {
            mid = l + ceil((r - l) / 2.0);

            if(array[mid].first > snap_id) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }

        return array[r].second;
    }
};

/*
I(3) ->     [0,0,0]
SET(0, 5)   [5,0,0]
SNAP()      0
GET(0, 0)   5


0 -> {0, 5}, {1, 7}, {2, 6}
1 -> {0, 3}
2 -> {0, 7}, {2, 3}
*/

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */