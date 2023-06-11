class SnapshotArray {
public:
    vector<vector<pair<int, int>>> vec;
    int snapid;
    SnapshotArray(int length) {
        snapid = 0;
        vec.resize(length);
        for(int i = 0; i < vec.size(); i++){
            vec[i].push_back(make_pair(0, 0));
        }
    }
    
    void set(int index, int val) {
        vec[index].push_back({snapid, val});
    }

    int snap() {
        snapid++;
        return snapid-1;
    }
    
    int get(int index, int snap_id) {
        int l = 0, r = vec[index].size()-1;
        
        int result = 0;
        while(l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(vec[index][mid].first <= snap_id) {
                result = vec[index][mid].second;
                l = mid+1;
            } else {
                r = mid-1;
            }
            
        }
        
        return result;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */