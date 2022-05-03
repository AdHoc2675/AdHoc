import java.util.Scanner;

public class baekjoon1546 { // 제출할 때는 클래스 이름을 Main으로 바꿀것
    public static void main(String[] args) {
        int n;
        int m = 0;
        double average = 0;

        Scanner keyboard = new Scanner(System.in);

        n = keyboard.nextInt();

        double[] arr = new double[n];

        for (int i = 0; i < n; i++) {
            arr[i] = keyboard.nextDouble();
            if (m < arr[i]) {
                m = (int) arr[i];
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] / m * 100;
            average = average + arr[i];
        }

        average = average / n;

        System.out.println(average);

        keyboard.close();
    }
}
