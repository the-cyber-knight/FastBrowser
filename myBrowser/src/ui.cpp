#include "ui.h"
#include <iostream>

UI::UI() : activeTabIndex(0) {
    // Создаем первую вкладку
    createNewTab("http://example.com");
}

UI::~UI() {
    for (auto tab : tabs) {
        delete tab;
    }
}

void UI::initialize() {
    std::cout << "UI initialized!" << std::endl;
}

void UI::render() {
    std::cout << "Rendering UI..." << std::endl;
    updateUI();
}

void UI::updateAddressBar(const std::string& url) {
    std::cout << "Address Bar Updated: " << url << std::endl;
}

void UI::createNewTab(const std::string& url) {
    Tab* newTab = new Tab(url);
    tabs.push_back(newTab);
    activeTabIndex = tabs.size() - 1;
    std::cout << "New Tab Created: " << url << std::endl;
}

void UI::switchTab(int index) {
    if (index >= 0 && index < tabs.size()) {
        activeTabIndex = index;
        updateUI();
        std::cout << "Switched to Tab: " << tabs[activeTabIndex]->getURL() << std::endl;
    }
}

void UI::closeTab(int index) {
    if (index >= 0 && index < tabs.size()) {
        delete tabs[index];
        tabs.erase(tabs.begin() + index);
        if (activeTabIndex >= tabs.size()) {
            activeTabIndex = tabs.size() - 1;  // Переключаемся на последнюю вкладку, если текущую закрыли
        }
        updateUI();
        std::cout << "Tab closed!" << std::endl;
    }
}

void UI::onBackButtonClicked() {
    if (tabs[activeTabIndex]->hasHistory()) {
        tabs[activeTabIndex]->goBack();
    }
}

void UI::onForwardButtonClicked() {
    if (tabs[activeTabIndex]->hasHistory()) {
        tabs[activeTabIndex]->goForward();
    }
}

void UI::onRefreshButtonClicked() {
    tabs[activeTabIndex]->refresh();
}

void UI::updateUI() {
    // Обновление интерфейса для активной вкладки
    std::cout << "Active Tab: " << tabs[activeTabIndex]->getURL() << std::endl;
    // В реальной реализации можно будет обновить отображение вкладок на экране
}