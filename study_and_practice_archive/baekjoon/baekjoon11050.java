import java.util.Scanner;

public class baekjoon11050 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int n, m;
        long result;

        result = 1;
        n = s1.nextInt();
        m = s1.nextInt();

        for (int i = 0; i < m; i++) {
            result = result * (n - i);
            result = result / (1 + i);
        }

        System.out.println(result);
    }
}
