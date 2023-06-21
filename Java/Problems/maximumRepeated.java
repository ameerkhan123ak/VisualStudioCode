/*
 * given two string A and B. write a  program to find the maximum number of times A has to be repeated such that B is a substring of it.
 * input:
 * abcd
 * caabcdab
 * output: 3
 */

public class maximumRepeated {
    public static boolean checkSubstring(String a,String b)
    {
        if(a.length() < b.length()) return false;

        for(int i=0;i<a.length()-b.length();i++)
        {
            String t = a.substring(i,i+b.length());
            if(t.equals(b)) return true;
        }
        return false;
    }
    public static void main(String[] args) {
        String a = "abcd";
        String b = "cdabcdab";
        String t = a;
        int count=1;
        int l1 = a.length();
        int l2 = b.length();
        while(true)
        {
            if(checkSubstring(a, b)==true) break;
            a = a+t;
            count++;
        }
        System.out.println(count);
    }
}
