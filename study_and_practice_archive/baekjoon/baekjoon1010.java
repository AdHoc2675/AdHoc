import java.util.Scanner;

public class baekjoon1010 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int testCase;
        int n, m;
        long result;

        testCase = s1.nextInt();

        while (true) {
            if (testCase == 0) {
                break;
            }
            testCase--;

            result = 1;
            m = s1.nextInt();
            n = s1.nextInt();

            for (int i = 0; i < m; i++) {
                result = result * (n - i);
                result = result / (1 + i);
            }
            System.out.println(result);
        }
    }
}
