#ifndef APPLICATION_H
#define APPLICATION_H
#include <stdlib.h>
#include <string>
constexpr int windowsHeigth = 480;
constexpr int windowsWidth = 480;
const std::string resourcesPath = "../resources/";
constexpr char title[] = "RetroCheckers";
class Application {
public:
  int InitApp();
};
#endif