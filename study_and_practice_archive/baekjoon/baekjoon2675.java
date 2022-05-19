import java.util.Scanner;

public class baekjoon2675 { // 제출시 Main으로 바꾸기
    public static void main(String[] args) {
        // 문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오. 즉, 첫 번째 문자를 R번
        // 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다.
        String str;
        Scanner s1 = new Scanner(System.in);
        int n;
        int repeat;

        n = s1.nextInt();

        for (int i = 0; i < n; i++) {
            repeat = s1.nextInt();
            str = s1.next();

            for (int j = 0; j < str.length(); j++) {
                for (int k = 0; k < repeat; k++) {
                    System.out.print(str.charAt(j));
                }
            }
            System.out.print("\n");
        }
    }
}