#include <iostream>
using namespace std;

struct  Mahasiswa
{
    int nim;
    string nama;
    char jeniskel;
    int nilaiangka; 
    string nilaihuruf;
    Mahasiswa *next;
    Mahasiswa *prev;
};

struct dblList
{
    private:
        Mahasiswa *head;
        Mahasiswa *tail;
    
    public:
        dblList()
        {
            head = NULL;
            tail = NULL;
        }

        void addData(int nim, string nama, char jeniskel, int nilaiangka, string nilaihuruf)
        {
            Mahasiswa *newData = new Mahasiswa;
            newData->nim = nim;
            newData->nama = nama;
            newData->jeniskel = jeniskel;
            newData->nilaiangka = nilaiangka;
            newData->nilaihuruf = nilaihuruf;
            newData->next = NULL;
            newData->prev = NULL;

            if (head == NULL)
            {
                head = newData;
                tail = newData;
            }
            else
            {
                tail->next = newData;
                newData->prev = tail;
                tail = newData;
            }
        }

        void displayData()
        {
            Mahasiswa *current = head;
            cout << "\n-------------- Data Nilai Mahasiswa UNNES --------------" << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << "NIM\tNama\tGender\tnilaiangka\tnilai huruf" << endl;
            cout << "--------------------------------------------------------" << endl;
            while (current != NULL)
            {
                cout << current->nim << "\t" << current->nama << "\t" << current->jeniskel << "\t" << current->nilaiangka << "\t\t" << current->nilaihuruf << endl;
                current = current->next;
            }
            cout << "--------------------------------------------------------" << endl;\
        }

        void statisticData()
        {
            Mahasiswa *current = head;
            int total = 0;
            int count = 0;
            int max = 0;
            int min = 100;
            Mahasiswa *maxData = new Mahasiswa;
            Mahasiswa *minData = new Mahasiswa;

            while (current != NULL)
            {
                count++;
                total += current->nilaiangka;
                if (current->nilaiangka > max)
                {
                    max = current->nilaiangka;
                    maxData = current;
                }
                if (current->nilaiangka < min)
                {
                    min = current->nilaiangka;
                    minData = current;
                }
                current = current->next;
            }

            cout << "Jumlah data: " << count << endl;
            cout << "Rata-rata nilaiangka: " << total/count << endl;
            cout << "Data nilai angka tertinggi: " << maxData->nilaiangka << " " << maxData->nama << endl;
            cout << "Data nilai angka terendah: " << minData->nilaiangka << " " << minData->nama << endl;
        }

        void searchData(int nim)
        {
            Mahasiswa *current = head;
            bool found = false;

            while (current != NULL)
            {
                if (current->nim == nim)
                {
                    found = true;
                    break;
                }
                current = current->next;
            }

            if (found)
            {
                cout << "Data ditemukan" << endl;
                cout << "NIM: " << current->nim << endl;
                cout << "Nama: " << current->nama << endl;
                cout << "Jenis kelamin: " << current->jeniskel << endl;
                cout << "nilaiangka: " << current->nilaiangka << endl;
                cout << "nilaiangka huruf: " << current->nilaihuruf << endl;
            }
            else
            {
                cout << "Data tidak ditemukan" << endl;
            }
        }
};

dblList myList;

    void tambahData()
    {
        int nim;
        string nama;
        char jeniskel;
        int nilaiangka;
        string nilaihuruf;

        cout << "Masukkan NIM: ";
        cin >> nim;
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan jenis kelamin (L/P): ";
        cin >> jeniskel;
        cout << "Masukkan nilai angka: ";
        cin >> nilaiangka;

        if (nilaiangka >= 86)
        {
            nilaihuruf = "A";
        }
        else if (nilaiangka >= 80)
        {
            nilaihuruf = "AB";
        }
        else if (nilaiangka >= 75)
        {
            nilaihuruf = "B";
        }
        else if (nilaiangka >= 70)
        {
            nilaihuruf = "BC";
        }
        else if (nilaiangka >= 65)
        {
            nilaihuruf = "C";
        }
        else if (nilaiangka >= 60)
        {
            nilaihuruf = "CD";
        }
        else if (nilaiangka >= 55)
        {
            nilaihuruf = "D";
        }
        else
        {
            nilaihuruf = "E";
        }

        myList.addData(nim, nama, jeniskel, nilaiangka, nilaihuruf);
    }

    void lihatData()
    {
        myList.displayData();
    }

    void lihatStatistik()
    {
        myList.statisticData();
    }

    void cariData()
    {
        int nim;
        cout << "Masukkan NIM: ";
        cin >> nim;
        myList.searchData(nim);
    }

    void keluar()
    {
        cout << "Terima kasih" << endl;
    }

    void menu()
    {
        int pilihan;
        do
        {
            cout << "\n-------- Menu Program --------" << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Tambah Data" << endl;
            cout << "2. Lihat Data Mahasiswa" << endl;
            cout << "3. Lihat Statistik Mahasiswa" << endl;
            cout << "4. Cari Data Mahasiswa (NIM)" << endl;
            cout << "5. Keluar Program" << endl;
            cout << "-----------------------------" << endl;
            cout << "Pilih Menu: ";
            cin >> pilihan;

            switch (pilihan)
            {
                case 1:
                    tambahData();
                    char input;
                    cout << "Apakah ingin menambah data lagi? (y/n) ";
                    cin >> input;
                    if (input == 'y')
                    {
                        tambahData();
                        cout << "Apakah ingin menambah data lagi? (y/n) ";
                        cin >> input;
                    }
                    else
                    {
                        menu();
                    }
                    break;    
                case 2:
                    lihatData();
                    break;
                case 3:
                    lihatStatistik();
                    break;
                case 4:
                    cariData();
                    break;
                case 5:
                    keluar();
                    break;
                default:
                    cout << "Pilihan tidak ada" << endl;
                    break;
            }
        } while (pilihan != 5);
    }

int main()
{
    menu();
    return 0;
}

