#include <stdio.h>
#include <math.h>

#define G 9.8 // 중력 가속도

int main() {
    double v0, angle_deg;
    double angle_rad;
    double v0x, v0y;
    double h;
    double t; // 충돌 시간
    double x; // 수평 거리
    double vx, vy, v; // 속도 성분 및 크기
    double theta_deg; // 충돌 각도

    // 사용자로부터 입력 받기
    printf("==== 포물체 운동 계산기 ====\n");
    printf("초기 속도 v0 (m/s): ");
    scanf_s("%lf", &v0);
    printf("발사 각도 θ (도): ");
    scanf_s("%lf", &angle_deg);
    printf("출발 지점의 높이 h (m): ");
    scanf_s("%lf", &h);

    // 각도를 라디안으로 변환
    angle_rad = angle_deg * 3.141592 / 180.0;

    // 속도 성분
    v0x = v0 * cos(angle_rad);
    v0y = v0 * sin(angle_rad);

    // 2차 방정식으로 충돌 시간 계산 (y = h + v0y * t - 0.5 * g * t^2)
    double a = -0.5 * G;
    double b = v0y;
    double c = h;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("오류: 현실적인 해가 없습니다 (낙하하지 않음).\n");
        return 1;
    }

    // 시간 t 계산 (양의 해)
    t = (-b + sqrt(discriminant)) / (2 * a);

    // 수평 거리 계산
    x = v0x * t;

    // 충돌 직전 속도 성분
    vx = v0x;
    vy = v0y - G * t;

    // 속도 크기
    v = sqrt(vx * vx + vy * vy);

    // 충돌 순간 각도
    theta_deg = atan2(vy, vx) * 180.0 / 3.141592;

    // 결과 출력
    printf("\n===== 결과 =====\n");
    printf("(a) 충돌까지 걸린 시간: %.2f 초\n", t);
    printf("(b) 수평 거리: %.2f m\n", x);
    printf("(c) 충돌 직전 속도 성분: vx = %.2f m/s, vy = %.2f m/s\n", vx, vy);
    printf("    속도 크기: %.2f m/s\n", v);
    printf("(d) 충돌 각도: %.2f 도\n", theta_deg);

    return 0;
}
