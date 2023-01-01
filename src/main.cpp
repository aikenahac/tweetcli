#include <iostream>
#include <string>
#include <cstring>

#include "utils/string_util.cpp"
#include "models/tweet.cpp"

int main(int argc, char *argv[]) {
  std::string argument;
  Tweet tweet;

  argument = convert_to_string(argv[1]);

  if (argument == "post") tweet.post_tweet(); 
  else if (argument == "get") tweet.get_env();

  return 0;
}