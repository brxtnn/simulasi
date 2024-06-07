#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

float generateNormalDistribution(float mean, float stdDev) {
    float u1 = static_cast<float>(rand()) / RAND_MAX;
    float u2 = static_cast<float>(rand()) / RAND_MAX;
    float z = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return mean + stdDev * z;
}

float generateExponentialDistribution(float mean) {
    float u = static_cast<float>(rand()) / RAND_MAX;
    return -mean * log(u);
}

float generatePoissonDistribution(float mean) {
    float p = 1.0;
    int k = 0;
    float L = exp(-mean);

    do {
        k++;
        float u = static_cast<float>(rand()) / RAND_MAX;
        p *= u;
    } while (p > L);

    return k - 1;
}

float generateUniformDistribution(float a, float b) {
    return a + (b - a) * (static_cast<float>(rand()) / RAND_MAX);
}

int main() {
    srand(time(0));

    int banyak_data;
    float totalWAK = 0, totalWLP = 0;

    cout << "Masukkan jumlah pelanggan: ";
    cin >> banyak_data;

    // Waktu Antar Kedatangan (WAK)
    cout << "\nWaktu Antar Kedatangan (WAK):\n";
    cout << "Pilih distribusi data WAK:\n";
    cout << "1. Distribusi Normal\n";
    cout << "2. Distribusi Poisson\n";
    cout << "3. Distribusi Uniform\n";
    cout << "4. Distribusi Eksponensial\n";

    int distWAK;
    cout << "Pilih distribusi (1-4): ";
    cin >> distWAK;

    switch (distWAK) {
        case 1: {
            float meanNormal, stdDevNormal;
            cout << "Distribusi Normal\n";
            cout << "Masukkan rata-rata: ";
            cin >> meanNormal;
            cout << "Masukkan deviasi standar: ";
            cin >> stdDevNormal;

            for (int i = 0; i < banyak_data; ++i) {
                float interval = generateNormalDistribution(meanNormal, stdDevNormal);
                cout << "Interval " << i + 1 << ": " << interval << endl;
                totalWAK += interval;
            }
            break;
        }
        case 2: {
            float meanPoisson;
            cout << "Distribusi Poisson\n";
            cout << "Masukkan rata-rata: ";
            cin >> meanPoisson;

            for (int i = 0; i < banyak_data; ++i) {
                float interval = generatePoissonDistribution(meanPoisson);
                cout << "Interval " << i + 1 << ": " << interval << endl;
                totalWAK += interval;
            }
            break;
        }
        case 3: {
            float aUniform, bUniform;
            cout << "Distribusi Uniform\n";
            cout << "Masukkan nilai minimum: ";
            cin >> aUniform;
            cout << "Masukkan nilai maksimum: ";
            cin >> bUniform;

            for (int i = 0; i < banyak_data; ++i) {
                float interval = generateUniformDistribution(aUniform, bUniform);
                cout << "Interval " << i + 1 << ": " << interval << endl;
                totalWAK += interval;
            }
            break;
        }
        case 4: {
            float meanExponential;
            cout << "Distribusi Eksponensial\n";
            cout << "Masukkan rata-rata: ";
            cin >> meanExponential;

            for (int i = 0; i < banyak_data; ++i) {
                float interval = generateExponentialDistribution(meanExponential);
                cout << "Interval " << i + 1 << ": " << interval << endl;
                totalWAK += interval;
            }
            break;
        }
        default:
            cout << "Pilihan distribusi tidak valid.\n";
            return 1;
    }

    // Rata-rata WAK
    float rataWAK = totalWAK / banyak_data;
    cout << "\nTotal WAK: " << totalWAK << endl;
    cout << "Rata-rata WAK: " << rataWAK << endl;

    // Waktu Lama Pelayanan (WLP)
    cout << "\nWaktu Lama Pelayanan (WLP):\n";
    cout << "Pilih distribusi data WLP:\n";
    cout << "1. Distribusi Normal\n";
    cout << "2. Distribusi Poisson\n";
    cout << "3. Distribusi Uniform\n";
    cout << "4. Distribusi Eksponensial\n";

    int distWLP;
    cout << "Pilih distribusi (1-4): ";
    cin >> distWLP;

    switch (distWLP) {
        case 1: {
            float meanNormalWLP, stdDevNormalWLP;
            cout << "Distribusi Normal\n";
            cout << "Masukkan rata-rata: ";
            cin >> meanNormalWLP;
            cout << "Masukkan deviasi standar: ";
            cin >> stdDevNormalWLP;

            for (int i = 0; i < banyak_data; ++i) {
                float pelayanan = generateNormalDistribution(meanNormalWLP, stdDevNormalWLP);
                cout << "Pelayanan " << i + 1 << ": " << pelayanan << endl;
                totalWLP += pelayanan;
            }
            break;
        }
        case 2: {
            float meanPoissonWLP;
            cout << "Distribusi Poisson\n";
            cout << "Masukkan rata-rata: ";
            cin >> meanPoissonWLP;

            for (int i = 0; i < banyak_data; ++i) {
                float pelayanan = generatePoissonDistribution(meanPoissonWLP);
                cout << "Pelayanan " << i + 1 << ": " << pelayanan << endl;
                totalWLP += pelayanan;
            }
            break;
        }
        case 3: {
            float aUniformWLP, bUniformWLP;
            cout << "Distribusi Uniform\n";
            cout << "Masukkan nilai minimum: ";
            cin >> aUniformWLP;
            cout << "Masukkan nilai maksimum: ";
            cin >> bUniformWLP;

            for (int i = 0; i < banyak_data; ++i) {
                float pelayanan = generateUniformDistribution(aUniformWLP, bUniformWLP);
                cout << "Pelayanan " << i + 1 << ": " << pelayanan << endl;
                totalWLP += pelayanan;
            }
            break;
        }
        case 4: {
            float meanExponentialWLP;
            cout << "Distribusi Eksponensial\n";
            cout << "Masukkan rata-rata: ";
            cin >> meanExponentialWLP;

            for (int i = 0; i < banyak_data; ++i) {
                float pelayanan = generateExponentialDistribution(meanExponentialWLP);
                cout << "Pelayanan " << i + 1 << ": " << pelayanan << endl;
                totalWLP += pelayanan;
            }
            break;
        }
        default:
            cout << "Pilihan distribusi tidak valid.\n";
            return 1;
    }

    // Rata-rata WLP
    float rataWLP = totalWLP / banyak_data;
    cout << "\nTotal WLP: " << totalWLP << endl;
    cout << "Rata-rata WLP: " << rataWLP << endl;

    // Total Lama Pelanggan dalam Sistem
    float totalLamaDalamSistem = totalWAK + totalWLP;

    // Rata-rata Pelanggan dalam Sistem
    float rataLamaDalamSistem = totalLamaDalamSistem / banyak_data;

    // Output hasil
    cout << "\nTotal Lama Pelanggan dalam Sistem: " << totalLamaDalamSistem << endl;
    cout << "Rata-rata Pelanggan dalam Sistem: " << rataLamaDalamSistem << endl;

    return 0;
}
