#include "apps/client/include/client.hpp"
#include <boost/asio.hpp>
#include <iostream>
#include <curl/curl.h>

Client::Client()
{
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

std::string Client::getUrl()
{
     std::string address = "localhost";
     if(std::getenv("SERVER_ENDPOINT"))
     {
         address = std::getenv("SERVER_ENDPOINT");
     }
     else if(std::getenv("CONTAINERIZED_ENV"))
     {
         address = "server";
     }
     return "http://" + address;
}

std::string Client::getPort()
{
     std::string port;
     if(std::getenv("SERVER_PORT") != NULL)
     {
          port = std::getenv("SERVER_PORT");
     }
     else
     {
        std::cout << "please provide a valide port";
        exit(1);                    
     }
     return port;
}

std::string read_(boost::asio::ip::tcp::socket & socket) {
       boost::asio::streambuf buf;
       boost::asio::read_until( socket, buf, "\n" );
       std::string data = boost::asio::buffer_cast<const char*>(buf.data());
       return data;
}

std::string Client::getDate()
{
    auto curl = curl_easy_init();
    std::string url = this->getUrl() + ":" + this->getPort();
    std::string data;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    curl_easy_perform(curl);  
 																								
    return data;
}        
