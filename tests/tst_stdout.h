#ifndef TST_STDOUT_H
#define TST_STDOUT_H

#include <gtest/gtest.h>

#include<fstream>

// dup, dup2
#include <unistd.h>

#include <fcntl.h>

extern "C" {
#include "myfunc.h"
}


#define MAXLINE 1024

TEST(TestStdOut, TestStdOut) {
    // тест проверки вывода на экран нужных фраз с помощью перехвата потока (dup/dup2) и побайтового сравнения результатов

    // запоминаем старый поток вывода
    int oldOutput = dup(STDOUT_FILENO);

    // открываем файл для записи результата
    FILE *outFile = fopen("TestStdOut_TestStdOut.out", "wb");

    // проверяем что файл открылся
    ASSERT_TRUE(outFile != NULL);

    // закрываем выходной поток и заменяем его на файл
    close(STDOUT_FILENO);
    dup2(fileno(outFile), STDOUT_FILENO);

    // запускаем функцию
    printStdoutMessages();

    // очищаем выходной поток
    fflush(stdout);

    // закрываем файл
    fclose(outFile);

    // возвращаем вывод на место
    dup2(oldOutput, STDOUT_FILENO);

    // открываем оригинал и результат
    char *filename = (char *)malloc(sizeof(char) * 1024);
    sprintf(filename, "%s/TestSTDOut_output.txt", INPUTDIR);
    int testFd = open("TestStdOut_TestStdOut.out", O_RDONLY);
    int originFd = open(filename, O_RDONLY);
    free(filename);

    ASSERT_NE(testFd, -1);
    ASSERT_NE(originFd, -1);

    // подготовка к чтению данных
    int outputCount;
    int originCount;
    char outBuffer[MAXLINE];
    char originBuffer[MAXLINE];

    do {
        // блоковое чтение данных
        outputCount = read(testFd, outBuffer, MAXLINE - 1);
        originCount = read(originFd, originBuffer, MAXLINE - 1);
        ASSERT_EQ(outputCount, originCount);
        for (int i = 0; i < outputCount; i++) {
            ASSERT_EQ(outBuffer[i], originBuffer[i]);
        }
    } while (outputCount > 0);

    // все отлично, закрываем
    close(testFd);
    close(originFd);
}

TEST(TestStdOut, usingCapture) {
    // тест проверки вывода на экран нужных фраз с помощью библиотеки STD и gtest Capture

    // подключаем захват вывода
    testing::internal::CaptureStdout();

    // зпускаем функцию
    printStdoutMessages();

    //получаем результат
    std::string output = testing::internal::GetCapturedStdout();

    // читаем ожидаемую строку из файла
    char *filename = (char *)malloc(sizeof(char) * 1024);
    sprintf(filename, "%s/TestSTDOut_output.txt", INPUTDIR);

    std::ifstream f(filename);
    free(filename);
    std::string content;
    content.assign( (std::istreambuf_iterator<char>(f) ),
                    (std::istreambuf_iterator<char>()    ) );

    // сравниваем значения
    ASSERT_EQ(output, content);
    f.close();
}

#endif // TST_STDOUT_H
