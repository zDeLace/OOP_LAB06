#pragma once
#include <string>
#include <fstream>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void onKill(const std::string& killer, const std::string& victim) = 0;
};

class LogObserver : public Observer {
    std::string filename;

public:
    LogObserver(std::string file) : filename(std::move(file)) {}

    void onKill(const std::string& killer,
                const std::string& victim) override {
        std::ofstream out(filename, std::ios::app);
        out << killer << " killed " << victim << "\n";
    }
};
