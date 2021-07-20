
#include "third_party/Config/include/Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int Config::DEFAULT_PORT = 8080;
const char *Config::DEFAULT_MESSAGE = "undifined";
Config::Config()
{
}
Config::~Config()
{
}
Config::Config(const int iPort, const std::string &iMessage) : _port(iPort), _message(iMessage)
{
}
Config::Config(const Config& iConf) : _port(iConf._port), _message(iConf._message)
{
}
void Config::set(const char *ioPort, const char *ioMessage)
{

    if (ioPort != nullptr && (strcmp(ioPort, "") != 0))
    {
        _port = atoi(ioPort);
    }
    else
    {
        _port = DEFAULT_PORT;
    }
    if (ioMessage != nullptr && (strcmp(ioMessage, "") != 0))
    {
        _message = ioMessage;
    }
    else
    {
        _message = DEFAULT_MESSAGE;
    }
}

int Config::getPort() const
{
    return _port;
}

const char *Config::getMessage() const
{
    return _message.c_str();
}
