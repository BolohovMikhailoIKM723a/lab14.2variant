#include <iostream>
#include <Windows.h>

using namespace std;
int findDivisors(int n, int divisors[]) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors[count++] = i;
        }
    }
    return count;
}
bool binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX_DIVISORS = 100;
    int number;
    cout << "введіть шестизначне ціле число: ";
    cin >> number;
    int divisors[MAX_DIVISORS];
    int count = findDivisors(number, divisors);
    cout << "дільники шестизначного числа " << number << ":\n";
    for (int i = 0; i < count; i++) {
        cout << divisors[i] << " ";
    }
    cout << endl;
    int target;
    cout << "введіть дільник для пошуку: ";
    cin >> target;
    bool found = binarySearch(divisors, count, target);
    if (found) {
        cout << "дільник " << target << " знайдено." << endl;
    }
    else {
        cout << "дільник " << target << " не знайдено." << endl;
    }
    return 0;
}