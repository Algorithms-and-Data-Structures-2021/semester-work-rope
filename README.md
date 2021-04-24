# Я ничо не придумал

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

**_Измените status badge сверху для отображения статуса сборки вашего проекта._**

`Actions > CMake > ... > Create status badge`

_Краткое описание семестрового проекта. Следует отразить информацию по следующим пунктам:_

- _Какая структура данных реализуется?_
  - Rope string(веревочная строка)
  

- _Что она из себя представляет (сбалансированное дерево, линейный список и пр.)?_
  - Сбалансированное дерево, содержащее подстроки изначальной строки.
  

- _Где и как она используется (приложения)?_
  - При работе с большими строками.
  

- _Какие операции над ней можно выполнять (поиск, удаление, добавление, вставка и пр.)?_
  - Поиск символа по индексу, соединение строк, удаление подстроки, разделение строки на две подстроки, вставка строки. 


- _Какова теоретическая сложность операций (поиск за `O(log(n))`, вставка за `O(n^2)` и т.д.)?_
  - Вставка - O(log(n));
  - Поиск по индексу - O(log(n));
  - Соединение - O(1) или же O(log(n)) для сбалансированной строки;
  - Разделение строки - O(log(n));
  - Удаление подстроки - O(log(n));
  

- _Какая-то другая справочная информация о проекте._
  - При работе с rope string не требуется O (n) дополнительной памяти (массивы нуждаются в ней для операций копирования);
  - Rope не требуют больших непрерывных пространств памяти;
  - Выделяется дополнительная память, необходимая для хранения родительских узлов;
  - Вырастает сложность некоторых операций;
  - Вырастает сложность исходного кода.

## Я ничо не придумал

**Примечание**. Преподаватель может определить вклад любого из участников команды по истории коммитов.

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Ризван |    50     |  garoriz              |
| Амирхан   |    50     |  mier |


**Девиз команды**
> _Dark deep fantasies_

## Структура проекта

Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

_В этом разделе задаются основые требования к программному и аппаратному обеспечению для успешной работы с проектом._

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Рекомендуемый объем оперативной памяти - 8 ГБ.
4. Свободное дисковое пространство объемом ~ 1 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

### Windows

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-rope.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-rope

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

_Тестовые данные хранятся в формате txt в dataset/data/_

Для генерации тестовых данных необходимо запустить метод main в файле create_txt_dataset.cpp, находящемся в папке dataset.
Или же создать иной метод, для этого можно воспользоваться методами из create_txt_dataset.cpp

Тестовые данные это файлы в формате txt, содержащие в себе строку определённой длины n или две строки длины n/2 каждая.

Тестовые данные для методов insert и merge(по 2 строки длины n/2) находятся в /dataset/data/insert_merge

Тестовые данные для методов split, delete, find(строки длины n) находятся в /dataset/data/find_split_delete

#### Контрольные тесты (benchmarks)

Для запуска контрольных тестов необходимо необходимо предварительно сгенерировать или скачать готовый набор тестовых данных и запустить метод main в файле benchmarks.cpp, находящемся в папке benchmark.
Также можно создать иной метод для запуска контрольных тестов, используя методы из benchmarks.cpp, который во вход принимают размер тестовых данных(100, 500, 1000 и т.д) и
 номер набора(число от 1 до 10).

Контрольные тесты замеряют время работы каждого из 5 основных методов rope.

##### Список методов контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `time_for_merge` | слияние двух строк   | _время_         |
| `time_for_insert`           | добавление строки в другую строку в случайное место | _время_ |
| `time_for_find` | Поиск элемента строки по случайному индексу | _время_
| `time_for_split` | Разделение строки на две в случайном месте | _время_
| `time_for_delete` | Удаление подстроки случайных размеров | _время_

##### Запуск контрольных тестов

Для запуска контрольных тестов можно запустить main в benchmark/benchmarks.cpp

Или же написать свой программу для запуска контрольных тестов, воспользовавшись методами в benchmarks.cpp, которые на вход принимают
два int значения: 

первое - кол-во входных данных(100, 500, 1000....); 

второе - номер тестовых данных с таким кол-вом входящих данных.

## Источники

_Список использованных при реализации структуры данных источников._

Русскоязычные источники:

[Статья на habr](https://habr.com/ru/post/144736/)

[Реализация на github](https://github.com/sayan9112/rope/blob/master/rope.cpp)

Англоязычные источники:

[Wikipedia](https://en.wikipedia.org/wiki/Rope_(data_structure))

[Статья на geeksforgeeks](https://www.geeksforgeeks.org/ropes-data-structure-fast-string-concatenation/)