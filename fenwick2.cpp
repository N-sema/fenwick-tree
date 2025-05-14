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
        n = arr.size() - 1; // 1. indeksden ba�lar
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
    int size;
    cout << "Dizinin eleman say�s�n� girin: ";
    cin >> size;

    // 1-indeksli dizi i�in ilk eleman 0 olacak
    vector<int> arr(size + 1);
    arr[0] = 0; // 0. indeks kullan�lmaz

    cout << "Dizinin elemanlar�n� girin:\n";
    for (int i = 1; i <= size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    FenwickTree ft(arr);

    cout << "\n--- Ba�lang�� ---" << endl;
    ft.printOriginal();
    ft.printBIT();

    int l, r;
    cout << " Toplam almak i�in aral��� girin (�rn: 1 3): ";
    cin >> l >> r;
    cout << l << "-" << r << " aras� toplam: " << ft.rangeSum(l, r) << endl;

    int idx, val;
    cout << "G�ncelleme yapmak i�in indeks ve eklenecek de�eri girin (�rn: 3 2): ";
    cin >> idx >> val;
    ft.update(idx, val); // arr[idx] += val

    cout << "\n--- G�ncellemeden Sonra ---" << endl;
    ft.printOriginal();
    ft.printBIT();

    cout << " Yeni " << l << "-" << r << " aras� toplam: " << ft.rangeSum(l, r) << endl;

    return 0;
}
