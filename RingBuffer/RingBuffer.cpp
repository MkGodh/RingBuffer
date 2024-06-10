#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec(20);

    int num;
    int front = 0;
    int rear = 0;
    int count = 0;
    cout << "Please input nums: ";
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        } 
        if (count < 20) {            // Если очередь не полна (count < 20), новый элемент добавляется в конец очереди:
            vec[rear] = num;          // vec[rear] = num; хранит новый элемент по текущему индексу rear.
            rear = (rear + 1) % 20;   // rear = (rear + 1) % 20; увеличивает индекс rear, обходя к 0, если он достигает конца вектора.
            count++; 
        }
        else {                      // Если очередь полна (count == 20), новый элемент заменяет самый старый элемент (в начале очереди):
            vec[front] = num;         // vec[front] = num; хранит новый элемент по текущему индексу front.
            front = (front + 1) % 20;  // front = (front + 1) % 20; увеличивает индекс front, обходя к 0, если он достигает конца вектора.
            rear = (front + 1) % 20;   // rear = (front + 1) % 20; обновляет индекс rear, чтобы он указывал на новый индекс front.
        }
    }

    cout << "Output ";
    int i = front;
    for (int j = 0; j < count; j++) {
        cout << vec[i] << " ";
        i = (i + 1) % 20;        //увеличивает индекс i, обходя к 0, если он достигает конца вектора.
    }
    cout << endl;

    return 0;
}