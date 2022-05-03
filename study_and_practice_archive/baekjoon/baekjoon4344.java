/*
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
*/

import java.util.Scanner;

public class baekjoon4344 { // 백준에 제출 시 클래스 명은 Main으로
    public static void main(String[] args) {
        int c; // 테스트 케이스의 개수
        int n; // 학생 수
        int sum;
        double average; // 점수 평균
        int over_average; // 평균을 넘는 학생 수
        double result; // 최종적으로 출력할 값

        Scanner keyboard = new Scanner(System.in);

        c = keyboard.nextInt();

        for (int i = 0; i < c; i++) {
            sum = 0;
            average = 0;
            over_average = 0;

            n = keyboard.nextInt();
            int[] score = new int[n]; // 학생들의 점수를 저장하는 배열

            for (int j = 0; j < n; j++) {
                score[j] = keyboard.nextInt(); // 점수를 입력받아 저장
                sum = sum + score[j];

            }

            average = (double) sum / n; // 평균 구해주기

            for (int j = 0; j < n; j++) {
                if (score[j] > average) { // 한 학생의 점수가 평균보다 높으면
                    over_average++; // 평균을 넘는 학생 수 1증가
                }
            }

            result = (double) over_average / (double) n * 100;
            System.out.println(String.format("%.3f", result) + "%");
        }

        keyboard.close();
    }
}