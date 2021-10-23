import java.util.*;
public class lengthOfLongestSubstring{
     public static int lengthOfLongestSubstringfunction(String s) {
        
        int winStart = 0 ;
        int winEnd = 0 ;
        int max = 0 ;
        Set<Character> set = new HashSet<>();
        
        while(winEnd < s.length()){
            char curr = s.charAt(winEnd);
            
            if(!set.contains(curr)){
                set.add(curr);
                winEnd++;
                max = Math.max(max , set.size());
            }else{
                set.remove(s.charAt(winStart++));
            }
            
            
        }
        
        return max;  
    }
     public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter substring in lower case letters: ");
        String s = sc.next();
        
        System.out.println("length of Longest Substring Without Repeating Characters is "+lengthOfLongestSubstringfunction(s));
        sc.close();
     }
}

