class Solution {
public:
vector<int> twoSum(vector<int> &arr, int target)
{
    // int start = 0, end = arr.size()-1,sum;
    // while (start < end){
    //     sum=arr[start]+arr[end];
    //     if(sum<target) start++;
    //     else if(sum>target) end--;
    //     else return {start,end};
    // }
    // return{-1,-1};
    map<int,int> hash;
    for (int i=0;i<arr.size();i++){
        int num=arr[i];
        int req=target-num;
        if(hash.find(req)!=hash.end()){
            return {hash[req],i};
        }
        hash[num]=i;
    }
    return {-1,-1};
}
};
