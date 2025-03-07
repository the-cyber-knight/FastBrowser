#ifndef BROWSER_H
#define BROWSER_H

#include "ui.h"

class Browser {
public:
    Browser();
    ~Browser();

    bool initialize();
    void start();
    void shutdown();

private:
    bool isRunning;
    UI* ui;  // Добавляем это поле, чтобы у браузера был указатель на UI
};

#endif // BROWSER_H