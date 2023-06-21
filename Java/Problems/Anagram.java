import java.util.*;

public class Anagram {
    public static boolean areAnagram(char ch1[],char ch2[])
    {
        int n1 = ch1.length;
        int n2 = ch2.length;

        if(n1!=n2) return false;

        Arrays.sort(ch1);
        Arrays.sort(ch2);

        for(int i=0;i<n1;i++)
        {
            if(ch1[i]!=ch2[i])
            return false;
        }
        return true;
    }
    public static void main(String[] args) {
        String s1 = "listen";
        String s2 = "silent";

        char ch1[] = s1.toCharArray();
        char ch2[] = s2.toCharArray();

        System.out.println(areAnagram(ch1,ch2));
    }
}
