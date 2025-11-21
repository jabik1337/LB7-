#include <iostream>
#include <string>
using namespace std;

struct Train {
    string destination;   // Назва пункту призначення
    int number;           // Номер потягу
    double time;          // Час відправлення (наприклад 14.30)
};

int main() {
    const int N = 8;
    Train trains[N];

    // --- Введення даних ---
    cout << "Введіть дані про 8 потягів:\n";
    for (int i = 0; i < N; i++) {
        cout << "\nПотяг " << i + 1 << ":\n";
        cout << "Пункт призначення: ";
        cin >> trains[i].destination;
        cout << "Номер потягу: ";
        cin >> trains[i].number;
        cout << "Час відправлення (наприклад 14.30): ";
        cin >> trains[i].time;
    }

    // --- Сортування за номером потягу (bubble sort) ---
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (trains[j].number > trains[j + 1].number) {
                Train temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }

    // Введення часу для порівняння
    double t;
    cout << "\nВведіть час, до якого знайти потяги: ";
    cin >> t;

    // --- Виведення потягів, що відправляються до вказаного часу ---
    bool found = false;
    cout << "\nПотяги, що відправляються до " << t << ":\n";

    for (int i = 0; i < N; i++) {
        if (trains[i].time < t) {
            cout << "Потяг №" << trains[i].number
                 << ", пункт призначення: " << trains[i].destination
                 << ", час: " << trains[i].time << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Немає потягів, що відправляються до вказаного часу.\n";
    }

    return 0;
}
e