#include "browser.h"
#include "ui.h"
#include <iostream>

Browser::Browser() : isRunning(false), ui(nullptr) {}

Browser::~Browser() {
    if (ui) {
        delete ui;
    }
}

bool Browser::initialize() {
    ui = new UI();
    ui->initialize();
    isRunning = true;
    return true;
}

void Browser::start() {
    if (!isRunning) {
        std::cerr << "Browser is not initialized!" << std::endl;
        return;
    }

    std::cout << "Starting browser..." << std::endl;

    ui->render();  // Отображаем UI
    shutdown();
}

void Browser::shutdown() {
    std::cout << "Shutting down the browser..." << std::endl;
    isRunning = false;
}