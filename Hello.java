package hello;

import java.util.Scanner;

public class Hello {

	public static void main(String[] args) {
	// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int[] primes = new int[50];
		primes[0] = 2;
		int cnt = 1;
		MAIN_LOOP:
		for(int x = 3;cnt<primes.length;x++)
		{
			for(int i = 0;i<cnt;i++)
			{
				if(x%primes[i]==0)
				{
					continue MAIN_LOOP;
				}
			}
			primes[cnt++] = x;
		}
		for(int k:primes)
		{
			System.out.println(k);
		}
		
	}

}
