public class numberInDigits {

    public static boolean checkNumbers(int i,int d)
    {
        while(i>0)
        {
            if(i%10==d) break;
            i/=10;
        }
        return i>0;
    }
    public static void printNumbers(int n,int d)
    {
        for(int i=0;i<n;i++)
        {
            if(i==d || checkNumbers(i,d))
            {
                System.out.print(i + " ");
            }
        }
    }
    public static void main(String[] args) {
        int n = 50;
        int d =2;
        printNumbers(n,d);
    }
}
