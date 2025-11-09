// CipherVault.cpp
#include <bits/stdc++.h>
using namespace std;

string caesarEncrypt(const string &text, int shift) {
    string result = text;
    for (char &c : result) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return result;
}

string caesarDecrypt(const string &text, int shift) {
    return caesarEncrypt(text, 26 - (shift % 26));
}

string vigenereEncrypt(const string &text, const string &key) {
    string result;
    int j = 0;
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char k = tolower(key[j % key.size()]) - 'a';
            result += (c - base + k) % 26 + base;
            j++;
        } else result += c;
    }
    return result;
}

string vigenereDecrypt(const string &text, const string &key) {
    string result;
    int j = 0;
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char k = tolower(key[j % key.size()]) - 'a';
            result += (c - base - k + 26) % 26 + base;
            j++;
        } else result += c;
    }
    return result;
}

void saveToFile(const string &filename, const string &data) {
    ofstream ofs(filename);
    ofs << data;
    ofs.close();
    cout << "Saved to " << filename << endl;
}

string loadFromFile(const string &filename) {
    ifstream ifs(filename);
    stringstream buffer;
    buffer << ifs.rdbuf();
    return buffer.str();
}

int main() {
    cout << "🔐 CipherVault — Secret Encoder/Decoder\n";
    cout << "-------------------------------------\n";

    while (true) {
        cout << "\n1. Caesar Encrypt\n2. Caesar Decrypt\n3. Vigenere Encrypt\n4. Vigenere Decrypt\n5. Load File\n6. Exit\nChoose: ";
        int choice; cin >> choice;
        cin.ignore();

        if (choice == 6) break;
        string text, key;
        int shift;

        switch (choice) {
            case 1:
                cout << "Enter text: "; getline(cin, text);
                cout << "Shift (1–25): "; cin >> shift; cin.ignore();
                cout << "Encrypted: " << caesarEncrypt(text, shift) << endl;
                break;
            case 2:
                cout << "Enter text: "; getline(cin, text);
                cout << "Shift (1–25): "; cin >> shift; cin.ignore();
                cout << "Decrypted: " << caesarDecrypt(text, shift) << endl;
                break;
            case 3:
                cout << "Enter text: "; getline(cin, text);
                cout << "Enter key: "; getline(cin, key);
                cout << "Encrypted: " << vigenereEncrypt(text, key) << endl;
                break;
            case 4:
                cout << "Enter text: "; getline(cin, text);
                cout << "Enter key: "; getline(cin, key);
                cout << "Decrypted: " << vigenereDecrypt(text, key) << endl;
                break;
            case 5:
                cout << "Enter filename: "; getline(cin, text);
                cout << "File Content:\n" << loadFromFile(text) << endl;
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    cout << "Goodbye 👋\n";
    return 0;
}

