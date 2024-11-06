class Solution {
    public boolean isSubsequence(String s, String t) {
        int l=0,m=0,len1=s.length(),len2=t.length();
        while (l<len1 && m<len2){
            if (s.charAt(l)==t.charAt(m)){
                l++;
            }
            m++;
        }
        return l==len1;
    }
}
