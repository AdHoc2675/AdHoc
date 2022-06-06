import java.util.Scanner;

public class baekjoon2420 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        long n, m;

        n = s1.nextLong();
        m = s1.nextLong();

        System.out.println(Math.abs(n - m));

    }
}
