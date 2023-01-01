#include <string>
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "config.hpp"

class API {
  private:
    std::string api_url = "https://api.twitter.com/2";
    std::string auth_header = "OAuth ";

    Config conf;

  public:
    void set_auth_header();
    void post_request(std::string endpoint, std::string body);
};

void API::set_auth_header() {
  auth_header = auth_header + " oauth_consumer_key=\"" + conf.CONSUMER_KEY + "\", oauth_nonce=\"" + std::to_string(rand()) + "\", oauth_signature_method=\"HMAC-SHA1\", oauth_timestamp=\"" + std::to_string(time(NULL)) + "\", oauth_token=\"" + conf.TOKEN + "\", oauth_version=\"1.0\", oauth_signature=\"";

  auth_header = "authorization: " + auth_header + "\"";
}

void API::post_request(std::string endpoint, std::string body) {
  curlpp::Cleanup cleanup;
  curlpp::Easy request;

  std::string url = api_url + endpoint;


  this->set_auth_header();
  std::cout << "auth header: " << auth_header << "\n";

  request.setOpt(curlpp::options::Url(url));
  std::list<std::string> header = {
    "Content-Type: application/json",
    "accept: application/json",
    auth_header
  };

  request.setOpt(new curlpp::options::HttpHeader(header)); 

  request.setOpt(new curlpp::options::PostFields(body)); 
  request.setOpt(new curlpp::options::WriteStream(&std::cout));

  request.perform();
}