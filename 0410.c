#include <stdio.h>
#include <math.h>

#define G 9.8
#define PI 3.14159265358979

int main() {
    double v0, angle_deg;
    double vx, vy;
    double h_max, t_peak, t_total, range;
    double vx_final, vy_final, v_final;

    // ����� �Է�
    printf("�ʱ� �ӵ� (m/s)�� �Է��ϼ���.: ");
    scanf_s("%lf", &v0);

    printf("�߻簢 (��)�� �Է��ϼ���.: ");
    scanf_s("%lf", &angle_deg);

    // ���� ��ȯ
    double angle_rad = angle_deg * PI / 180.0;

    // 1) x, y ���� �ʱ�ӵ�
    vx = v0 * cos(angle_rad);
    vy = v0 * sin(angle_rad);

    // 2) �ְ��� ����
    h_max = (vy * vy) / (2 * G);

    // 3) �ְ��� ���� �ð�
    t_peak = vy / G;

    // ��ü ���� �ð�
    t_total = 2 * t_peak;

    // 4) ���� �̵� �ִ� �Ÿ�
    range = vx * t_total;

    // 5) ���鿡 ������ �� �ӵ� ����
    vx_final = vx;            // ���� �ӵ��� ����
    vy_final = -vy;           // y������ -�ʱⰪ
    v_final = sqrt(vx_final * vx_final + vy_final * vy_final); // ���� �ӵ� ũ��

    // ��� ���
    printf("\n==== ��� ��� ====\n");
    printf("1) �ʱ� �ӵ� ����: Vx = %.2f m/s, Vy = %.2f m/s\n", vx, vy);
    printf("2) �ְ��� ����: %.2f m\n", h_max);
    printf("3) �ְ��� ���� �ð�: %.2f s\n", t_peak);
    printf("4) ���� �̵� �Ÿ�: %.2f m\n", range);
    printf("5) ���� ���� �� �ӵ� ����: Vx = %.2f m/s, Vy = %.2f m/s, V = %.2f m/s\n", vx_final, vy_final, v_final);

    return 0;
}