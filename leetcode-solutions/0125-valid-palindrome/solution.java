class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int len=s.length();
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < len; i++) {
            char c = s.charAt(i);  // Corrected from str.charAt(i)
            if (Character.isLetterOrDigit(c)) {  // Corrected condition
                str.append(c);
            }
        }
        return checkPalindrome(str.toString());
    }
    
    public boolean checkPalindrome(String str) {
        int start=0,end=str.length()-1;
        boolean flag=true;
        while (start<end){
            if (str.charAt(start)!=str.charAt(end)){
                flag=false;
                break;
            }
            start++;
            end--;
        }
        return flag;
    }
}
