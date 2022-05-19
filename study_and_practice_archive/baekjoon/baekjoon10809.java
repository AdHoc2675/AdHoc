import java.util.Scanner;

public class baekjoon10809 { // 백준에 제출시 이름을 Main으로

    public static void main(String[] args) {
        int[] arr = new int[26];
        Scanner s1 = new Scanner(System.in);
        String str = s1.nextLine();

        for (int i = 0; i < arr.length; i++) {
            arr[i] = -1;
        }

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            if (arr[ch - 'a'] == -1) { // arr 원소 값이 -1 인 경우에만 초기화
                arr[ch - 'a'] = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            System.out.println(arr[i]);
        }
    }
}