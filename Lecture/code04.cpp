#include <iostream>
    
using namespace std;

int calculate_sum(int * array);
int main() {
    int sum;
    int num[10];

    for (int i = 0; i < 10; i++)
        cin >> num[i];

    sum = calculate_sum(num);

    double average = (double)sum/10;
    cout << average << endl;
    
    return 0;
}

int calculate_sum (int * array) {
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += array[i];

    return sum;
}