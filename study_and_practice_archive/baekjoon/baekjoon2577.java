import java.util.Scanner;

public class baekjoon2577 { // 백준에서 제출시 클래스 명을 Main으로 바꿀것
    public static void main(String[] args) {
        int a, b, c;
        int count;
        int number;
        String numberstring;

        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        number = a * b * c;
        numberstring = Integer.toString(number);

        for (int i = 0; i < 10; i++) {
            count = 0;
            for (int j = 0; j < numberstring.length(); j++) {
                if (numberstring.charAt(j) - '0' == i) {
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}