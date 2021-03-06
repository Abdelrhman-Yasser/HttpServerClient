//
// Created by muhammed on 02/11/18.
//

#ifndef HTTPSERVERCLIENT_HTTPHANDLER_H
#define HTTPSERVERCLIENT_HTTPHANDLER_H
/**
 * Class for Http thread worker.
 * */

#include <bits/stdc++.h>
#include <pthread.h>
#include "IOHandler.h"
#include "PortHandler.h"
using namespace std;

#define MAX_REQ_SZ 10240

class HttpHandler{

public:
    HttpHandler(IOHandler* ioHandler, PortHandler* portHandler, string serverName);
    ~HttpHandler();
    bool isFinished();
    unsigned long long getCreateTime();
    bool start();

private:

    //attributes
    time_t startTime;
    bool finished;
    IOHandler* ioHandler;
    PortHandler* portHandler;
    pthread_t handler_id;
    string serverName;

    // methods
    void run();
    void close();
    static void * startHelper(void * runner);
    static void cleanupHelper(void * runner);
    void handleGet(vector<string> tokens);
    void handlePost(vector<string> tokens);
    vector<string> tokenize(string s);
};

#endif //HTTPSERVERCLIENT_HTTPHANDLER_H
