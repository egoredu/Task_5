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

    cout << "0 - clean the list\n1 - print the list\n2 - insert element before x\n3 - insert element after x\n";
    cout << "4 - insert element in the end\n5 - remove element\n6 - create l1 with positive nums and l2 with negative nums\n";
    cout << "-1 - exit\n";
    cout << "Enter the action: ";
    cin >> x;
    while (x != -1)
    {
        switch (x)
        {
            case 0:
                l.clear();
                break;
            case 1:
                if (l.empty()) cout << "List is empty\n";
                else
                    for (it = l.begin(); it != l.end(); cout << *it << ' ', it++);
                cout << "\n";
                break;
            case 2:
                if (l.empty()) cout << "List is empty\n";
                else
                {
                    cout << "Enter the value: ";
                    cin >> v;
                    cout << "Enter the value x: ";
                    cin >> y;
                    it = find(l.begin(), l.end(), y);
                    if (it == l.end()) cout << "No such element\n";
                    else
                        l.emplace(it, v);
                }
                break;
            case 3:
                if (l.empty()) cout << "List is empty\n";
                else
                {
                    cout << "Enter the value: ";
                    cin >> v;
                    cout << "Enter the value x: ";
                    cin >> y;
                    it = find(l.begin(), l.end(), y);
                    if (it == l.end()) cout << "No such element\n";
                    else
                    {
                        it++;
                        l.emplace(it, v);
                    }
                }
                break;
            case 4:
                cout << "Enter the value: ";
                cin >> v;
                l.emplace_back(v);
                break;
            case 5:
                if (l.empty()) cout << "List is empty\n";
                else
                {
                    cout << "Enter the value: ";
                    cin >> v;
                    it = find(l.begin(), l.end(), v);
                    if (it == l.end()) cout << "No such element\n";
                    else
                        l.erase(it);
                }
                break;
            case 6:
                if (l.empty()) cout << "List is empty\n";
                else
                {
                    pair < list<int>, list<int> > a = pml(l);
                    cout << "Positive list: ";
                    for (it = a.first.begin(); it != a.first.end(); cout << *it << ' ', it++);
                    cout<< "\nNegative list: ";
                    for (it = a.second.begin(); it != a.second.end(); cout << *it << ' ', it++);
                    cout << "\n";
                }
                break;
            default:
                cout << "Wrong action\n";
                break;
        }
        cin >> x;
    }
}
