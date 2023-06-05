// algocpp_homework_04_2.cpp 

#include <iostream>
#include <string>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    for (int i = 0; i < actual_size; i++)
    {
        std::string sign;
        (i < logical_size) ? sign = std::to_string(arr[i]) : sign = "_";
        std::cout << sign << " ";
    }
    std::cout << std::endl;
}


int* append_to_dynamic_array (int*arr, int* l_s, int* a_s) 
{ 
    int mark = 1;
    int* temp_address = NULL;
   
    while (mark != 0) {
        if (*l_s == *a_s)
        {
            int* temp = new int [*a_s * 2] {};
           
            for (int y = 0; y < *a_s; y++)
            {
                temp[y] = arr[y];
            }
           
            temp_address = temp;
            temp=arr;
            arr = temp_address;
            delete[]temp;
            *a_s = *a_s * 2;         
        }
        std::cout << "Введите элемент для добавления: ";
        std::cin >> mark;
        if (mark != 0)
        {
            arr[*l_s] = mark;
            std::cout << "Динамический массив: ";
            print_dynamic_array(arr, *l_s+1, *a_s);
           
            *l_s = *l_s + 1;
        }
    }
    
  return (arr);
}



int main()
{
    int logical_size = 0;
    int actual_size = 0;
    int mark = 0;

    system("chcp 1251");
    system("cls");

    while (mark == 0)
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

    for (int count = 0; count < logical_size; count++)
    {
        std::cout << "Введите arr[" << count << "]:";
        std::cin >> arr[count];
    }
    int* a_s = &actual_size;
    int* l_s = &logical_size;
    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, *l_s, *a_s);

    arr = append_to_dynamic_array(arr, l_s, a_s);
    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, *l_s, *a_s);
    delete[] arr;
    return 0;
}