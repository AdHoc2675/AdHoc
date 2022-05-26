import java.util.Scanner;

public class baekjoon2941 { // 제출시 Main
    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        String str;

        str = s1.nextLine();

        int count = str.length();

        for (int i = 0; i < str.length(); i++) {
            if (i < str.length() - 1) {
                if (i < str.length() - 2) {
                    if (str.charAt(i) == 'd' && str.charAt(i + 1) == 'z' && str.charAt(i + 2) == '=') {
                        count = count - 2;
                        i = i + 2;
                    }
                }
                if (str.charAt(i) == 'c' && str.charAt(i + 1) == '=') {
                    count--;
                    i++;
                } else if (str.charAt(i) == 'c' && str.charAt(i + 1) == '-') {
                    count--;
                    i++;
                } else if (str.charAt(i) == 'd' && str.charAt(i + 1) == '-') {
                    count--;
                    i++;
                } else if (str.charAt(i) == 'l' && str.charAt(i + 1) == 'j') {
                    count--;
                    i++;
                } else if (str.charAt(i) == 'n' && str.charAt(i + 1) == 'j') {
                    count--;
                    i++;
                } else if (str.charAt(i) == 's' && str.charAt(i + 1) == '=') {
                    count--;
                    i++;
                } else if (str.charAt(i) == 'z' && str.charAt(i + 1) == '=') {
                    count--;
                    i++;
                }
            }
        }

        System.out.println(count);

    }
}
