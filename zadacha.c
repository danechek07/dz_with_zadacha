#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    // Шаг 1: Задание исходных значений
    int x = 20;            // Плановое количество дней
    int n = 18;            // Фактическое количество дней
    float S = 100000.0f;   // Базовая зарплата (руб.)

    // Шаг 2: Расчет процентов изменения зарплаты за каждый день
    float percent_change_per_day = 50.0f / n; // 50/n %

    // Шаг 3: Расчет итоговой зарплаты
    float final_salary;
    int days_difference = x - n; // Положительное — досрочно, отрицательное — просрочка
    float salary_change_percent = percent_change_per_day * abs(days_difference);
    float salary_change = S * salary_change_percent / 100.0f;

    if (n == x) {
        final_salary = S;
    }
    else if (n < x) {
        final_salary = S + salary_change;  // Премия за досрочную сдачу
    }
    else {
        final_salary = S - salary_change;  // Штраф за просрочку
    }

    // Шаг 4: Форматированный вывод
    printf("РАСЧЕТ ЗАРПЛАТЫ СТРОИТЕЛЬНОЙ БРИГАДЫ\n");
    printf("===================================\n\n");

    printf("УСЛОВИЯ:\n");
    printf("- Плановое время строительства: %d дней\n", x);
    printf("- Фактическое время строительства: %d дней\n", n);
    printf("- Базовая зарплата: %.2f руб.\n", S);
    printf("- Каждый день отклонения изменяет зарплату на 50 / n = 50 / %d = %.2f %%\n\n", n, percent_change_per_day);

    printf("РАСЧЕТ:\n");

    if (n == x) {
        printf("- Дом сдан точно в срок. Зарплата не изменяется.\n");
    }
    else if (n < x) {
        printf("- Дом сдан досрочно на %d дней.\n", x - n);
        printf("- Повышение зарплаты: %.2f %% от %.2f руб. = %.2f руб.\n", salary_change_percent, S, salary_change);
    }
    else {
        printf("- Дом сдан с просрочкой в %d дней.\n", n - x);
        printf("- Снижение зарплаты: %.2f %% от %.2f руб. = %.2f руб.\n", salary_change_percent, S, salary_change);
    }

    printf("===================================\n");
    printf("ИТОГОВАЯ ЗАРПЛАТА БРИГАДЫ: %.2f руб.\n", final_salary);

    return 0;
}
