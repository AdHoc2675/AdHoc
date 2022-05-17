import java.util.Scanner;

public class baekjoon1712 { // 백준엔 Main으로 제출
    public static void main(String[] args) {
        int a, b, c;
        int sell_count;

        Scanner s1 = new Scanner(System.in);

        a = s1.nextInt();
        b = s1.nextInt();
        c = s1.nextInt();

        if (b >= c) {
            System.out.println("-1");
        } else {
            sell_count = a / (c - b) + 1;
            System.out.println(sell_count);
        }

        s1.close();

    }
}
