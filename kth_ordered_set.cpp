#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace std;
using namespace __gnu_pbds;

// Определение ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set os;
    os.insert(5);
    os.insert(2);
    os.insert(8);
    os.insert(4);

    // Получить элемент по индексу (нумерация с 0)
    cout << "Элемент с индексом 0: " << *os.find_by_order(0) << endl; // Выведет 2
    cout << "Элемент с индексом 2: " << *os.find_by_order(2) << endl; // Выведет 5

    // Получить количество элементов меньше 5
    cout << "Количество элементов меньше 5: " << os.order_of_key(5) << endl; // Выведет 2

    // Проверить наличие элемента
    if (os.find(4) != os.end()) {
        cout << "Элемент 4 найден." << endl;
    }

    // nth_element
    std::vector<int> data = {7, 5, 1, 2, 3, 6, 4};

    // Запросы на 1-й, 3-й и 5-й наименьшие элементы
    std::vector<int> queries = {0, 2, 4}; // индексы для std::nth_element
    for (int q: queries) {
        std::vector<int> temp = data; // Копия данных для изоляции изменений
        std::nth_element(temp.begin(), temp.begin() + q, temp.end());
        std::cout << "The " << (q + 1) << "th smallest element is " << temp[q] << std::endl;
    }
}

//Методы ordered_set:
//Вставка элемента:
//
//insert(value): Вставляет значение в контейнер.
//Удаление элемента:
//
//erase(iterator): Удаляет элемент, на который указывает итератор.
//erase(value): Удаляет элемент со значением value.
//Поиск элемента:
//
//find(value): Возвращает итератор на элемент со значением value. Если такого элемента нет, возвращается итератор end().
//Порядковые функции:
//
//find_by_order(k): Возвращает итератор на k-й наименьший элемент в контейнере (индексация начинается с нуля).
//order_of_key(k): Возвращает количество элементов в контейнере, которые строго меньше k.
//Размер и проверка на пустоту:
//
//size(): Возвращает количество элементов в контейнере.
//empty(): Возвращает true, если контейнер пуст.
//Доступ к началу и концу:
//
//begin(), end(): Возвращают итераторы, указывающие на начало и конец контейнера соответственно.
//Очистка контейнера:
//
//clear(): Удаляет все элементы из контейнера.
