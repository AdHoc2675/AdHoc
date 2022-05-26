import java.util.Scanner;

public class baekjoon11659 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int n, m;
        int range1, range2;

        n = s1.nextInt();
        m = s1.nextInt();

        int arr[] = new int[n + 1];

        arr[0] = 0;

        for (int i = 1; i < n + 1; i++) {
            arr[i] = arr[i - 1] + s1.nextInt();
        }

        for (int i = 0; i < m; i++) {
            range1 = s1.nextInt();
            range2 = s1.nextInt();

            System.out.println(arr[range2] - arr[range1 - 1]);
        }
    }
}
