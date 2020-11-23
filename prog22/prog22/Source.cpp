#include <iostream>
#include <iomanip>
#include <windows.h>

    using namespace std;

    int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        int n,m;
        cout << "n = "; cin >> n;
        cout << "m = "; cin >> m;

        int** a = new int* [n];
        for (int i = 0; i < n; i++)
            a[i] = new int[m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cout << "a[" << i << "," << j << "] = "; cin >> a[i][j];
            }
        void CmpSim(int** a, int n, int m);
        {
            bool main = true;
            bool side = true;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
            cout << endl;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i][j] != a[j][i] && i != j)
                        main = false;
                    if (a[i][j] != a[n - j - 1][n - i - 1] && j != (n - 1 - i))
                        side = false;
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << a[i][j] << " ";
                cout << endl;
            }
            cout << endl;

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] != a[j][i] && i != j)
                        main = false;
                    if (a[i][j] != a[m - j - 1][m - i - 1] && j != (m - 1 - i))
                        side = false;
                }
            }
            if (main == true)
                cout << "По основній" << endl;
            if (side == true)
                cout << "По другорядній" << endl;
            if (!main && !side)
                cout << "Немає симетрії" << endl;
            cout << endl;
        }
        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
        return 0;
    }