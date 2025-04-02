class Solution {
    public boolean isPalindrome(int x) {
        int check=x;
        int remainder=0;
        int reverse=0;
        while(x>0){
            remainder=x%10;
            reverse=reverse*10+remainder;
            x=x/10;
        }
        if(check<0){
            return false;
        }
        return(check==reverse);
    }
}
