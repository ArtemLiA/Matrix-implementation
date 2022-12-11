# Лабораторная работа 2
Данный репозиторий является решением к лабораторной работе 2.

## Общий комментарий к решению.
В ходе реализации работы ставилась задача обеспечить строгий уровень безопаности исключений. Это значит, 
что в случае, если в одном из методов происходит выброс исключения, то после обработки данного исключения система возвращается в состояние, 
в котором находилась до вызова метода. В частности по этой причине некоторый операторы для Matrix были реализованы через move конструктор.

За работу с памятью в данном проекте отвечает класс - реализация одномерного динамического массива Array. Это практически полностью
гарантирует отсутствие утечек памяти при работе с матрицами.

В дальнейшем планируется дополнительная реализация отдельного класса исключений для матриц (см. файл Exceptions.cpp).

### Структура проекта.
В файлах Array.h и Array.cpp находится реализация одномерного динамического массива, отвечающего в классе Matrix за работу с памятью.
В файлах Matrix.h и Matrix.cpp находится реализация матрицы.

### Безопасноть
Данная реализация матрицу гарантирует строгую гарантию безопасности исключений.

### Разрабочик
Ляхов Артём
