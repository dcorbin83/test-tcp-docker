#ifndef CONFIG_H // include guard
#define CONFIG_H

#include <string>

class Config
{

public:
    Config();
    explicit Config(const int iPort, const std::string &iMessage);
    Config(const Config& iConf);
    
    virtual ~Config();

    void set(const char *ioPort, const char *ioMessage);
    int getPort() const;

    const char *getMessage() const;

    static const int DEFAULT_PORT;
    static const char * DEFAULT_MESSAGE;

private:
    int _port;
    std::string _message;
};
#endif //CONFIG_H
