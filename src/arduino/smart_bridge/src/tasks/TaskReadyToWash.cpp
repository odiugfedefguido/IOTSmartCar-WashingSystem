//il gate si apre e il veicolo va alla zona 2 --> L2 Red inizia a lampeggiare ogni 0.1 sec + "Proceed to the Washing Area" mex nel LCD
//-) entrata del veicolo nella zona 2 è rilevata  al SONAR 
//-) se la distanza misurata dal veicolo al sonar è minore di MINDIST per N2 sec il veicolo è considerato dentro la zona 2 --> gate si chiude + L2 Red diventa accesa
//(smette di lampeggiare quindi) + "Ready to Wash" mex nel LCD
/*
#include <iostream>
#include UltrasonicSensor.h
#include ServoMotor.h
#include Led.h

void displayMessage(const std::string& message) {
    // Funzione per mostrare il messaggio sull'LCD
    // (Implementazione simulata)
    std::cout << "LCD: " << message << std::endl;
}

int main() {
    const int N2 = 5; // Durata in secondi per cui la distanza deve essere minore di MINDIST

    bool isVehicleInside = false;
    int secondsInsideZone = 0;

    while (true) {
        float distance = Ultrasuonic::getDistance(); // Utilizzo del metodo per ottenere la distanza dalla classe Ultrasuonic

        if (distance == 0) { // Se la macchina è dentro la zona
            if (!isVehicleInside) {
                displayMessage("Ready to Wash");
                isVehicleInside = true;
            }

            secondsInsideZone++;
            if (secondsInsideZone >= N2) {
                displayMessage("Washing in Progress");
                closeGate(); // Chiude il gate quando la macchina è dentro per N2 secondi
                turnOff(); // Spegni il LED rosso
                break; // Esce dal loop di controllo della distanza
            } else {
                turnOn(); // Accendi il LED rosso se la macchina è dentro
            }
        } else {
            isVehicleInside = false;
            secondsInsideZone = 0;
            turnOff(); // Spegni il LED rosso se la macchina è fuori
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}


*/
