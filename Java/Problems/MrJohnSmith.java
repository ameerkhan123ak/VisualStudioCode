public class MrJohnSmith
{
    public static void main(String[] args)
    {
        String s = "Mr John Smith";
        s = s.trim();
        s = s.replaceAll("//s", "%20");
        System.out.println(s);
    }
}