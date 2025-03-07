#include "adblock.h"
#include <iostream>
#include <fstream>
#include <sstream>

AdBlock::AdBlock(const std::string& rulesFile) : rulesFile(rulesFile) {
    std::cout << "AdBlock initialized!" << std::endl;
}

AdBlock::~AdBlock() {
    std::cout << "AdBlock destroyed!" << std::endl;
}

bool AdBlock::loadRules() {
    std::ifstream file(rulesFile);
    if (!file.is_open()) {
        std::cerr << "Failed to open rules file: " << rulesFile << std::endl;
        return false;
    }

    // Очистим старые правила
    rules.clear();
    
    // Разбор правил
    parseRules();
    return true;
}

void AdBlock::parseRules() {
    std::ifstream file(rulesFile);
    std::string line;

    // Чтение файла построчно
    while (std::getline(file, line)) {
        if (!line.empty() && line[0] != '#') {  // Пропускаем пустые строки и комментарии
            rules.push_back(line);
        }
    }
}

bool AdBlock::isAd(const std::string& url) {
    // Проверка на совпадение URL с любым из правил
    for (const auto& rule : rules) {
        if (url.find(rule) != std::string::npos) {
            return true;  // URL содержит правило, это реклама
        }
    }
    return false;  // Реклама не найдена
}