# Лабораторная работа №1
## На тему:Наследование и полиморфизм.
Выполнили: Авдеев АЮ
           Бреславский НВ  
Задание: На языке С++ разработать программу, реализующую функции расчета площади и периметра геометрических фигур. Должны быть реализованы следующие классы:

1. Класс Figure, который содержит множество точек – вершин плоской геометрической фигуры. В конструктора необходимо передать массив точек.

2. Класс Rectangle, моделирующий сущность прямоугольник и наследуемый от Figure. В конструктор необходимо передать ширину и длину прямоугольника, которые необходимо пересчитать в координаты вершин фигуры (использовать множество вершин из родительского класса)

3. Класс Square, моделирующий сущность квадрат и наследуемый от Rectangle. В конструктор необходимо передать длину стороны квадрата

4. Класс Circle, моделирующий сущность окружность (круг) и наследуемый от Figure. Предусмотреть 2 конструктора:

· принимающий радиус окружности;

· принимающий две точки – центр окружности и точку на окружности.

Для всех классов определить функции getPerimetr (расчет периметра) и getSquare (расчет площади). Переопределить функции для каждого класса, если необходимо.
