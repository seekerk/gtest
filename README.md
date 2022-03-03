[![CI/CD GitHub Actions](https://github.com/seekerk/gtest/actions/workflows/test-action.yml/badge.svg)](https://github.com/seekerk/gtest/actions/workflows/test-action.yml)
[![Coverage Status](https://coveralls.io/repos/seekerk/gtest/badge.svg?branch=master)](https://coveralls.io/github/seekerk/gtest?branch=master)
[![Quality Gate](https://sonarcloud.io/api/project_badges/measure?project=seekerk_gtest&metric=alert_status)](https://sonarcloud.io/dashboard?id=seekerk_gtest)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=seekerk_ctest&metric=bugs)](https://sonarcloud.io/summary/new_code?id=seekerk_ctest)
[![Code smells](https://sonarcloud.io/api/project_badges/measure?project=seekerk_gtest&metric=code_smells)](https://sonarcloud.io/dashboard?id=seekerk_gtest)

# Пример работы связки Qt + Google Test (gtest) + QtCreator

## Загрузка и запуск примера на локальном компьютере

1. Выполнить проверку наличия библиотек Qt и среды разработки Qt Creator. 
В ОС Ubuntu необходимо установить пакеты `qt5-default qt5-qmake qtcreator`. 
В ОС Windows необходимо установить Qt и компилятор, например, mingw с помощью онлайн установщика https://www.qt.io/download-qt-installer
2. Выполнить клонирование репозитория с помощью утилиты git (`git clone ....`).
3. Для подгрузки gtest необходимо выполнить команды:
```shell
git submodule init
git submodule update
```
4. Запустить создание Make файлов:
```shell
qmake
```
5. выполнить сборку приложения:
```shell
make
```
6. Выполнить запуск тестов
```shell
./tests/tests
```

## Создание проекта на базе примера

1. Удалить каталог .git из директории проекта
2. Выполнить инициализацию нового репозитория
```shell
git init
```
3. Выполнить модификацию приложения в каталоге `app/`: 
   - удалить модуль myfunc, 
   - создать модуль(и) со своими функциями, 
   - исправить подключение заголовочных файлов и работуглавной функции (файл `main.c`) 
   - обновить перечень файлов проекта (файл `app.pro`, секции `SOURCES` и `HEADERS`)
4. Выполнить модификацию тестов в каталоге `tests/`:
   - удалить примеры тестов
   - добавить заголовочные файлы со своими тестами
   - обновить список подключений заголовочных файлов в main.cpp
   - обновить перечень файлов проекта включая файлы приложения (файл `tests.pro`, секции `SOURCES` и `HEADERS`)
5. Подключить внешний репозиторий следуя инструкциям Github
6. Загрузить код на Github

### Запуск тестов на Github actions
1. Сборка и запуск приложения осуществляется с помощью github actions.
2. Конфигурационный скрипт лежит в каталоге .gihub/workflows
3. Необходимо удостовериться что выполняется сборка и запуск тестов до секции с отправкой статистик
4. Обновить бейдж сборки в соответствии с названием профиля и репозитория

### Соединение с coveralls.io

1. Необходимо зайти на сайт coveralls.io и авторизоваться через github
2. Подключить репозиторий с своим проектом
3. В настройках репозитория скопировать токен
4. В настройках гитхаба в разделе `secrets - actions` создать ключ `coveralls_token` со значением токена
5. Запустить github actions, проверить успешное выполнение задания gtest-tests
6. проверить появление статистики на coveralls.io
7. Обновить бейдж покрытия в соответствии с названием профиля и репозитория

### Соединение с sonarcloud
1. Необходимо зайти на сайт https://sonarcloud.io и авторизоваться через github
2. Создать новый проект, выбрать github actions, указать свой репозиторий
3. Скопировать токен проекта, в настройках github в разделе `secrets - actions` создать ключ `sonar_token` со значением токена
4. продолжить настройку проекта на sonarcloud до раздела с конфигурационным файлом
5. Изменить значения названия проекта и организации в файле sonar-project.properties в соответствии с предложенными
6. Запустить github actions, проверить успешное выполнение задания gtest-tests
7. проверить появление результатов на sonarcloud
8. Обновить бейджи статистик в соответствии с названием профиля и репозитория
