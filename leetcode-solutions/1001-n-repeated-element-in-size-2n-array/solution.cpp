class Solution {
public:
    int repeatedNTimes(vector<int>& arr) {
        int n=arr.size()/2;
        unordered_map<int,int> hash;
        for(int x: arr){
            hash[x]++;
            if(hash[x]>1) return x;
        }
        return -1;
    }
};
