public class uniquecharinstring
{
    public static boolean isUnique(String s)
    {
        boolean[] b = new boolean[128];
        for(int i=0;i<s.length();i++)
        {
            int val = s.charAt(i);
            if(b[val]==true) return false;
            b[val] = true;
        }
        return true;
    }
    public static void main(String[] args)
    {
        String s = "abcd";
        System.out.println(isUnique(s));
    }
}