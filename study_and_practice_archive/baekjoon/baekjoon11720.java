import java.util.Scanner;

public class baekjoon11720 {
    public static void main(String[] args) {
        int n;
        String a;
        int sum = 0;

        Scanner s1 = new Scanner(System.in);

        n = s1.nextInt();
        a = s1.next();

        for (int i = 0; i < n; i++) {
            sum = sum + a.charAt(i) - '0';
        }

        System.out.print(sum);

        s1.close();
    }
}
