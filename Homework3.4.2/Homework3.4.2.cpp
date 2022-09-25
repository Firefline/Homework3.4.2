// Homework3.4.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

class address
{
public:
    std::string city;
    std::string street;
    int house = 0;
    int room = 0;
public:
    address(std::string city, std::string street, int house, int room) {}
    address () {}
    std::string get_output_address()
    {
        std::string glue = city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(room);
        return glue;
    }
};

void sort(address* addresses, int size)
{
    bool swap = false;
    do
    {
        swap = false;
        for (int num = size - 1; num > 0; --num) 
        {
            if (&addresses[num - 1] > &addresses[num])
            {
                address temp = addresses[num - 1];
                addresses[num - 1] = addresses[num];
                addresses[num] = temp;
                swap = true;
            }
        }
    } while (swap);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    address get_address;

    int line;

    std::ifstream in("in.txt");
    std::ofstream out("out.txt");

    if (!in.is_open()) {
        std::cout << "Файл не найден" << std::endl;
        return 0;
    }

    in >> line;
    out << line << std::endl;

    address* array = new address[line];

    for (int i = 0; i < line; ++i)
    {
        in >> array[i].city;
        in >> array[i].street;
        in >> array[i].house;
        in >> array[i].room;
    }

    sort(array, line);

    for (int i = 0; i < line; ++i) {
        out << array[i].get_output_address() << std::endl;
    }

    delete[] array;

    in.close();
    out.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
