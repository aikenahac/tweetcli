#include <string>
#include <cstring>

std::string convert_to_string(char* a) {
    int i;
    std::string s = "";
    for (i = 0; i < strlen(a); i++) {
        s = s + a[i];
    }
    return s;
}