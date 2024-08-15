class Solution {
    public boolean lemonadeChange(int[] bills) {
        int i,five=0,ten=0;
        for (int x: bills ){
            if(x==5){
                five++;
            } else if (x==10) {
                if (five>=1){
                ten++;
                five--;
                }
                else return false;
            }
            else {
                if(five>=1 && ten>=1){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
            }
        return true;
    }
}
