#include <iostream>
#include <string>
#include <map>

int main()
{
  std::map<std::string, int> registry;
  std::string req;
  do
  {
    std::cout << "Input request: " << std::endl;
    std::cin >> req;
    if (req == "exit")
    {
      continue;
    }
    else if (req == "next")
    {
      std::map<std::string, int>::iterator it = registry.begin();
      if (it != registry.end())
      {
        std::cout << it->first << std::endl;
        if (0 == --it->second)
          registry.erase(it);
      }
      else
        std::cout << "empty" << std::endl;
      continue;
    }
    else
    {
      registry[req]++;
    }
  }while(req != "exit");
  return 0;
}
