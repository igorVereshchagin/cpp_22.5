#include <iostream>
#include <map>
#include <string>
#include <vector>

bool check_phone(std::string &str);

int main()
{
  std::map<std::string, std::string> yp_phone;
  std::map<std::string, std::vector<std::string>> yp_name;
  std::string req;
  do
  {
    std::cout << "Input request: " << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin, req);
    if (req == "exit")
    {
      continue;
    }
    else if (req == "list")
    {
      for (std::map<std::string, std::string>::iterator it_phone = yp_phone.begin();
           it_phone != yp_phone.end(); it_phone++)
        std::cout << it_phone->first << " " << it_phone->second << std::endl;
      for (std::map<std::string, std::vector<std::string>>::iterator it_name = yp_name.begin();
           it_name != yp_name.end(); it_name++)
      {
        std::cout << it_name->first << ": ";
        for (std::vector<std::string>::iterator it = it_name->second.begin();
             it != it_name->second.end(); it++)
          std::cout << *it << " ";
        std::cout << std::endl;
      }
      continue;
    }
    int pos = req.find(' ');
    if (pos != std::string::npos)
    {
      std::string str_phone = req.substr(0, pos);
      std::string str_name = req.substr(pos + 1);
      std::map<std::string, std::string>::iterator it_phone = yp_phone.find(str_phone);
      if ((it_phone != yp_phone.end()) && (it_phone->second != str_name))
      {
        std::map<std::string, std::vector<std::string>>::iterator it_name = yp_name.find(it_phone->second);
        if (it_name != yp_name.end())
        {
          for (std::vector<std::string>::iterator it = it_name->second.begin(); it != it_name->second.end(); it++)
          {
            if (*it == str_phone)
            {
              it_name->second.erase(it);
              if (0 == it_name->second.size())
                yp_name.erase(it_name);
              break;
            }
          }
        }
      }
      yp_phone[str_phone] = str_name;
      std::map<std::string, std::vector<std::string>>::iterator it_name = yp_name.find(str_name);
      if (it_name != yp_name.end())
      {
        it_name->second.insert(it_name->second.end(), str_phone);
      }
      else
      {
        std::vector<std::string> vec_phone = {str_phone};
        yp_name.insert(std::pair<std::string, std::vector<std::string>>(str_name, vec_phone));
      }
    } else if (check_phone(req))
    {
      std::map<std::string, std::string>::iterator it_phone = yp_phone.find(req);
      if (it_phone != yp_phone.end())
      {
        std::cout << it_phone->first << " " << it_phone->second << std::endl;
      }
    } else
    {
      std::map<std::string, std::vector<std::string>>::iterator it_name = yp_name.find(req);
      std::cout << it_name->first << ": ";
      for (std::vector<std::string>::iterator it = it_name->second.begin();
           it != it_name->second.end(); it++)
        std::cout << *it << " ";
      std::cout << std::endl;
    }
  }while(req != "exit");
  return 0;
}

bool check_digit(char c)
{
  return (c >= '0' && c <= '9');
}

bool check_phone(std::string &str)
{
  bool res = true;
  if (str.length() != 8)
    return false;
  if (str[2] != '-' || str[5] != '-')
    return false;
  if (check_digit(str[0]) && check_digit(str[1]) &&
        check_digit(str[3]) && check_digit(str[4]) &&
        check_digit(str[6]) && check_digit(str[7]))
    return true;
  else
    return false;

}