#ifndef ADBLOCK_H
#define ADBLOCK_H

#include <string>
#include <vector>

class AdBlock {
public:
    AdBlock(const std::string& rulesFile);
    ~AdBlock();

    bool loadRules();
    
    bool isAd(const std::string& url);

private:
    std::vector<std::string> rules;  // Список правил блокировки
    std::string rulesFile;  // Путь к файлу с правилами

    void parseRules();
};

#endif