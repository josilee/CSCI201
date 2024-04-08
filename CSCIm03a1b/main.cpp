#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <limits>

using namespace std;

// Enum for valid RAM values
enum class RAMType { _4GB, _6GB, _8GB, _16GB, _32GB, _64GB };

// Enum for valid storage types
enum class StorageType { UFS, SSD, HDD };

class PersonalComputer {
private:
    string manufacturer;
    string formFactor;
    string serialNumber;
    string processor;
    RAMType ram;
    StorageType storageType;
    int storageSizeGB;

public:
    // Constructor
    PersonalComputer(const string& manufacturer, const string& formFactor,
                     const string& serialNumber, const string& processor,
                     RAMType ram, StorageType storageType, int storageSizeGB)
        : manufacturer(manufacturer), formFactor(formFactor), serialNumber(serialNumber),
          processor(processor), ram(ram), storageType(storageType), storageSizeGB(storageSizeGB) {
        // Validate storage size
        if (storageSizeGB != 128 && storageSizeGB != 256 && storageSizeGB != 512 &&
            storageSizeGB != 1024 && storageSizeGB != 2048) {
            throw invalid_argument("Invalid storage size");
        }
    }

    // Accessor methods
    string getManufacturer() const { return manufacturer; }
    string getFormFactor() const { return formFactor; }
    string getSerialNumber() const { return serialNumber; }
    string getProcessor() const { return processor; }
    RAMType getRAM() const { return ram; }
    StorageType getStorageType() const { return storageType; }
    int getStorageSizeGB() const { return storageSizeGB; }

    // Mutator methods
    void setRAM(RAMType newRAM) { ram = newRAM; }
    void setStorage(StorageType newStorageType, int newStorageSizeGB) {
        // Validate storage size
        if (newStorageSizeGB != 128 && newStorageSizeGB != 256 && newStorageSizeGB != 512 &&
            newStorageSizeGB != 1024 && newStorageSizeGB != 2048) {
            throw invalid_argument("Invalid storage size");
        }
        storageType = newStorageType;
        storageSizeGB = newStorageSizeGB;
    }

    // toString method
    string toString() const {
        stringstream ss;
        ss << "Manufacturer: " << manufacturer << ", ";
        ss << "Form Factor: " << formFactor << ", ";
        ss << "Serial Number: " << serialNumber << ", ";
        ss << "Processor: " << processor << ", ";
        ss << "RAM: ";
        switch (ram) {
            case RAMType::_4GB: ss << "4GB"; break;
            case RAMType::_6GB: ss << "6GB"; break;
            case RAMType::_8GB: ss << "8GB"; break;
            case RAMType::_16GB: ss << "16GB"; break;
            case RAMType::_32GB: ss << "32GB"; break;
            case RAMType::_64GB: ss << "64GB"; break;
        }
        ss << ", ";
        ss << "Storage Type: ";
        switch (storageType) {
            case StorageType::UFS: ss << "UFS"; break;
            case StorageType::SSD: ss << "SSD"; break;
            case StorageType::HDD: ss << "HDD"; break;
        }
        ss << " (" << storageSizeGB << "GB)";
        return ss.str();
    }
};

int main() {
    vector<PersonalComputer> inventory;
    string manufacturer, formFactor, serialNumber, processor;
    int ramSize, storageSize;
    RAMType ramType;
    StorageType storageType;

    char addAnother;
    do {
        // Prompt for PC details
        cout << "Enter manufacturer: ";
        cin >> manufacturer;
        cout << "Enter form factor (laptop/desktop): ";
        cin >> formFactor;
        cout << "Enter serial number: ";
        cin >> serialNumber;
        cout << "Enter processor: ";
        cin >> processor;
        cout << "Enter RAM size (4, 6, 8, 16, 32, 64): ";
        cin >> ramSize;
        cout << "Enter storage type (0 for UFS, 1 for SSD, 2 for HDD): ";
        int storageTypeInput;
        cin >> storageTypeInput;
        storageType = static_cast<StorageType>(storageTypeInput);
        cout << "Enter storage size (128, 256, 512, 1024, 2048): ";
        cin >> storageSize;

        try {
            // Validate and create new PersonalComputer object
            if (ramSize == 4) {
                ramType = RAMType::_4GB;
            } else if (ramSize == 6) {
                ramType = RAMType::_6GB;
            } else if (ramSize == 8) {
                ramType = RAMType::_8GB;
            } else if (ramSize == 16) {
                ramType = RAMType::_16GB;
            } else if (ramSize == 32) {
                ramType = RAMType::_32GB;
            } else if (ramSize == 64) {
                ramType = RAMType::_64GB;
            } else {
                throw invalid_argument("Invalid RAM size");
            }

            PersonalComputer pc(manufacturer, formFactor, serialNumber, processor,
                                ramType, storageType, storageSize);
            inventory.push_back(pc);

            // Display the newly added PC and total count
            cout << "New PC added:\n";
            cout << pc.toString() << "\n";
            cout << "Total PCs in inventory: " << inventory.size() << "\n";

            // Prompt to add another PC
            cout << "Add another PC? (y/n): ";
            cin >> addAnother;
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << ". Please try again.\n";
            // Clear input buffer to prevent infinite loop on invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            addAnother = 'y'; // Allow retry for the same PC
        }
    } while (tolower(addAnother) == 'y');

    // Display full inventory
    cout << "\nInventory List:\n";
    for (const auto& pc : inventory) {
        cout << pc.toString() << "\n";
    }

    return 0;
}
