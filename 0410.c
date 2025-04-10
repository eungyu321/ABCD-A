#include <stdio.h>
#include <math.h>

#define G 9.8
#define PI 3.14159265358979

int main() {
    double v0, angle_deg;
    double vx, vy;
    double h_max, t_peak, t_total, range;
    double vx_final, vy_final, v_final;

    // 사용자 입력
    printf("초기 속도 (m/s)를 입력하세요.: ");
    scanf_s("%lf", &v0);

    printf("발사각 (도)를 입력하세요.: ");
    scanf_s("%lf", &angle_deg);

    // 라디안 변환
    double angle_rad = angle_deg * PI / 180.0;

    // 1) x, y 방향 초기속도
    vx = v0 * cos(angle_rad);
    vy = v0 * sin(angle_rad);

    // 2) 최고점 높이
    h_max = (vy * vy) / (2 * G);

    // 3) 최고점 도달 시간
    t_peak = vy / G;

    // 전체 비행 시간
    t_total = 2 * t_peak;

    // 4) 수평 이동 최대 거리
    range = vx * t_total;

    // 5) 지면에 도달할 때 속도 성분
    vx_final = vx;            // 수평 속도는 일정
    vy_final = -vy;           // y방향은 -초기값
    v_final = sqrt(vx_final * vx_final + vy_final * vy_final); // 최종 속도 크기

    // 결과 출력
    printf("\n==== 계산 결과 ====\n");
    printf("1) 초기 속도 성분: Vx = %.2f m/s, Vy = %.2f m/s\n", vx, vy);
    printf("2) 최고점 높이: %.2f m\n", h_max);
    printf("3) 최고점 도달 시간: %.2f s\n", t_peak);
    printf("4) 수평 이동 거리: %.2f m\n", range);
    printf("5) 지면 도달 시 속도 성분: Vx = %.2f m/s, Vy = %.2f m/s, V = %.2f m/s\n", vx_final, vy_final, v_final);

    return 0;
}