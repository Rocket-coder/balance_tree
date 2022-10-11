#include "tree.h"



int main()
{
    setlocale(0, "");
    int d = 0;
    char ch;
    int b = 0;
    tree* root;
    root = NULL;


    int dip, count;
    int tell;
    srand(time(NULL));

    cout << "Заполнить дерево случаными числами?" << endl;
    cout << "1. Да" << endl;
    cout << "2. Нет" << endl;
    cout << endl;
    cin >> tell;
    switch (tell)
    {
    case 1:
        cout << "Введите диапозон значений: ";
        cin >> dip;
        cout << "Введите количество элементов: ";
        cin >> count;
        cout << endl;

        try {

            if ((count != 0) && (dip != 0)) {
                throw dip;
            }
            cout << "Введено нулевое значение" << endl;
            return 1;
        }

        catch (int e) {
            do {
                d = rand() % abs(e);
                root->Insert(root, d);
                b += 1;

            } while (b != abs(count));
        }

        break;
    case 2:
        break;

    default:
        cout << "Ошибка! Повторите попытку.";
        return 1;
    }

    cout << "   Заполнение дерева вручную:" << endl;

    do {
        cout << endl;
        cout << "Введите число: ";
        cin >> d;
        cout << endl;
        root->Insert(root, d);
        cout << "Продолжить ввод чисел? (y/n) ";
        cin >> ch;

    } while (ch != 'n');

    cout << endl;

    root->Print(root);

    root->Clear(&root);
    if (!root) {
        cout << "Дерево успешно очищено!" << endl;
    }
    else {
        cout << "Ошибка удаления!" << endl;
    }
}

