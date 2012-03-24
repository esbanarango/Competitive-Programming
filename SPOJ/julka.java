/*
  54 - Julka
  SPOJ
  Esteban Arango Medina
  
  Solution:
    Simply shows the advantage of Java over C++ = BigInteger. :P
*/
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;
import java.math.BigInteger;

public class julka {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	
	public static void main(String[] args) throws NumberFormatException, IOException  {
		int cases = 10;
		BigInteger dos = new BigInteger("2");
		Scanner sc = new Scanner(System.in);
		while(cases--!=0){
			BigInteger a= sc.nextBigInteger();
			BigInteger b= sc.nextBigInteger();
			BigInteger c =a.add(b);
			c = c.divide(dos);
			BigInteger n =a.subtract(b);
			n=n.divide(dos);
			System.out.println(c);
			System.out.println(n);
		}
	}

}
