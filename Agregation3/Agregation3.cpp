#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

const int MAX_BUS_VEHICLES = 10;
const int MAX_CAR_VEHICLES = 15;
const int MAX_TRUCK_VEHICLES = 5;

//Bus

class Bus
{
private:
    string model;
    unsigned int seats;
public:

    Bus(string _model, int _seats) : model(_model), seats(_seats)
    {
    }

    Bus() : Bus("", 0) {}

    string GetModel() { return model; }

    int GetSeats() { return seats; }

    void Set(string _model, int _seats)
    {
        model = _model;
        seats = _seats;
    }
    void Print()
    {
        cout << "Модель: " << model << ", сидінь: " << seats << endl;
    }
};

//Car

class Car
{
private:
    string model;
public:

    Car(string _model) :model(_model)
    {
    }
    Car() : Car("")
    {
    }
    string GetModel() { return model; }
    void SetModel(string _model)
    {
        model = _model;
    }
    void Print()
    {
        cout << "Модель: " << model << endl;
    }
};

//Truck

class Truck
{
private:
    string model;
public:

    Truck(string _model) :model(_model)
    {
    }
    Truck() : Truck("")
    {
    }
    string GetModel() { return model; }
    void SetModel(string _model)
    {
        model = _model;
    }
    void Print()
    {
        cout << "Модель: " << model << endl;
    }
};

//station

class Station
{
private:
    vector <Bus> B;
    vector <Car> C;
    vector <Truck> T;
public:
    //Bus
    Bus GetBus(unsigned int number)
    {
        if (number < B.size())
            return B[number];
        else
        {
            cout << "Помилка в номері автобуса" << endl;
            return Bus("", 0);
        }
    }
    void AddBus(string model, unsigned int seats)
    {
        if (B.size() < MAX_BUS_VEHICLES)
        {
            Bus temp(model, seats);
            B.push_back(temp);
            cout << "Новий автобус додано!" << endl;
        }
        else
        {
            cout << "Не можливо додати новий автобус" << endl;
            return;
        }
    }
    void DelBus(unsigned int number)
    {
        if (number <= B.size())
        {
            B.erase(B.begin() + (number + 1));
            cout << "автобус видалено!" << endl;
        }
    }
    //Car
    Car GetCar(unsigned int number)
    {
        if (number < C.size())
            return C[number];
        else
        {
            cout << "Помилка в номері автівки!" << endl;
            return Car("");
        }
    }
    void AddCar(string model)
    {
        if (C.size() < MAX_CAR_VEHICLES)
        {
            Car temp(model);
            C.push_back(temp);
            cout << "Нове авто додане!" << endl;
        }
        else
        {
            cout << "Не можливо додати нове авто!" << endl;
            return;
        }
    }
    void DelCar(unsigned int number)
    {
        if (number < C.size())
        {
            C.erase(C.begin() + (number + 1));
            cout << "вантажівку видалено!" << endl;
        }
    }
    //Truck

    Truck GetTruck(unsigned int number)
    {
        if (number < T.size())
            return T[number];
        else
        {
            cout << "Помилка в номері вантажівки!" << endl;
            return Truck("");
        }
    }
    void AddTruck(string model)
    {
        if (T.size() < MAX_TRUCK_VEHICLES)
        {
            Truck temp(model);
            T.push_back(temp);
            cout << "Нова вантажівка додана!" << endl;
        }
        else
        {
            cout << "Не можливо додати нову вантажівку!" << endl;
            return;
        }
    }
    void DelTruck(unsigned int number)
    {
        if (number < T.size())
        {
            T.erase(T.begin() + (number + 1));
            cout << "вантажівку видалено!" << endl;
        }
    }

    //Print
    void Print()
    {
        cout << "Відомості про автостанцію:" << endl;
        if (B.empty()) {
            cout << "Станція для автобусів пуста!" << endl;
        }
        else {
            cout << "Кількість автобусів = " << B.size() << endl;
            if (B.size() > 0)
            {
                cout << "Відомості про автобуси:" << endl;
                for (int i = 0; i < B.size(); i++)
                {
                    B[i].Print();
                }
            }
        }
        if (C.empty()) {
            cout << "Станція для автівок пуста!" << endl;
        }
        else {
            cout << "Кількість автомобілів = " << C.size() << endl;
            if (C.size() > 0)
            {
                cout << "Відомості про автомобілі:" << endl;
                for (int i = 0; i < C.size(); i++)
                {
                    C[i].Print();
                }
            }
        }
        if (T.empty()) {
            cout << "Станція для вантажівок пуста!" << endl;
        }
        else {
            cout << "Кількість вантажівок = " << T.size() << endl;
            if (T.size() > 0)
            {
                cout << "Відомості про вантажівки:" << endl;
                for (int i = 0; i < T.size(); i++)
                {
                    T[i].Print();
                }
            }
        }

    }

    void Write(string path = "file.txt") {
        ofstream fout(path);
        fout << B.size() << "\n";

        for (size_t i = 0; i < B.size(); i++)
        {
            fout << B[i].GetModel() << "\n" << B[i].GetSeats() << "\n";

        }

        fout << C.size() << "\n";

        for (size_t i = 0; i < C.size(); i++)
        {
            fout << C[i].GetModel() << "\n";

        }

        fout << T.size() << "\n";

        for (size_t i = 0; i < T.size(); i++)
        {
            fout << T[i].GetModel() << "\n";

        }

        fout.close();
    }

    void Read(string path = "file.txt") {
        ifstream fin(path);

        if (!fin.is_open())
        {
            cout << "can`t open this file\n";
        }
        else
        {
            char size;
            string model;
            int seats;
            fin >> size;
            getline(fin, model);
            if (size!=0)
            {
                for (size_t i = 0; i < size - 48; i++)
                {
                    getline(fin, model);
                    fin >> seats;
                    this->AddBus(model, seats);
                    getline(fin, model);
                }
            }

            fin >> size;
            getline(fin, model);
            if (size != 0)
            {
                for (size_t i = 0; i < size - 48; i++)
                {
                    getline(fin, model);
                    this->AddCar(model);
                }
            }

            fin >> size;
            getline(fin, model);
            if (size != 0)
            {
                for (size_t i = 0; i < size - 48; i++)
                {
                    getline(fin, model);
                    this->AddTruck(model);
                }
            }
        }
        fin.close();
    }
};


int main() { // Щоб додати новий транспортний засіб потрібно просто викликати один із методів:
            //s.AddBus("модель", кіль-ість місць);  s.AddTruck("модель"); s.AddCar("модель");
            // і програма автоматично запише його у файл
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Station s;
    cout << "ініцалізація попередньої інформації:\n";
       s.Read(); // зчитування інформації попереднього сеансу
       cout << endl << endl;
     s.Print();

    //s.AddBus("Mercedes", 6);
    //s.AddTruck("Volkswagen");
    //s.AddCar("Audi");

     //s.Print();
    cout << endl << endl;
    cout << "запис поточної інформації про сеанс:\n";
    s.Write(); //запис поточної інформації про сеанс
    cout << "запис завершено\n\n\n";
}