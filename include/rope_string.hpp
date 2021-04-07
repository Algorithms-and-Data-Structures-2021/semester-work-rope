#pragma once

// Заголовочный файл с объявлением структуры данных

namespace itis {
  // Структура веревочной строки
  struct Node {
   public:
    Node *left, *right, *parent;
    char *str;
    int lCount;

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    // Вывод строки в консоль
    void print(Node *node);

    // Объединение двух строк
    void concatenate(Node *n1, Node *n2, Node *n3, int l);

    // Разделение строки по некоторому индексу
    Node split(Node *n1, int index);
  };

}  // namespace itis