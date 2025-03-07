#include "tab.h"
#include <iostream>

Tab::Tab(const std::string& initialURL) : url(initialURL), historyIndex(0) {
    history.push_back(initialURL);
}

Tab::~Tab() {
    std::cout << "Tab with URL " << url << " destroyed!" << std::endl;
}

void Tab::loadPage(const std::string& newURL) {
    url = newURL;
    history.push_back(newURL);
    historyIndex = history.size() - 1;
    std::cout << "Loaded page: " << newURL << std::endl;
}

void Tab::goBack() {
    if (historyIndex > 0) {
        --historyIndex;
        url = history[historyIndex];
        std::cout << "Went back to: " << url << std::endl;
    }
}

void Tab::goForward() {
    if (historyIndex < history.size() - 1) {
        ++historyIndex;
        url = history[historyIndex];
        std::cout << "Went forward to: " << url << std::endl;
    }
}

void Tab::refresh() {
    std::cout << "Refreshing: " << url << std::endl;
}

std::string Tab::getURL() const {
    return url;
}

bool Tab::hasHistory() const {
    return history.size() > 1;
}