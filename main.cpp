#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

pair < list<int>, list<int> > pml(const list<int> l) {
    // разделение на положительный и отрицательный список
    list <int> lp, lm;
    for (auto &it : l)
        if (it > 0) lp.emplace_back(it);
        else if (it < 0) lm.emplace_back(it);
    return make_pair(lp, lm);
}

int main() {
    // индивидуальное задание – разделить список на два – с положительными и с отрицательными числами
    int x, y, v;
    list<int>::iterator it;
    list <int> l;
    // инициализируем список из 7 элементов
    for (int i = 0; i < 7; ++i) {
        v = (rand() % 2 == 0 ? 1 : -1) * rand() % 100;
        l.emplace_back(v);
    }

    cout << "0 - очистить список\n1 - вывести списокt\n2 - вставить элемент перед элементом x\n3 - вставить элемент после элемента x\n";
    cout << "4 - вставить элемент в конец\n5 - удалить элементт\n6 - создать список l1, содержащий положительные числа, и список l2, содержащий отрицательные\n";
    cout << "-1 - выйти\n";
    cout << "Введите команду: ";
    cin >> x;
    while (x != -1)
    {
        switch (x)
        {
            case 0:
                l.clear();
                break;
            case 1:
                if (l.empty()) cout << "Список пуст\n";
                else
                    for (it = l.begin(); it != l.end(); cout << *it << ' ', it++);
                cout << "\n";
                break;
            case 2:
                if (l.empty()) cout << "Список пуст\n";
                else
                {
                    cout << "Введите значение: ";
                    cin >> v;
                    cout << "Введите значение x: ";
                    cin >> y;
                    it = find(l.begin(), l.end(), y);
                    if (it == l.end()) cout << "В списке нет такого элемента\n";
                    else
                        l.emplace(it, v);
                }
                break;
            case 3:
                if (l.empty()) cout << "Список пуст\n";
                else
                {
                    cout << "Введите значение: ";
                    cin >> v;
                    cout << "Введите значение x: ";
                    cin >> y;
                    it = find(l.begin(), l.end(), y);
                    if (it == l.end()) cout << "В списке нет такого элемента\n";
                    else
                    {
                        it++;
                        l.emplace(it, v);
                    }
                }
                break;
            case 4:
                cout << "Введите значение: ";
                cin >> v;
                l.emplace_back(v);
                break;
            case 5:
                if (l.empty()) cout << "Список пуст\n";
                else
                {
                    cout << "Введите значение: ";
                    cin >> v;
                    it = find(l.begin(), l.end(), v);
                    if (it == l.end()) cout << "В списке нет такого элемента\n";
                    else
                        l.erase(it);
                }
                break;
            case 6:
                if (l.empty()) cout << "Список пуст\n";
                else
                {
                    pair < list<int>, list<int> > a = pml(l);
                    cout << "Положительный список: ";
                    for (it = a.first.begin(); it != a.first.end(); cout << *it << ' ', it++);
                    cout<< "\nОтрицательный список: ";
                    for (it = a.second.begin(); it != a.second.end(); cout << *it << ' ', it++);
                    cout << "\n";
                }
                break;
            default:
                cout << "Неверная команда\n";
                break;
        }
        cin >> x;
    }
}