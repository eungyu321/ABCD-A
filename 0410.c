#include <stdio.h>
#include <math.h>

#define pi 3.14159265
#define g 9.8 // 중력가속도

int main() {
    // 초기 조건
    double angle_deg = 30.0; // 발사각도 (도)
    double v0 = 30.0;        // 초기 속도 (m/s)

    // 각도를 라디안으로 변환
    double angle_rad = angle_deg * (pi / 180.0);

    // 1) x, y 방향 초기 속도
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);
    printf("1) V0x = %.2f m/s, V0y = %.2f m/s\n", v0x, v0y);

    // 3) 최고점 도달 시간 (Vy가 0일 때)
    double t_top = v0y / g;
    printf("3) 최고점 도달 시간 = %.2f 초\n", t_top);

    // 2) 최고점 높이
    double h_top = v0y * t_top - 0.5 * g * pow(t_top, 2);
    printf("2) 최고점 높이 = %.2f m\n", h_top);

    // 4) 수평으로 이동한 최고 거리 (비행 시간 = 2 * 최고점 도달 시간)
    double t_total = 2 * t_top;
    double x_max = v0x * t_total;
    printf("4) 수평으로 이동한 최대 거리 = %.2f m\n", x_max);

    // 5) 지면에 닿을 때의 속도 성분
    double vx_final = v0x; // 수평 속도는 변하지 않음
    double vy_final = -v0y; // 지면에 닿을 때 수직 속도는 초기의 반대 방향

    double v_final = sqrt(pow(vx_final, 2) + pow(vy_final, 2)); // 속도 크기
    printf("5) Vx = %.2f m/s, Vy = %.2f m/s\n", vx_final, vy_final);
    printf("   최종 속도 크기 V = %.2f m/s\n", v_final);

    return 0;
}