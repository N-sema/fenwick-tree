#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> bit;
    vector<int> original; // Orijinal diziyi saklar
    int n;

public:
    FenwickTree(const vector<int>& arr) {
        n = arr.size() - 1; // 1. indexden ba�lar
        bit.assign(n + 1, 0);
        original = arr;

        // Fenwick a�ac�n� olu�tur
        for (int i = 1; i <= n; i++) {
            update(i, arr[i], false); // �lk ba�ta double g�ncelleme olmamas� i�in false
        }
    }

    void update(int i, int val, bool updateOriginal = true) {
        if (updateOriginal)
            original[i] += val; // Orijinal diziyi de g�nceller

        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    int prefixSum(int i) {
        int result = 0;
        while (i > 0) {
            result += bit[i];
            i -= i & -i;
        }
        return result;
    }

    int rangeSum(int i, int j) {
        return prefixSum(j) - prefixSum(i - 1);
    }

    void printOriginal() {
        cout << "Orijinal dizi: ";
        for (int i = 1; i <= n; i++) {
            cout << original[i] << " ";
        }
        cout << endl;
    }

    void printBIT() {
        cout << "Fenwick a�ac� (bit[]): ";
        for (int i = 1; i <= n; i++) {
            cout << bit[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Orijinal dizi (1-indexed, 0. indeks bo�)
    vector<int> arr = {0, 1, 2, 3, 4, 5};

    FenwickTree ft(arr);

    cout << "--- Ba�lang�� ---" << endl;
    ft.printOriginal();
    ft.printBIT();

    cout << "1-3 aras� toplam: " << ft.rangeSum(1, 3) << endl;
    cout << "1-5 aras� toplam: " << ft.rangeSum(1, 5) << endl;

    cout << "\n--- 3. elemana +2 ekleniyor ---" << endl;
    ft.update(3, 2); // arr[3] += 2

    ft.printOriginal();
    ft.printBIT();

    cout << "1-3 aras� yeni toplam: " << ft.rangeSum(1, 3) << endl;

    return 0;
}
