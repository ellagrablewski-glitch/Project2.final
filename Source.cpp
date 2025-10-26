#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile;
     inputFile.open("FahrenheitTemperature.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open input file, please recheck and retry" << endl;
        return 1;
    } 
    ofstream outputFile;
    outputFile.open("CelsiusTemperature.txt");

    if (!outputFile.is_open()) {
       inputFile.close();
          cout << "Sorry, unable to create output file, please retry" << endl;
        return 1; // Exit with error code
    }
    string city;
        int fTemp;
        double cTemp; 
        while (inputFile >> city >> fTemp) {
        cTemp = (fTemp - 32) * (5.0 / 9.0);
        outputFile << city << " " << cTemp << endl;
    }
    inputFile.close(); //close files
    outputFile.close();

    cout << "All temps were converted and successfully saved to CelsiusTemperature.txt" << endl;

    return 0; // end
}