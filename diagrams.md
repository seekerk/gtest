# Примеры диаграмм на Mermaid

## Литература и справочные руководства
* https://mermaid.js.org/
* https://plantuml.com/
* https://habr.com/ru/articles/652867/

## Диаграмма активности (Activity diagram)
* Документация: https://plantuml.com/ru/activity-diagram-beta
* Онлайн генерация (формат mermaid, используется инструмент Диаграммы состояний)
```mermaid
stateDiagram-v2
node1: Скачать шаблон проекта
node2: шаблон скачан архивом?
node3: удалить папку googletest в external
node4: подключить связь с googletest репозиторием вручную
node5: инициировать и обновить подмодули
node6: Реализовать функцию вычисления **корней** уравнения
node7: Написать тесты
node8: Выложить в Github
state if_state <<choice>>

[*] --> node1
node1 --> node2
node2 --> if_state
if_state --> node3 : Да
node3 --> node4
if_state --> node5 : нет 
node4 --> node6
node5 --> node6
node6 --> node7
node7 --> node8
node8 --> [*]
```
* [оффлайн файл](diagrams/activity.puml)

![Диаграмма активности](diagrams/activity.png)

## Диаграмма состояний (State Machine diagram)

* Онлайн генерация (формат mermaid)
