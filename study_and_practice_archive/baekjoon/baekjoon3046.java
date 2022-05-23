import java.util.Scanner;

public class baekjoon3046 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int r1, r2;

        r1 = s1.nextInt();
        r2 = s1.nextInt();

        System.out.println(r2 * 2 - r1);
    }
}