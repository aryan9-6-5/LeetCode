class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& vec) {
    int n=vec.size();
    double wt=vec[0][1];
    double at=wt+vec[0][0];
    for(int i=1;i<n;i++){
        if(at<vec[i][0]) at=vec[i][0];
        wt+=at+vec[i][1]-vec[i][0];
        at=at+vec[i][1];
    }
    return wt/n;
    }
};
