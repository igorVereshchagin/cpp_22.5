#include <iostream>
#include <string>
#include <map>

bool is_anagram(std::string str1,std::string str2);

int main()
{
  std::string str_first;
  std::string str_second;
  std::cout << "Input string 1: " << std::endl;
  std::cin >> std::ws;
  std::getline(std::cin, str_first);
  std::cout << "Input string 2: " << std::endl;
  std::cin >> std::ws;
  std::getline(std::cin, str_second);
  std::cout << is_anagram(str_first, str_second) << std::endl;
  return 0;
}

bool is_anagram(std::string str1,std::string str2)
{
  if (str1.length() != str2.length())
    return false;
  std::map<char, int> map1;
  std::map<char, int> map2;
  for (int i = 0; i < str1.length(); i++)
  {
    map1[str1[i]]++;
    map2[str2[i]]++;
  }
  std::map<char, int>::iterator it1 = map1.begin();
  std::map<char, int>::iterator it2 = map2.begin();
  while(it1 != map1.end() && it2 != map2.end())
  {
    if (it1->first != it2->first || it1->second != it2->second)
      return false;
    it1++;
    it2++;
  }
  if (it1 != map1.end() || it2 != map2.end())
    return false;
  return true;
}