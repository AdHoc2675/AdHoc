import java.util.Scanner;

public class baekjoon5086 { // 백준 제출시 Main으로
    public static void main(String[] args) {
        int n1, n2;
        Scanner s1 = new Scanner(System.in);

        while (true) {
            n1 = s1.nextInt();
            n2 = s1.nextInt();

            if (n1 == 0 && n2 == 0) {
                break;
            }

            if ((n2 % n1) == 0) {
                System.out.println("factor");
            } else if ((n1 % n2) == 0) {
                System.out.println("multiple");
            } else {
                System.out.println("neither");
            }
        }

        s1.close();
    }
}
