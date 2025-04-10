#include <stdio.h>
#include <math.h>

#define pi 3.14159265
#define g 9.8 // �߷°��ӵ�

int main() {
    // �ʱ� ����
    double angle_deg = 30.0; // �߻簢�� (��)
    double v0 = 30.0;        // �ʱ� �ӵ� (m/s)

    // ������ �������� ��ȯ
    double angle_rad = angle_deg * (pi / 180.0);

    // 1) x, y ���� �ʱ� �ӵ�
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);
    printf("1) V0x = %.2f m/s, V0y = %.2f m/s\n", v0x, v0y);

    // 3) �ְ��� ���� �ð� (Vy�� 0�� ��)
    double t_top = v0y / g;
    printf("3) �ְ��� ���� �ð� = %.2f ��\n", t_top);

    // 2) �ְ��� ����
    double h_top = v0y * t_top - 0.5 * g * pow(t_top, 2);
    printf("2) �ְ��� ���� = %.2f m\n", h_top);

    // 4) �������� �̵��� �ְ� �Ÿ� (���� �ð� = 2 * �ְ��� ���� �ð�)
    double t_total = 2 * t_top;
    double x_max = v0x * t_total;
    printf("4) �������� �̵��� �ִ� �Ÿ� = %.2f m\n", x_max);

    // 5) ���鿡 ���� ���� �ӵ� ����
    double vx_final = v0x; // ���� �ӵ��� ������ ����
    double vy_final = -v0y; // ���鿡 ���� �� ���� �ӵ��� �ʱ��� �ݴ� ����

    double v_final = sqrt(pow(vx_final, 2) + pow(vy_final, 2)); // �ӵ� ũ��
    printf("5) Vx = %.2f m/s, Vy = %.2f m/s\n", vx_final, vy_final);
    printf("   ���� �ӵ� ũ�� V = %.2f m/s\n", v_final);

    return 0;
}