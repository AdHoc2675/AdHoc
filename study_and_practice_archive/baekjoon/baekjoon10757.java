import java.math.BigInteger;
import java.util.Scanner;

public class baekjoon10757 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        BigInteger a;
        BigInteger b;
        BigInteger sum;

        a = s1.nextBigInteger();
        b = s1.nextBigInteger();

        sum = a.add(b);

        System.out.println(sum.toString());
    }
}