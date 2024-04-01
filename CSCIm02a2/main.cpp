#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class StereoReceiver {
private:
    string manufacturer;
    string model;
    string serialNumber;
    string band;
    int wattage;
    int numChannels;
    int trebleLevel;
    int volume;
    double frequency;
    bool power;
    bool isMuted;

public:
    // Constructor with exception handling
    StereoReceiver(const string& manuf, const string& mdl, const string& serial,
                   int watt, int channels)
        : manufacturer(manuf), model(mdl), serialNumber(serial), wattage(watt),
          numChannels(channels), band("FM"), frequency(98.3), volume(5), power(false),
          isMuted(false), trebleLevel(5) {
        // Validation
        if (manufacturer.empty() || model.empty() || serialNumber.empty())
            throw invalid_argument("Manufacturer, Model, or Serial Number not given");
        if (wattage <= 0 || numChannels <= 0)
            throw invalid_argument("Bad values for Wattage or Number of Channels");
    }
    
    // Mutator methods with exception handling
    void setPower(bool state) { power = state; }
    void setBand(const string& newBand) {
        if (newBand != "AM" && newBand != "FM")
            throw invalid_argument("Invalid Band");
        band = newBand;
    }
    void setFrequency(double freq) {
        if (freq < 88.0 || freq > 108.0)
            throw invalid_argument("Invalid Frequency");
        frequency = freq;
    }
    void setVolume(int vol) {
        if (vol < 0 || vol > 10)
            throw invalid_argument("Invalid Volume");
        volume = vol;
    }
    void setMute(bool muteState) { isMuted = muteState; }
    void setTrebleLevel(int level) {
        if (level < 0 || level > 10)
            throw invalid_argument("Invalid Treble Level");
        trebleLevel = level;
    }

    // Accessor methods
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    string getSerialNumber() const { return serialNumber; }
    string getBand() const { return band; }
    int getWattage() const { return wattage; }
    int getNumChannels() const { return numChannels; }
    int getVolume() const { return volume; }
    int getTrebleLevel() const { return trebleLevel; }
    double getFrequency() const { return frequency; }
    bool getPower() const { return power; }
    bool getIsMuted() const { return isMuted; }
};

int main() {
    try {
        string manufacturer, model, serialNumber;
        int wattage, numChannels;

        // Prompt user input
        cout << "Enter manufacturer: ";
        getline(cin, manufacturer);
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter serial number: ";
        getline(cin, serialNumber);
        cout << "Enter wattage: ";
        cin >> wattage;
        cout << "Enter number of channels: ";
        cin >> numChannels;

        // Create StereoReceiver object with exception handling
        StereoReceiver receiver(manufacturer, model, serialNumber, wattage, numChannels);

        // Display info
        cout << "\nStereoReceiver information:\n";
        cout << "Manufacturer: " << receiver.getManufacturer() << endl;
        cout << "Model: " << receiver.getModel() << endl;
        cout << "Serial Number: " << receiver.getSerialNumber() << endl;
        cout << "Wattage: " << receiver.getWattage() << endl;
        cout << "Number of Channels: " << receiver.getNumChannels() << endl;

        // Demonstrate changing values with exception handling
        receiver.setPower(true);
        receiver.setBand("AM"); // Throw an exception
    } catch (const invalid_argument& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
