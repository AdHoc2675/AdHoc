import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class baekjoon2869 { // 제출시 Main
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());
        int day;

        day = (v - a) / (a - b);

        if ((v - a) % (a - b) == 0) {
            System.out.println(day + 1);
        } else {
            System.out.println(day + 2);
        }

        br.close();
    }
}