//
// Created by abdelrhman on 11/3/18.
//

#ifndef HTTPSERVERCLIENT_REQUEST_H
#define HTTPSERVERCLIENT_REQUEST_H

#include <string>
#include <vector>
#include <map>
#include "HttpMessage.h"

using namespace std ;


class Request: HttpMessage {

 public:
  Request();
  Request(HTTP_METHODS method, const string &file_name, const string &host_name, const string &body = "");
  virtual ~Request();
  void setFileName(const string &file_name);
  void setHostName(const string &host_name);
  const string &getFile_name() const;
  const string &getHost_name() const;

     void setMethod(HTTP_METHODS method){
         HttpMessage::setMethod(method);
     }
     HTTP_METHODS getMethod() const{
         return HttpMessage::getMethod();
     }
    void setKeyVal(string key, string val) {
        HttpMessage::setKeyVal(key,val);
    }
    void setBody(string body){
        HttpMessage::setBody(body);
    }
    string getKey_val(string key){
        return HttpMessage::getKey_val(key);
    }

  string toString();

 private:
    string fileName , hostName ;



};

#endif //HTTPSERVERCLIENT_REQUEST_H
