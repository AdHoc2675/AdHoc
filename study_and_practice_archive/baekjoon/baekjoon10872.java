import java.util.Scanner;

public class baekjoon10872 { // 제출시 Main
    public static int pacto(int num) {
        if (num <= 1) {
            return 1;
        }

        return pacto(num - 1) * num;
    }

    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int n;
        int result;

        n = s1.nextInt();
        s1.close();

        result = pacto(n);

        System.out.println(result);
    }
}