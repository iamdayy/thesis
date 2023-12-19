#include <iostream>
#include "function/auth.h"
#include "function/inventory.h"
int pilih_auth();
int pilih_menu();

int main()
{
    Auth auth;
    bool access;
label_auth:
    // pilih authentication
    int select = pilih_auth();
    while (select != 3)
    {
        switch (select)
        {
        case 1:
            access = auth.login();
            break;
        case 2:
            access = auth.registerUser();
            break;
        default:
            break;
        }
        /* jika login gagal maka akan di ulang untuk login */
        if (!access)
        {
            cout << "not authenticated" << endl;
            goto label_auth;
        }

        // masuk inventaris menu
        int select_menu = pilih_menu();
        char is_continue;
        while (select_menu != 6)
        {
            switch (select_menu)
            {
            case 1:
                cout << "Menu Tambah Item" << endl;
                cout << "================" << endl;
                auth.inventoryData.addInventory();
                break;
            case 2:
                cout << "Menu Baca Semua Item" << endl;
                cout << "====================" << endl;
                auth.inventoryData.readAll();
                break;
            case 3:
                cout << "Menu Cari Item" << endl;
                cout << "==============" << endl;
                auth.inventoryData.readOne();
                break;
            case 4:
                cout << "Menu Ubah Item" << endl;
                cout << "==============" << endl;
                auth.inventoryData.updateInventory();
                break;
            case 5:
                cout << "Menu Hapus Item" << endl;
                cout << "===============" << endl;
                auth.inventoryData.deleteInventory();
                break;
            default:
                break;
            }
        label_continue:
            cout << "lanjutkan ? [y/n] : ";
            cin >> is_continue;

            if (is_continue == 'y' | is_continue == 'Y')
            {
                select_menu = pilih_menu();
            }
            else if (is_continue == 'n' | is_continue == 'N')
            {
                select = 3;
                break;
            }
            else
            {
                goto label_continue;
            }
        }
    }

    return 0;
}

int pilih_auth()
{
    int input;

    cout << "=========================" << endl;
    cout << "Program kelola inventaris" << endl;
    cout << "=========================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Keluar" << endl;
    cout << "=====================" << endl;
    cout << "Pilih menu? [1-3] : ";

    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

int pilih_menu()
{
    int input;

    cout << "=========================" << endl;
    cout << "Program kelola inventaris" << endl;
    cout << "=========================" << endl;
    cout << "1. Tambah" << endl;
    cout << "2. Tampilkan semua" << endl;
    cout << "3. Cari" << endl;
    cout << "4. Ubah" << endl;
    cout << "5. Hapus" << endl;
    cout << "6. Selesai" << endl;
    cout << "=====================" << endl;
    cout << "Pilih menu? [1-6] : ";

    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}
