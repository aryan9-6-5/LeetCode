class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int target=0;
        int count=0;
        for(int x:apple){
            target+=x;
        }
        int x=0;
        while(target>0 && x<capacity.size()){
            target-=capacity[x];
            count++;
            x++;
        }
        return count;
    }
};
