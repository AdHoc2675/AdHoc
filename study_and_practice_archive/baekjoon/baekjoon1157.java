import java.util.Scanner;

public class baekjoon1157 {
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        String str;
        int count[] = new int[26];
        char c1;
        int num;
        int max = 0;
        int maxIndex = 0;
        char maxChar;

        str = s1.nextLine();
        str = str.toUpperCase();

        for (int i = 0; i < 26; i++) {
            count[i] = 0;
        }

        for (int i = 0; i < str.length(); i++) {
            c1 = str.charAt(i);
            num = c1;

            count[num - 65] = count[num - 65] + 1;
        }

        for (int i = 0; i < 26; i++) {
            if (max < count[i]) {
                max = count[i];
                maxIndex = i;
            }
        }

        maxChar = (char) (maxIndex + 65);

        for (int i = 0; i < 26; i++) {
            if (i != maxIndex && max == count[i]) {
                System.out.println("?");
                return;
            }
        }

        System.out.println(maxChar);
    }
}
