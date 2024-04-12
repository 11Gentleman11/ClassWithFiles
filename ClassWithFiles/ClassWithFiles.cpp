#include <iostream>
#include<vector>
#include <Windows.h>
#include<algorithm>
#include<string>
#include <fstream>
#include <stdlib.h>
#include <sstream>

using namespace std;
int duration;

class baggage

{
private:

    string item;
    double weight;

public:

    baggage() { item = ""; weight = 0; } //конструктор по умолчанию 
    baggage(const string& stringValue, double weight) //конструктор для создания динамического массива

    {
        item = stringValue;
        this->weight = weight;
    }


    ~baggage() {}
    string GetI() //геттер элемента item
    {
        return item;
    }
    double GetW() //геттер элемента weight
    {
        return weight;
    }
    friend void baggagemaker();//дружественная функция для сбора багажа
};

class placeandprice
{
protected:

    string place;
    int price;
    int distance;

public:

    placeandprice() //конструктор по умолчанию 

    {
        place = "";
        price = 0;

        distance = 0;

    }

    ~placeandprice() {}


    void SetPr(int price) //сеттер для элемента price
    {

        this->price = price;

    }

    void SetPl(string place) //сеттер для элемента place

    {

        this->place = place;

    }

    int GetPr() //геттер для элемента price

    {

        return price;

    }
    string GetPl()//геттер для элемента place

    {

        return place;

    }

    void SetD(int distance)

    {

        this->distance = distance;

    }

    int GetD()

    {

        return distance;

    }

};
class placeandduaration :placeandprice
{

public:

    placeandduaration() //конструктор по умолчанию

    {

        place = "";

        price = 0;

    }

    ~placeandduaration() {}

    void SetPr(int price) //сеттер для элемента price

    {

        this->price = price;

    }

    void SetPl(string place) //сеттер для элемента place

    {

        this->place = place;

    }

    int GetPr() //геттер для элемента price

    {

        return price;

    }

    string GetPl() //геттер для элемента place

    {

        return place;

    }

};

int stram()
{

    std::ifstream file("place.txt");

    int lineCount = 0;

    std::string line;

    while (std::getline(file, line))

    {

        lineCount++;

    }

    file.close();

    return lineCount;

}

int typechoiser()

{

    setlocale(LC_ALL, "Rus");

    int choise;

    cout << "\nВведите желаемый способ поездки:\n1.Авто\n2.Самолёт: ";

    cin >> choise;

    return choise;

}

string placechoiser(int& budget, int choise)

{



    setlocale(LC_ALL, "Rus");

    int oilprice = 48;

    string sity;

    ifstream fin;

    placeandprice* arr = new placeandprice[stram()]; //динамический массив для класса placeandprice

    fin.open("place.txt");

    if (!fin.is_open())

    {

        cout << "Ошибка открытия файла";

        exit(0);

    }

    int cc = 0;


    while (!fin.eof())

    {

        string word = "";

        int N = 0;

        int N1 = 0;

        setlocale(LC_ALL, "Rus");

        if (fin.eof()) break;

        fin >> word;

        arr[cc].SetPl(word); //начало объявления элементов массива

        fin >> word;

        N = stoi(word);

        arr[cc].SetPr(N);

        fin >> word;

        N1 = stoi(word);

        arr[cc].SetD(N1);

        cc++;

    }


    fin.close();

    int count = 0;


    if (choise == 1)

    {


        for (int i = 0; i < 5; i++)

        {

            if ((((arr[i].GetD() / 100) * 9) * oilprice) * 2 < budget) //вывод возможных городов в зависимости от бджета

            {

                count++;

                cout << "Возможный город для поездки: " << arr[i].GetPl() << endl;

            }

        }

        if (count == 0)

        {

            cout << "Ваш бюджет слишком мал\n";

            exit(0);

        }

        else

        {

            cout << "Введите город из предложеного списка : ";

            cin >> sity; //выбор города из списка

            transform(sity.begin(), sity.end(), sity.begin(), ::tolower);  // С помощью функции transform преобразуем строку во все строчные буквы на месте.

            for (int i = 0; i < 5; i++)

            {

                string place = arr[i].GetPl();


                transform(place.begin(), place.end(), place.begin(), ::tolower); // С помощью функции transform преобразуем строку во все строчные буквы на месте.

                if (place == sity)

                {

                    budget = budget - (((arr[i].GetD() / 100) * 9) * oilprice) * 2; //изменение бюдждета в заависимости от выбранного города
                    cout << "";

                }

            }

        }



    }



    if (choise == 2)

    {

        for (int i = 0; i < 5; i++)

        {

            if (arr[i].GetPr() * 2 < budget) //вывод возможных городов в зависимости от бджета

            {

                count++;

                cout << "Возможный город для поездки: " << arr[i].GetPl() << endl;

            }

        }

        if (count == 0)

        {

            cout << "Ваш бюджет слишком мал\n";

            exit(0);

        }

        else

        {

            cout << "Введите город из предложеного списка : ";

            cin >> sity; //выбор города из списка

            transform(sity.begin(), sity.end(), sity.begin(), ::tolower);  // С помощью функции transform преобразуем строку во все строчные буквы на месте.

            for (int i = 0; i < 5; i++)

            {

                string place = arr[i].GetPl();


                transform(place.begin(), place.end(), place.begin(), ::tolower); // С помощью функции transform преобразуем строку во все строчные буквы на месте.

                if (place == sity)

                {

                    budget = budget - arr[i].GetPr() * 2; //изменение бюдждета в заависимости от выбранного города

                }

            }

        }

    }



    return(sity); //возврат выбранного города

}




