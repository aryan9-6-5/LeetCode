class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        int maxlen=(int) (n/3)+1;
        int c1=0,c2=0;
        int e1=INT_MIN,e2=INT_MIN;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]==e1) c1++;
            else if(arr[i]==e2) c2++;
            else if(c1==0){
                c1=1;
                e1=arr[i];
            }
            else if(c2==0){
                c2=1;
                e2=arr[i];
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==e1) c1++;
            if(arr[i]==e2) c2++;
        }
        if(e1==e2 && c1>=maxlen) ans.push_back(e1);
        else{
            if(c1>=maxlen) ans.push_back(e1);
            if(c2>=maxlen) ans.push_back(e2);
        }
        return ans;
    }
};
