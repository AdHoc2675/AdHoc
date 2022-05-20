import java.util.Scanner;
import java.util.StringTokenizer;

public class baekjoon1152 { // 제출시 Main

    public static void main(String[] args) {
        Scanner s1 = new Scanner(System.in);
        String str;

        str = s1.nextLine();

        s1.close();

        StringTokenizer st = new StringTokenizer(str, " ");

        System.out.println(st.countTokens());
    }

}