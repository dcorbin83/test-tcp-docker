#include "apps/client/include/server_client.hpp"
#include "apps/client/include/client.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <thread>
#include <cstdlib>
#include <fstream>

Server_client::Server_client()
{
}

int main(int argc, char *argv[])
{
    std::cout << "enter in main" << std::endl;

    Server_client srv;
    srv.run();
} 

void Server_client::run()
{
    std::cout << "start server_client run" << std::endl;
    bool isLooping = false;
    int aMsec = 1000;
    float aMaxDuration = 0.f;
    if(std::getenv(std::getenv("CLIENT_DELAY_MS")))
    {
        isLooping = true;
        aMsec = atoi(std::getenv("CLIENT_DELAY_MS"));
    }
    if (std::getenv("CLIENT_MAX_DURATION_SECONDS") != NULL)
    {
        isLooping = true;
        aMaxDuration = atof(std::getenv("CLIENT_MAX_DURATION_SECONDS"));
    }

    std::string path_to_file = "/data/history/client_history.txt";
    std::cout << "we will store output history in " << path_to_file << std::endl;

    std::fstream file(path_to_file, std::ios::in | std::ios::out | std::ios::app);
    if (!file)
    {
        std::cerr << "Unable to open file.\n";
        std::cout << "We will run whithout saving history" << std::endl;
    }

    std::string data;
    unsigned int loopNb = 0;
    double alim = 0;
    Client client;
    std::string url = client.getUrl() + ":" + client.getPort();
    std::cout << "client use url: " << url << std::endl;
    

    if (aMsec > 0)
    {
        alim = 1000.0 * (aMaxDuration / aMsec);
    }
    ////// send QUERY /////
    do
    {
        data = client.getDate();
        std::this_thread::sleep_for(std::chrono::milliseconds(aMsec));
        loopNb++;
        std::cout << data << std::endl;
        file << "Call server number: " << loopNb << " got response: " << data << std::endl;
        data = std::string();
    } while (isLooping && (loopNb < alim));
    file.close();
}
