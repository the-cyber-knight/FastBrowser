#include <iostream>
#include "browser.h"

int main() {
    // Инициализация браузера
    Browser browser;

    // Запуск браузера
    if (browser.initialize()) {
        std::cout << "Browser initialized successfully!" << std::endl;
        browser.start();
    } else {
        std::cerr << "Error initializing the browser." << std::endl;
    }

    return 0;
}