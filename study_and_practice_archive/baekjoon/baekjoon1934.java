import java.util.Scanner;

public class baekjoon1934 { // 제출시 Main

    public static int find_GCD(int n1, int n2) {
        int n3 = n1 % n2;

        while (true) {
            if (n3 == 0) {
                break;
            }
            n1 = n2;
            n2 = n3;
            n3 = n1 % n2;
        }

        return n2;
    }

    public static void main(String[] args) {
        int n1, n2;
        int re1, re2;
        int repeat;

        Scanner s1 = new Scanner(System.in);

        repeat = s1.nextInt();

        while (true) {
            if (repeat == 0) {
                break;
            }
            repeat--;
            n1 = s1.nextInt();
            n2 = s1.nextInt();

            if (n1 > n2) {
                re1 = find_GCD(n1, n2);
            } else {
                re1 = find_GCD(n2, n1);
            }

            re2 = (n1 / re1) * (n2 / re1) * re1;
            System.out.println(re2);
        }

        s1.close();
    }

}
