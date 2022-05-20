import java.util.Scanner;
import java.util.Arrays;

public class baekjoon1037 { // 제출시 Main
    public static void main(String[] args) {
        int arrsize = 0;
        int N = 0;

        Scanner s1 = new Scanner(System.in);

        arrsize = s1.nextInt();

        int arr[] = new int[arrsize];

        for (int i = 0; i < arrsize; i++) {
            arr[i] = s1.nextInt();
        }

        Arrays.sort(arr);

        if (arrsize % 2 == 1) {
            N = arr[arrsize / 2] * arr[arrsize / 2];
        } else if (arrsize % 2 == 0) {
            N = arr[0] * arr[arrsize - 1];
        }

        System.out.println(N);

        s1.close();
    }
}
