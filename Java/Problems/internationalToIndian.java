public class internationalToIndian
{
	public static String convertIndianFormat(String s)
	{
		StringBuilder input = new StringBuilder(s);
		int l = input.length();
		for(int i=0;i<l;)
		{
			if(input.charAt(i)==',')
			{
				input.deleteCharAt(i);
				i--;
				l--;
			}
			else if(input.charAt(i)==' ')
			{
				input.deleteCharAt(i);
				i--;
				l--;
			}
			else i++;
		}
		input.reverse();
		StringBuilder inputreverse = new StringBuilder(input);
		StringBuilder output = new StringBuilder();
		for(int i=0;i<l;i++)
		{
			if(i==2)
			{
				output.append(inputreverse.charAt(i));
				output.append(", ");
			}
			else if(i>2 && i%2==0 && i+1<l)
			{
				output.append(inputreverse.charAt(i));
				output.append(", ");
			}
			else 
				output.append(inputreverse.charAt(i));
		}
		output.reverse();
		return output.toString();
	}
	public static void main(String[] args)
	{
		String s = "123, 456, 789";
		String indianFormat = convertIndianFormat(s);
		System.out.println(indianFormat);
	}
}