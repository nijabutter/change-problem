#include <stdio.h>

float round(float x) {
    int y = (x+0.005)*100; // round up and truncate
    return y/100.0; // put back into decimal
}

int main() {

    float values[] = {50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01}; // must be descending

    int count = 0; 
    float amount;

    printf("Amount: £");
    scanf("%f", &amount);
    float remaining = amount;

    for (int i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
        remaining = round(remaining); // round to 2dp
        int valueIntoRemaining = remaining / values[i]; // how many times it goes in
        remaining -= values[i] * valueIntoRemaining;
        count += valueIntoRemaining;

        if (count) {
            printf("%dx £%.2f\n", count, values[i]);
            count = 0;
        }
    }
    if (remaining)
        printf("Remaining: %.2f\n", remaining);
}
