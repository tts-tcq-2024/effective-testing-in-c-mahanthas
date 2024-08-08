#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // Let's alternate the return value for better testing
    if (celcius > 200) {
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response should increment the failure count
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5); // Should trigger failure
    alertInCelcius(303.6); // Should trigger failure
    assert(alertFailureCount == 2); // We expect 2 failures
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
