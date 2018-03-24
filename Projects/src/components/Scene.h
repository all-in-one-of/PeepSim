#pragma once
#include <string>
#include <fstream>
#include <streambuf>

#include "Agents.h"
#include "../external/json.hpp"


// Keep it as a Struct so
// it is just a data container for us.
struct Scene {
  using String = std::string;
  using Json = nlohmann::json;
  Scene();
  void loadFromFile(String filePath);

  Agents mAgents;
};
