public class baekjoon4673 { // 제출시 Main
    public static int self_num(int n) {
        int self = n;

        while (n != 0) {
            self = self + n % 10;
            n = n / 10;
        }
        return self;
    }

    public static void main(String[] args) {
        boolean arr[] = new boolean[10000];

        for (int i = 0; i < 10000; i++) {
            if (self_num(i + 1) < 10001) {
                arr[self_num(i + 1) - 1] = true;
            }
        }
        for (int i = 0; i < 10000; i++) {
            if (arr[i] == false) {
                System.out.println(i + 1);
            }
        }
    }
}
