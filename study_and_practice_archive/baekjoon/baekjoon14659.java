import java.util.Scanner;

public class baekjoon14659 {
    public static int MAX = 30000;

    public static void main(String[] args) {
        int n;
        int hill[] = new int[MAX];
        int kill_count = 0;
        int max_kill_count = 0;
        int current_hill;
        Scanner s1 = new Scanner(System.in);

        n = s1.nextInt();

        for (int i = 0; i < n; i++) {
            hill[i] = s1.nextInt();
        }

        for (int i = 0; i < n; i++) {
            current_hill = hill[i];
            kill_count = 0;

            for (int j = i + 1; j < n; j++) {
                if (current_hill < hill[j]) {
                    break;
                } else {
                    kill_count++;
                }

            }

            if (kill_count > max_kill_count) {
                max_kill_count = kill_count;
            }
        }

        System.out.println(max_kill_count);

        s1.close();
    }
}
