#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for (auto s : my_string) if(string(1, s) != letter) answer += s;

    return answer;
}