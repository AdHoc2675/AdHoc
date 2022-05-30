import java.util.Scanner;

public class baekjoon1085 {
    public static void main(String[] args) { // 제출시 Main
        Scanner s1 = new Scanner(System.in);
        int x, y, w, h;

        x = s1.nextInt();
        y = s1.nextInt();
        w = s1.nextInt();
        h = s1.nextInt();

        // x - 0 , y - 0 , w - x, h - y 중에서 가장 작은 것 찾기

        if (x <= w - x && x <= y && x <= h - y) {
            System.out.println(x);
            return;
        } else if (y <= x && y <= w - x && y <= h - y) {
            System.out.println(y);
            return;
        } else if (w - x <= x && w - x <= y && w - x <= h - y) {
            System.out.println(w - x);
            return;
        } else if (h - y <= x && h - y <= w - x && h - y <= y) {
            System.out.println(h - y);
            return;
        }

        s1.close();
    }
}
