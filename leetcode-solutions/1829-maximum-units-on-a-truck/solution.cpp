class Solution {
public:
    int maximumUnits(vector<vector<int>>& vec, int truckSize) {
    sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1]; 
    });
    int count=0;
    for(int i=0;i<vec.size() && truckSize>0;i++){
        int length=vec[i][0];
        if(truckSize-length>0) count+=length*vec[i][1];
        else {
            count+= truckSize* vec[i][1];
        }
        truckSize-=length;
    }
    return count;
    }
};
