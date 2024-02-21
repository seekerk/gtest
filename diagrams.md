# Примеры диаграмм на Mermaid/PlantUML

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
```mermaid
stateDiagram-v2
node1: Копия репозитория шаблона
node2: Шаблон без кода и примеров тестов
node3: Шаблон с кодом и тестами

[*] --> node1
node1 --> node2
node2 --> node3
node3 --> [*]

note left of node1
  код фибоначчи
  примеры тестов
end note

note right of node3
  функция нахождения корней
  тесты функции
end note
```

* [оффлайн файл](diagrams/state-machine.puml)

![Диаграмма состояний](diagrams/state-machine.png)

## Диаграмма последовательности (Sequence diagram)

* Документация: https://mermaid.js.org/syntax/sequenceDiagram.html
* Онлайн генерация (формат mermaid)
```mermaid
sequenceDiagram
actor student as Студент
participant project as Проект
participant local_storage as .git
participant github as Github
participant github_actions as Github actions

student->>project: Написание кода
project ->> local_storage : git commit
local_storage ->> github : git push
activate github
github ->> github_actions : Запуск CI/CD
activate github_actions
github_actions ->> github_actions : компиляция
github_actions ->> github_actions : тестирование
github_actions ->> coveralls : Оценка покрытия
github_actions ->> sonarcloud : Стат.анализ
github_actions -->> github : бейдж
deactivate github_actions
github -->> student : Результаты CI/CD
deactivate github
```

* [оффлайн файл](diagrams/sequence.puml)
* Документация: https://plantuml.com/ru/sequence-diagram

![Диаграмма последовательности](diagrams/sequence.png)
