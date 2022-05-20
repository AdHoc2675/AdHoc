import java.util.Scanner;

public class baekjoon2908 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int n1, n2, n3, n4;

        n1 = s1.nextInt();
        n2 = s1.nextInt();

        n3 = n1 / 100 + (n1 % 100 - n1 % 10) + (n1 % 10 * 100);
        n4 = n2 / 100 + (n2 % 100 - n2 % 10) + (n2 % 10 * 100);

        if (n3 > n4) {
            System.out.println(n3);
        } else {
            System.out.println(n4);
        }

    }
}