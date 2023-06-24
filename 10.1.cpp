#include <iostream>
#include <string>
#include <array>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>

struct Book {
    std::string title;
    std::string author;
    std::string genre;
    int year;
};

void input_book(Book& book) {
    std::cout << "Название: ";
    std::getline(std::cin, book.title);
    std::cout << "Автор: ";
    std::getline(std::cin, book.author);
    std::cout << "Жанр: ";
    std::getline(std::cin, book.genre);
    std::cout << "Год: ";
    std::cin >> book.year;
    std::cin.ignore(); // ignore newline character
}

void output_book(const Book& book) {
    std::cout << book.title << " от " << book.author << ", "
        << book.genre << ", " << book.year << std::endl;
}

struct Compare_Year {
    bool operator()(const Book& lhs, const Book& rhs) {
        return lhs.year > rhs.year;
    }
};

int main() {
    std::array<Book, 4> arr;
    std::list<Book> lst;
    std::forward_list<Book> fwd_lst;

    std::cout << "Введите инф о 4 книгах" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Книга " << i + 1 << ":" << std::endl;
        input_book(arr[i]);
        lst.push_back(arr[i]);
        fwd_lst.push_front(arr[i]);
    }

    std::cout << "Обратный порядок (using Stack):" << std::endl;
    std::stack<Book> stk;
    for (const Book& book : arr) {
        stk.push(book);
    }
    while (!stk.empty()) {
        output_book(stk.top());
        stk.pop();
    }

    std::cout << "Порядок добавления (using Queue):" << std::endl;
    std::queue<Book> que;
    for (const Book& book : lst) {
        que.push(book);
    }
    while (!que.empty()) {
        output_book(que.front());
        que.pop();
    }

    std::cout << "Сортировка по году (using Priority_queue):" << std::endl;
    std::priority_queue<Book, std::vector<Book>, Compare_Year> pq;
    for (const Book& book : fwd_lst) {
        pq.push(book);
    }
    while (!pq.empty()) {
        output_book(pq.top());
        pq.pop();
    }

    return 0;
}