import java.util.Scanner;

public class baekjoon1676 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int n;
        int count5 = 0;
        int count25 = 0;
        int count125 = 0;

        n = s1.nextInt();
        count5 = n / 5;
        count25 = n / 25;
        count125 = n / 125;

        System.out.println(count5 + count25 + count125);
    }
}