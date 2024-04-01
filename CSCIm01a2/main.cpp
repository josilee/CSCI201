#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class StereoReceiver {
private:
    string manufacturer;
    string model;
    string serialNumber;
    int wattage;
    int numChannels;
    string band;
    double frequency;
    int volume;
    bool power;
    // Two other attributes: isMuted and trebleLevel
    bool isMuted;
    int trebleLevel;

public:
    // Constructor
    StereoReceiver(const string& manuf, const string& mdl, const string& serial,
                   int watt, int channels)
        : manufacturer(manuf), model(mdl), serialNumber(serial), wattage(watt),
          numChannels(channels), band("FM"), frequency(98.3), volume(5), power(false),
          isMuted(false), trebleLevel(5) {}

    // Accessor methods
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    string getSerialNumber() const { return serialNumber; }
    int getWattage() const { return wattage; }
    int getNumChannels() const { return numChannels; }
    string getBand() const { return band; }
    double getFrequency() const { return frequency; }
    int getVolume() const { return volume; }
    bool getPower() const { return power; }
    bool getIsMuted() const { return isMuted; }
    int getTrebleLevel() const { return trebleLevel; }

    // Mutator methods
    void setPower(bool state) { power = state; }
    void setBand(const string& newBand) { band = newBand; }
    void setFrequency(double freq) { frequency = freq; }
    void setVolume(int vol) {
        if (vol >= 0 && vol <= 10)
            volume = vol;
        else
            throw invalid_argument("Volume must be between 0 and 10");
    }
    // Methods for other attributes
    void setMute(bool muteState) { isMuted = muteState; }
    void setTrebleLevel(int level) {
        if (level >= 0 && level <= 10)
            trebleLevel = level;
        else
            throw invalid_argument("Treble level must be between 0 and 10");
    }
};

int main() {
    string manufacturer, model, serialNumber;
    int wattage, numChannels;

    // Prompt for user input
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

    // Validate input
    if (wattage <= 0 || numChannels <= 0) {
        cerr << "Invalid input. Wattage and number of channels must be positive integers.\n";
        return 1;
    }

    // Create StereoReceiver object
    StereoReceiver receiver(manufacturer, model, serialNumber, wattage, numChannels);

    // Display information
    cout << "\nStereoReceiver information:\n";
    cout << "Manufacturer: " << receiver.getManufacturer() << endl;
    cout << "Model: " << receiver.getModel() << endl;
    cout << "Serial Number: " << receiver.getSerialNumber() << endl;
    cout << "Wattage: " << receiver.getWattage() << endl;
    cout << "Number of Channels: " << receiver.getNumChannels() << endl;

    // Turn on the receiver
    receiver.setPower(true);
    cout << "\nStereoReceiver is now turned on.\n";

    // Set band, frequency, and volume
    receiver.setBand("FM");
    receiver.setFrequency(98.3);
    receiver.setVolume(7);

    // Display current settings
    cout << "\nCurrent settings:\n";
    cout << "Power: " << (receiver.getPower() ? "On" : "Off") << endl;
    cout << "Band: " << receiver.getBand() << endl;
    cout << "Frequency: " << receiver.getFrequency() << " MHz" << endl;
    cout << "Volume: " << receiver.getVolume() << endl;

    // Turn off the receiver
    receiver.setPower(false);
    cout << "\nStereoReceiver is now turned off.\n";

    return 0;
}
