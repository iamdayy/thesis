#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <iostream>
#include <vector>
#include "../modules/structures.h"

// Contoh template untuk Database
template<typename T>
class Database {
private:
    std::string name;
    std::fstream data;

public:
    Database(std::string n);
    void openDatabase();
    int getDataSize();
    void deleteDatabase();
    void writeData(int position, T& dataToWrite); // Metode template untuk menulis data ke file
    T readData(int position); // Metode template untuk membaca file ke data
    bool deleteData(int id);
};

#include "database.cpp"
#endif // DATABASE_H
