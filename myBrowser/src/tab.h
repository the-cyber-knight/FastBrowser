#ifndef TAB_H
#define TAB_H

#include <string>
#include <vector>

class Tab {
public:
    Tab(const std::string& url);
    ~Tab();

    void loadPage(const std::string& url);
    void goBack();
    void goForward();
    void refresh();
    
    std::string getURL() const;
    bool hasHistory() const;

private:
    std::string url;
    std::vector<std::string> history;
    size_t historyIndex;
};

#endif // TAB_H