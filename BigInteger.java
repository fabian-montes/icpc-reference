import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

// uso basico de array list y big integer para calcular factorial 
// java nombre_archivo.java
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("n = ");
		int n = sc.nextInt(); // sc.nextBigInteger();
		ArrayList<BigInteger> F = new ArrayList<BigInteger>();
		F.add(BigInteger.ONE);
		for(int i=1; i<=n; i++) {
			BigInteger x = BigInteger.valueOf(i);
			BigInteger fi_1 = F.get(i-1);
			BigInteger fi = fi_1.multiply(x);
			F.add(fi);
		}
		System.out.printf("%d! = %s\n", n, F.get(n).toString());
	}
}