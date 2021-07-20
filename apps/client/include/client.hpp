#ifndef CLIENT_H
#define CLIENT_H
#include <string>

class Client{

    public:
        Client();
       
        std::string getUrl();  // return the url to target date_server base on env var
        std::string getPort();
        std::string getDate(); // return date_server response
};
#endif
