#include <stdio.h>
#include <math.h>

#define G 9.8 // �߷� ���ӵ�

int main() {
    double v0, angle_deg;
    double angle_rad;
    double v0x, v0y;
    double h;
    double t; // �浹 �ð�
    double x; // ���� �Ÿ�
    double vx, vy, v; // �ӵ� ���� �� ũ��
    double theta_deg; // �浹 ����

    // ����ڷκ��� �Է� �ޱ�
    printf("==== ����ü � ���� ====\n");
    printf("�ʱ� �ӵ� v0 (m/s): ");
    scanf_s("%lf", &v0);
    printf("�߻� ���� �� (��): ");
    scanf_s("%lf", &angle_deg);
    printf("��� ������ ���� h (m): ");
    scanf_s("%lf", &h);

    // ������ �������� ��ȯ
    angle_rad = angle_deg * 3.141592 / 180.0;

    // �ӵ� ����
    v0x = v0 * cos(angle_rad);
    v0y = v0 * sin(angle_rad);

    // 2�� ���������� �浹 �ð� ��� (y = h + v0y * t - 0.5 * g * t^2)
    double a = -0.5 * G;
    double b = v0y;
    double c = h;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("����: �������� �ذ� �����ϴ� (�������� ����).\n");
        return 1;
    }

    // �ð� t ��� (���� ��)
    t = (-b + sqrt(discriminant)) / (2 * a);

    // ���� �Ÿ� ���
    x = v0x * t;

    // �浹 ���� �ӵ� ����
    vx = v0x;
    vy = v0y - G * t;

    // �ӵ� ũ��
    v = sqrt(vx * vx + vy * vy);

    // �浹 ���� ����
    theta_deg = atan2(vy, vx) * 180.0 / 3.141592;

    // ��� ���
    printf("\n===== ��� =====\n");
    printf("(a) �浹���� �ɸ� �ð�: %.2f ��\n", t);
    printf("(b) ���� �Ÿ�: %.2f m\n", x);
    printf("(c) �浹 ���� �ӵ� ����: vx = %.2f m/s, vy = %.2f m/s\n", vx, vy);
    printf("    �ӵ� ũ��: %.2f m/s\n", v);
    printf("(d) �浹 ����: %.2f ��\n", theta_deg);

    return 0;
}
