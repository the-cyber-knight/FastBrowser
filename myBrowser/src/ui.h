#ifndef UI_H
#define UI_H

#include "tab.h"
#include <vector>

class UI {
public:
    UI();
    ~UI();

    void initialize();
    void render();
    void updateAddressBar(const std::string& url);
    void createNewTab(const std::string& url);
    void switchTab(int index);
    void closeTab(int index);
    void onBackButtonClicked();
    void onForwardButtonClicked();
    void onRefreshButtonClicked();

private:
    std::vector<Tab*> tabs;  // Список вкладок
    int activeTabIndex;  // Индекс активной вкладки
    void updateUI();
};

#endif // UI_H