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
        n = arr.size() - 1; // 1. indeksden baþlar
        bit.assign(n + 1, 0);
        original = arr;

        // Fenwick aðacýný oluþtur
        for (int i = 1; i <= n; i++) {
            update(i, arr[i], false); // Ýlk baþta double güncelleme olmamasý için false
        }
    }

    void update(int i, int val, bool updateOriginal = true) {
        if (updateOriginal)
            original[i] += val; // Orijinal diziyi de günceller

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
        cout << "Fenwick aðacý (bit[]): ";
        for (int i = 1; i <= n; i++) {
            cout << bit[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Dizinin eleman sayýsýný girin: ";
    cin >> size;

    // 1-indeksli dizi için ilk eleman 0 olacak
    vector<int> arr(size + 1);
    arr[0] = 0; // 0. indeks kullanýlmaz

    cout << "Dizinin elemanlarýný girin:\n";
    for (int i = 1; i <= size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    FenwickTree ft(arr);

    cout << "\n--- Baþlangýç ---" << endl;
    ft.printOriginal();
    ft.printBIT();

    int l, r;
    cout << " Toplam almak için aralýðý girin (örn: 1 3): ";
    cin >> l >> r;
    cout << l << "-" << r << " arasý toplam: " << ft.rangeSum(l, r) << endl;

    int idx, val;
    cout << "Güncelleme yapmak için indeks ve eklenecek deðeri girin (örn: 3 2): ";
    cin >> idx >> val;
    ft.update(idx, val); // arr[idx] += val

    cout << "\n--- Güncellemeden Sonra ---" << endl;
    ft.printOriginal();
    ft.printBIT();

    cout << " Yeni " << l << "-" << r << " arasý toplam: " << ft.rangeSum(l, r) << endl;

    return 0;
}
