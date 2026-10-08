#include <iostream>
using namespace std;

class EVChargingSafetyController {
private:
    double maxVoltage;
    double maxCurrent;
    double maxTemperature;
    double minBatterySOC;

public:
    EVChargingSafetyController(double voltageLimit,
                               double currentLimit,
                               double temperatureLimit,
                               double socLimit) {
        maxVoltage = voltageLimit;
        maxCurrent = currentLimit;
        maxTemperature = temperatureLimit;
        minBatterySOC = socLimit;
    }

    void checkSafety(double voltage,
                    double current,
                    double temperature,
                    double batterySOC) {

        bool safe = true;

        cout << "\n----- EV Charging Safety Controller -----" << endl;
        cout << "Charging Voltage : " << voltage << " V" << endl;
        cout << "Charging Current : " << current << " A" << endl;
        cout << "Battery Temperature : "
             << temperature << " C" << endl;
        cout << "Battery SOC : " << batterySOC << " %" << endl;

        // Voltage protection
        if (voltage > maxVoltage) {
            cout << "\nFAULT: Overvoltage detected!" << endl;
            safe = false;
        }

        // Current protection
        if (current > maxCurrent) {
            cout << "FAULT: Overcurrent detected!" << endl;
            safe = false;
        }

        // Temperature protection
        if (temperature > maxTemperature) {
            cout << "FAULT: High battery temperature detected!" << endl;
            safe = false;
        }

        // Battery SOC protection
        if (batterySOC >= 100) {
            cout << "Battery is fully charged." << endl;
            safe = false;
        }

        if (batterySOC < minBatterySOC) {
            cout << "WARNING: Battery SOC is very low." << endl;
        }

        // Final decision
        if (safe) {
            cout << "\nSafety Status : SAFE" << endl;
            cout << "Charging Status: CHARGING ENABLED" << endl;
        }
        else {
            cout << "\nSafety Status : UNSAFE" << endl;
            cout << "Charging Status: CHARGING STOPPED" << endl;
            cout << "EV Charger: DISCONNECTED" << endl;
        }
    }
};

int main() {

    // Safety limits
    double voltageLimit = 450.0;       // V
    double currentLimit = 100.0;       // A
    double temperatureLimit = 45.0;    // °C
    double minimumSOC = 10.0;           // %

    EVChargingSafetyController controller(
        voltageLimit,
        currentLimit,
        temperatureLimit,
        minimumSOC
    );

    // Example charging conditions
    double voltage = 400.0;
    double current = 80.0;
    double temperature = 35.0;
    double batterySOC = 65.0;

    controller.checkSafety(
        voltage,
        current,
        temperature,
        batterySOC
    );

    return 0;
}
