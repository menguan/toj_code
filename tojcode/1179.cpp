import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main {

	public static void main(String[] args)
	{
		Scanner cin =new Scanner(System.in);
		BigInteger t1,t2,dp[]=new BigInteger[110];
	    dp[1]=BigInteger.valueOf(1);
	    for(int i=2;i<=100;i++)
	    {
	    	t1=BigInteger.valueOf(4*i-2);
	    	t2=BigInteger.valueOf(i+1);
	    	dp[i]=dp[i-1].multiply(t1).divide(t2);
	    }
	    while(cin.hasNext())
	    {
	    	int id=cin.nextInt();
	    	if(id==-1)
	    		break;
	    	System.out.println(dp[id]);
	    }
	}
	
}
