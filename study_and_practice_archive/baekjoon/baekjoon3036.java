import java.util.Scanner;

public class baekjoon3036 { // 제출시 Main

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
        Scanner s1 = new Scanner(System.in);
        int testCase;
        int arr[] = new int[100];
        int gcd;

        testCase = s1.nextInt();

        for (int i = 0; i < testCase; i++) {
            arr[i] = s1.nextInt();
        }

        for (int i = 1; i < testCase; i++) {
            gcd = find_GCD(arr[0], arr[i]);
            System.out.println(arr[0] / gcd + "/" + arr[i] / gcd);
        }

    }
}
