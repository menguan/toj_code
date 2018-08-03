import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
	public static void main(String args[])
    {
		Scanner in=new Scanner(System.in);
		BigInteger b,a,bas,t1,t2;
		int count=0;;
		b=in.nextBigInteger();
		a=in.nextBigInteger();
		bas=BigInteger.valueOf(1);
		t1=BigInteger.valueOf(1);
		while(a.compareTo(bas)>=0)
		{
			count++;
			a=a.subtract(bas);
			bas=bas.multiply(b);
		}
		while(count>0)
		{
			count--;
			bas=bas.divide(b);
			System.out.print(a.divide(bas).add(t1));
			a=a.mod(bas);
		}
		System.out.println("");
		//a=in.nextInt();
		
    }

}
