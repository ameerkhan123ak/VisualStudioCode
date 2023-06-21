public class AddDigits {
    public static int addDigits(int num)
    {
        if(num==0) return 0;
        int sum=0;
        while(num>0)
        {
            sum += num%10;
            num/=10;

            if(num==0 && sum>9)
            {
                num = sum;
                sum=0;
            }
        }
        return sum;
    }
    public static void main(String[] args) {
        int num=1234;
        System.out.println(addDigits(num));
    }    
}
