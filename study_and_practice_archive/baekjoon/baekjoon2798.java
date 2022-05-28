import java.util.Scanner;

public class baekjoon2798 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        int n, m;
        int closest = 0;

        n = s1.nextInt();
        m = s1.nextInt();

        int card[] = new int[n];

        for (int i = 0; i < n; i++) {
            card[i] = s1.nextInt();
        }

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (card[i] + card[j] + card[k] <= m && card[i] + card[j] + card[k] >= closest) {
                        closest = card[i] + card[j] + card[k];
                    }
                }
            }
        }

        System.out.println(closest);

    }
}
