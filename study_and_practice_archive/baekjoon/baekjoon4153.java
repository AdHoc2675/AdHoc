import java.util.Scanner;

public class baekjoon4153 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int x, y, z;

        while (true) {
            x = s1.nextInt();
            y = s1.nextInt();
            z = s1.nextInt();

            if (x == 0 && y == 0 && z == 0) {
                break;
            }

            if (z * z == x * x + y * y) {
                System.out.println("right");
            } else if (x * x == z * z + y * y) {
                System.out.println("right");
            } else if (y * y == x * x + z * z) {
                System.out.println("right");
            } else {
                System.out.println("wrong");
            }

        }
        s1.close();
    }
}
