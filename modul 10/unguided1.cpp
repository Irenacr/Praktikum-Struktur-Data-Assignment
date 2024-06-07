#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display menu
void showMenu_2311110066_IRENA_CAHYA_RESINAH() {
    int numSimpul;
    cout << "Silakan masukan jumlah simpul : ";
    cin >> numSimpul;

    vector<string> simpul;
    for (int i = 1; i <= numSimpul; i++) {
        string namaSimpul;
        cout << "Simpul " << i << ": ";
        cin >> namaSimpul;
        simpul.push_back(namaSimpul);
    }

    // Input bobot antar simpul
    vector<vector<int>> bobot(numSimpul, vector<int>(numSimpul));
    for (int i = 0; i < numSimpul; i++) {
        for (int j = 0; j < numSimpul; j++) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    // Display table
    cout << " ";
    for (const string& s : simpul) {
        cout << s << " ";
    }
    cout << endl;
    for (int i = 0; i < numSimpul; i++) {
        cout << simpul[i];
        for (int j = 0; j < numSimpul; j++) {
            cout << " " << bobot[i][j];
        }
        cout << endl;
    }

    
}

int main() {
    showMenu_2311110066_IRENA_CAHYA_RESINAH();
    return 0;
}