string placeanddurationchoiser(int& budget)

{

    string place;

    duration = 0;

    placeandduaration* arr = new placeandduaration[3]; //создание динамического массива из элементво класса placeandduration

    arr[0].SetPl("Гостиница"); //начало объявления элементов массива

    arr[0].SetPr(700);

    arr[1].SetPl("Хостел");

    arr[1].SetPr(250);

    arr[2].SetPl("Отель");

    arr[2].SetPr(1500); //конец объявления элементов массива

    for (int i = 0; i < 3; i++)

    {

        if (arr[i].GetPr() < budget)

        {

            cout << "Вы можете прожить в " << arr[i].GetPl() << " в течениии " << budget / arr[i].GetPr() << " дней" << endl; //Вывод возможных мест для проживания в зависимости от оставшегося бюджета

        }

    }

    cout << "Выберете окончательное место пребывания: ";

    cin >> place; //выбор места из списка

    transform(place.begin(), place.end(), place.begin(), ::tolower); // С помощью функции transform преобразуем строку во все строчные буквы на месте.            

    cout << endl << "Укажите количество дней пребывания в указанном месте, но не больше максимального: ";

    cin >> duration; //выбор количества дней проживания

    for (int i = 0; i < 3; i++)

    {

        string exactplace = arr[i].GetPl();

        transform(exactplace.begin(), exactplace.end(), exactplace.begin(), ::tolower);


        if (place == exactplace)

        {

            budget = budget - (arr[i].GetPr() * duration); //изменение бюджета в зависимости от выбранного места и количества дней проживания

        }

    }

    return place;

}

void baggagemaker()

{

    baggage a;

    string item1;

    double weight1;

    vector<baggage> myvector; //создание вектора для элементов багажа

    cout << "Введите предмет, который хотите взять в поездку и его вес. Oбщий вес передметов не может превышать 20 кг! \nВведите слово \"Конец\" если хотите завершить заполнене багажа досрочно" << endl;

    do

    {

        cout << "Текущий вес багажа: " << a.weight; //вывод общего веса предметов

        cout << "\nВведите предмет: ";

        cin >> item1; //ввод наименования предмета

        if (item1 == "конец")

        {

            break;

        }

        cout << "\nВведите вес предмета: ";

        cin >> weight1; //ввод веса предмета

        a.weight += weight1;

        baggage obj(item1, weight1); //создание объекта из элементов класса baggage

        myvector.push_back(obj); //добавление объекта в вектор

        if (a.weight >= 20) //порверка условия веса общего веса багажа

        {

            break;

        }

    } while (true);

    for (int i = 0; i < myvector.size(); i++)

    {

        cout << myvector[i].GetI() << "   " << myvector[i].GetW() << endl; //вывод элементов багажа

    }

}


void main()

{

    stram();
    int choise;

    choise = typechoiser();

    SetConsoleCP(1251);//изменение настроек консоли на ввод символов русского языка

    SetConsoleOutputCP(1251);//изменение настроек консоли на ввод символов русского языка

    setlocale(LC_ALL, "Rus");//добавление возможности вывода символов русского языка

    int budget;

    string sity;

    string place;

    cout << "Введите бюджет поездки: ";

    cin >> budget; //ввод бюджета поездки

    sity = placechoiser(budget, choise);

    place = placeanddurationchoiser(budget);

    cout << "У вас осталось " << budget << " рублей" << endl; //вывод 

    baggagemaker();

    cout << "Итог:\nВы собираетесь поехать в " << sity << " ,остановиться на " << duration << " дней в " << place << " с остаточным бюджетом в " << budget; //вывод

}
