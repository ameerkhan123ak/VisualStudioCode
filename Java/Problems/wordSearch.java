public class wordsearch {
    public static boolean checksubString(String s,String word)
    {
        for(int i=0;i<3;i++)
        {
            //System.out.println(s.substring(i,i+3));
            if(s.substring(i,i+3).equals(word)) return true;
        }
        return false;
    }
    public static boolean checkHorizontal(char[][] arr,String word)
    {
        for(int i=0;i<5;i++)
        {
            String s = "";
            for(int j=0;j<5;j++)
            {
                s += arr[i][j];
            }
            boolean b = checksubString(s,word);
            if(b==true) 
            {
                System.out.println("horizontal");
                return true;
            }
        }
        return false;
    }
    public static boolean checkVertical(char[][] arr,String word)
    {
        for(int i=0;i<5;i++)
        {
            String s = "";
            for(int j=0;j<5;j++)
            {
                s += arr[j][i];
            }
            boolean b = checksubString(s,word);
            if(b==true) 
            {
                System.out.println("vertical");
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args)
    {
        char arr[][] = new char[][]
                        {{'w','e','l','c','o'},
                        {'m','e','t','o','z'},
                        {'o','h','o','c','o'},
                        {'r','p','o','r','a'},
                        {'t','i','o','n','y'}};

        String word = "too";
        boolean a = checkHorizontal(arr,word);    
        boolean b = checkVertical(arr, word);          
    }
}
