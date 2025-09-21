#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    // ��� 1: ������� �������� ��������
    int x = 20;            // �������� ���������� ����
    int n = 18;            // ����������� ���������� ����
    float S = 100000.0f;   // ������� �������� (���.)

    // ��� 2: ������ ��������� ��������� �������� �� ������ ����
    float percent_change_per_day = 50.0f / n; // 50/n %

    // ��� 3: ������ �������� ��������
    float final_salary;
    int days_difference = x - n; // ������������� � ��������, ������������� � ���������
    float salary_change_percent = percent_change_per_day * abs(days_difference);
    float salary_change = S * salary_change_percent / 100.0f;

    if (n == x) {
        final_salary = S;
    }
    else if (n < x) {
        final_salary = S + salary_change;  // ������ �� ��������� �����
    }
    else {
        final_salary = S - salary_change;  // ����� �� ���������
    }

    // ��� 4: ��������������� �����
    printf("������ �������� ������������ �������\n");
    printf("===================================\n\n");

    printf("�������:\n");
    printf("- �������� ����� �������������: %d ����\n", x);
    printf("- ����������� ����� �������������: %d ����\n", n);
    printf("- ������� ��������: %.2f ���.\n", S);
    printf("- ������ ���� ���������� �������� �������� �� 50 / n = 50 / %d = %.2f %%\n\n", n, percent_change_per_day);

    printf("������:\n");

    if (n == x) {
        printf("- ��� ���� ����� � ����. �������� �� ����������.\n");
    }
    else if (n < x) {
        printf("- ��� ���� �������� �� %d ����.\n", x - n);
        printf("- ��������� ��������: %.2f %% �� %.2f ���. = %.2f ���.\n", salary_change_percent, S, salary_change);
    }
    else {
        printf("- ��� ���� � ���������� � %d ����.\n", n - x);
        printf("- �������� ��������: %.2f %% �� %.2f ���. = %.2f ���.\n", salary_change_percent, S, salary_change);
    }

    printf("===================================\n");
    printf("�������� �������� �������: %.2f ���.\n", final_salary);

    return 0;
}
