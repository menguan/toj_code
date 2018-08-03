import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
	public static void main(String args[])
    {
		Scanner in=new Scanner(System.in);
		BigInteger s;int a;
		s=in.nextBigInteger();
		a=in.nextInt();
		s=s.pow(a);
		char[] ch=s.toString().toCharArray();
		for(int i=0;i<ch.length;i++)
		{
			System.out.print(ch[i]);
			if((i+1)%70==0)
			{
				System.out.println("");
			}
		}
		if(ch.length%70!=0)
		  System.out.println("");
    }

}
