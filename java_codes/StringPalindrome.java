public class StringPalindrome {
    public static void main(String[] args) {
        String str = "";
        System.out.println(isPalindrome(str));

    }
    static boolean isPalindrome(String str){
        int start = 0;
        int end = str.length()-1;
        if(str.length() == 0){
            return true;
        }
        while(start<end){
            if(str.charAt(start) == str.charAt(end)){
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }
}
