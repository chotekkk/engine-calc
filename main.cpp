#include <iostream>
#include <iomanip>

using namespace std;

// Parametry napędu
const double FINAL_DRIVE = 3.647; 
const double TIRE_CIRCUMFERENCE_M = 1.99; // przybliżony obwód dla opony 225/45 R17

// Funkcja obliczająca prędkość w km/h
double calculateSpeed(int rpm, double gearRatio) {
    return (rpm * TIRE_CIRCUMFERENCE_M * 60.0) / (gearRatio * FINAL_DRIVE * 1000.0);
}

int main() {
    cout << "--- Kalkulator Predkosci ---" << endl;
    cout << "Symulacja dla 1.5 TSI (skrzynia 6-biegowa)" << endl;
    cout << "----------------------------" << endl;

    // Dodany komunikat o modyfikacji
    cout << "--> Wgrano nowa mape silnika (Stage 1) <--" << endl;
    cout << "----------------------------" << endl;

    int currentRpm = 6000;
    
    // Przełożenia dla kolejnych biegów (1-6)
    double gearRatios[] = {3.78, 2.12, 1.36, 1.03, 0.86, 0.73};

    cout << "Predkosc pojazdu przy " << currentRpm << " RPM:" << endl;
    
    for(int gear = 1; gear <= 6; ++gear) {
        double speed = calculateSpeed(currentRpm, gearRatios[gear-1]);
        cout << "Bieg " << gear << ": " << fixed << setprecision(1) << speed << " km/h" << endl;
    }

    return 0;
}