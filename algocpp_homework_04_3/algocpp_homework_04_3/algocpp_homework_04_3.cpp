// algocpp_homework_04_3.cpp 

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


void remove_dynamic_array_head(int*arr, int* l_s, int* a_s)
{ 
    
    std::string str="да";
    int* temp_address = NULL;
   
    while (str == "да") 
    {
        std::cout << "Удалить первый элемент? ";
        std::cin >> str;
        if (str == "да")
        {

            if (*l_s == 0 && *a_s == 1)
            {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания! " << std::endl;
                return;                
            }

            if (*l_s == 1 && *a_s == 1)
            {
                *l_s = 0;
            }
            else
            {
                for (int i = 0; i < (*l_s - 1); i++)
                {
                    arr[i] = arr[i + 1];
                }
                arr[*l_s] = 0;
                *l_s = *l_s - 1;
            }
               
                if (*l_s * 3 <= *a_s && * l_s != 0)
                {
                    int* temp = new int [*a_s / 3] {};
                    for (int y = 0; y < *a_s/3; y++)
                        {
                        temp[y] = arr[y];
                        }
                    delete[] arr;
                    arr = new int [*a_s / 3] {};
                    for (int y = 0; y < *a_s/3; y++)
                        {
                        arr[y] = temp[y];
                        }
                    delete[]temp;
                    *a_s = *a_s / 3;
                }          
        } 
        else 
        {
            std::cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, *l_s, *a_s);
            return;
        }

        std::cout << "Динамический массив: ";
        print_dynamic_array(arr, *l_s, *a_s);
    }   
    delete[] arr;
  return;
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
    remove_dynamic_array_head(arr, l_s, a_s);
    return 0;
}