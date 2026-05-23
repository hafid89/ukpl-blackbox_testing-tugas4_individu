// usia_validator.cpp
// Aplikasi validasi usia untuk kompetisi

#include <iostream>
#include <string>
using namespace std;

class UsiaValidator {
private:
    string state;
    
public:
    UsiaValidator() {
        state = "S0";
    }
    
    string validateAge(int usia) {
        if (usia <= 0) {
            return "ERROR: Usia harus lebih dari 0";
        }
        if (usia < 13) {
            return "DITOLAK: Usia terlalu muda, minimal 13 tahun";
        }
        if (usia > 60) {
            return "DITOLAK: Usia terlalu tua, maksimal 60 tahun";
        }
        if (usia >= 13 && usia <= 17) {
            return "DITERIMA DENGAN CATATAN: Perlu izin orang tua";
        }
        if (usia >= 18 && usia <= 60) {
            return "DITERIMA: Silakan lanjut pendaftaran";
        }
        return "ERROR: Data tidak valid";
    }
    
    string processInput(int usia) {
        // State transition S0 -> S1
        if (state == "S0") {
            state = "S1";
        }
        
        string hasil = validateAge(usia);
        
        // State transition berdasarkan hasil
        if (hasil.find("ERROR") != string::npos) {
            state = "S5";  // Error state
        } 
        else if (hasil.find("DITOLAK") != string::npos) {
            state = "S4";  // Ditolak state
        }
        else {
            state = "S3";  // Diterima state
        }
        
        return hasil;
    }
    
    string getState() {
        return state;
    }
    
    void reset() {
        state = "S0";
    }
};

int main() {
    int usia;
    
    cout << "========================================" << endl;
    cout << "   APLIKASI VALIDASI USIA KOMPETISI" << endl;
    cout << "========================================" << endl;
    cout << "Aturan:" << endl;
    cout << "  - Usia minimal: 13 tahun" << endl;
    cout << "  - Usia maksimal: 60 tahun" << endl;
    cout << "  - Usia 13-17 : perlu izin orang tua" << endl;
    cout << "  - Usia 18-60 : langsung diterima" << endl;
    cout << "========================================" << endl;
    
    cout << "\nMasukkan usia Anda: ";
    cin >> usia;
    
    UsiaValidator validator;
    string hasil = validator.processInput(usia);
    
    cout << "\nHasil: " << hasil << endl;
    cout << "State akhir: " << validator.getState() << endl;
    
    return 0;
}