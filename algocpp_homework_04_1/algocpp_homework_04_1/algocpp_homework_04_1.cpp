// algocpp_homework_04_1.cpp 

#include <iostream>
#include <string>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) 
{
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++) 
    {
     std::string sign;
     (i < logical_size) ? sign = std::to_string (arr[i]) : sign = "_";
     std::cout << sign << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int logical_size=0;
    int actual_size=0;
    int mark = 0;

    system("chcp 1251");
    system("cls");

    while (mark==0)
    {
        std::cout << "Введите фактичеcкий размер массива: ";
        std::cin >> actual_size;
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
        if (logical_size > actual_size) 
        {
            std::cout << "Ошибка! Логический размер массива не может превышать фактический! " << std::endl;
            return 0;
        }
        mark = 1;
    }

    int* arr = new int [actual_size] {};

    for(int count =0;count<logical_size;count++) 
    {
        std::cout << "Введите arr[" << count << "]:";
        std::cin >> arr[count];
    }
    
    print_dynamic_array(arr,logical_size,actual_size);

    delete[] arr;
    return 0;
}
