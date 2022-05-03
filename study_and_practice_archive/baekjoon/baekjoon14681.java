import java.util.Scanner;

public class baekjoon14681 { // 백준에서 제출시엔 클래스 명을 Main으로 바꿀것

    public static void main(String[] args) {
        int x, y;

        Scanner sc = new Scanner(System.in);

        x = sc.nextInt();
        y = sc.nextInt();

        if (x > 0) {
            if (y > 0) {
                System.out.println("1");
            } else if (y < 0) {
                System.out.println("4");
            }
        } else if (x < 0) {
            if (y > 0) {
                System.out.println("2");
            } else if (y < 0) {
                System.out.println("3");
            }
        }
    }
}