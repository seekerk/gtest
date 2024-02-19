# Примеры диаграмм на Mermaid

## Литература и справочные руководства
* https://mermaid.js.org/
* https://plantuml.com/

## Диаграмма активности
* Документация: https://plantuml.com/ru/activity-diagram-beta
* Онлайн генерация
```mermaid
@startuml
start
:Скачать шаблон проекта;
if (шаблон скачан архивом) then (да)
  : удалить папку googletest в external;
  : подключить связь с googletest репозиторием вручную;
else (нет)
  : инициировать и обновить подмодули;
endif
:Реализовать функцию вычисления **корней** уравнения;
:Написать тесты;
:Выложить в Github;
stop
@enduml
```
* [оффлайн файл](diagrams/activity.puml)
![Диаграмма активности](diagrams/activity.png)
