#include "database.h"
template <typename T>
Database<T>::Database(std::string n) : name(n)
{
    openDatabase();
}

template <typename T>
void Database<T>::openDatabase()
{
    data.open("./bin/data/" + name + ".bin", std::ios::out | std::ios::in | std::ios::binary);
    if (data.is_open())
    {
        // std::cout << "Database ditemukan" << std::endl;
    }
    else
    {
        // std::cout << "Database tidak ditemukan, membuat baru!!!" << std::endl;
        data.close();
        data.open("./bin/data/" + name + ".bin", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
    }
}

template <typename T>
int Database<T>::getDataSize()
{
    int start, end;
    data.seekg(0, std::ios::beg);
    start = data.tellg();
    data.seekg(0, std::ios::end);
    end = data.tellg();

    return (end - start) / sizeof(T);
}

template <typename T>
void Database<T>::deleteDatabase()
{
    data.close();
    std::string fullname = "./bin/data/" + name + ".bin";
    const char *fullnameChar = fullname.c_str();
    std::remove(fullnameChar);
}

template <typename T>
void Database<T>::writeData(int position, T &dataToWrite)
{
    data.seekp((position - 1) * sizeof(T), std::ios::beg);         // Pindah penunjuk posisi ke akhir file
    data.write(reinterpret_cast<char *>(&dataToWrite), sizeof(T)); // Menulis data struct ke file
}

template <typename T>
T Database<T>::readData(int position)
{
    T readData;
    data.seekp((position - 1) * sizeof(T), std::ios::beg);     // Pindah penunjuk posisi ke akhir file
    data.read(reinterpret_cast<char *>(&readData), sizeof(T)); // Menulis data struct ke file
    return readData;
}

template <typename T>
bool Database<T>::deleteData(int id)
{
    T blank, temp;
    int size, offset;
    bool success = true;

    size = getDataSize();
    blank.id = 0;
    offset = 0;
    Database<T>::writeData(id, blank);

    // Membuat objek database sementara untuk menyimpan data yang tidak dihapus
    Database<T> tempData("temp");

    for (int i = 1; i <= size; i++)
    {
        temp = readData(i);
        if (temp.id != 0)
        {
            temp.id = temp.id - offset;
            tempData.writeData(i - offset, temp);
        }
        else
        {
            offset++;
        }
    }

    // Menutup dan membuka kembali database untuk menimpa data yang ada
    deleteDatabase();
    openDatabase();

    size = tempData.getDataSize();

    // Menulis kembali data yang tidak dihapus ke database
    for (int i = 1; i <= size; i++)
    {
        temp = tempData.readData(i);
        writeData(i, temp);
    }
    tempData.deleteDatabase();

    return success;
}