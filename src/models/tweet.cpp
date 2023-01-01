#include <iostream>
#include <string>
#include "../utils/api.cpp"

class Tweet {
  private:
    std::string author;
    std::string tweet;

    API api;

    int likes;
    int comments;
    int retweets;
  
  public:
    void get_env();
    void post_tweet();

    void get_tweets(int count) {};
};

void Tweet::post_tweet() {
  std::cout << "Enter the content: ";
  
  do {
    if (tweet.length() > 280)
      std::cout << "Twitter character limit is 280. You had " << tweet.length() << " characters.\nGo again: ";

    std::getline(std::cin, tweet);
  } while (tweet.length() > 280);

  std::cout << "Tweet content: " << tweet << "\n";

  std::string body = "{ \"data\": { \"text\": \"" + tweet + "\" } }";

  api.post_request("/tweets", body);
};

void Tweet::get_env() {
  api.set_auth_header();
}