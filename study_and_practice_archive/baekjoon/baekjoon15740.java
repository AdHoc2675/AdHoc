import java.util.Scanner;
import java.math.BigInteger;

public class baekjoon15740 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        BigInteger n, m;

        n = s1.nextBigInteger();
        m = s1.nextBigInteger();

        System.out.println(n.add(m));
    }
}
