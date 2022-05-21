import java.util.Scanner;

public class baekjoon2475 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int num;
        int powsum = 0;
        for (int i = 0; i < 5; i++) {
            num = s1.nextInt();
            powsum = powsum + num * num;
        }

        System.out.println(powsum % 10);
    }
}
