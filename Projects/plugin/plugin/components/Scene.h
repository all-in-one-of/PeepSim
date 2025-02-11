#pragma once
#include <string>
#include <fstream>
#include <streambuf>

#include "Agents.h"
#include "../colliders/Collider.h"
#include "../external/json.hpp"

using SizeType = std::size_t;

// Keep it as a Struct so
// it is just a data container for us.
struct Scene {
  using String = std::string;
  using Json = nlohmann::json;

  PeepSimConfig mConfig;

  Scene(const PeepSimConfig& config);
  ~Scene();

  void loadFromFile(String filePath);

  void addAgent(const Vector& startPos, const Vector& target, const Vector& plannedVelocity,
                float mass, float radius, AgentGroup* group);

  std::vector<Vector> getAllPositions() const;
  void outputFrame(unsigned int frameId);

  void addAgentGroups(std::vector<AgentGroup*> &mAllAgentGroups);
  void addColliders(std::vector<std::pair<Vector, Vector>> &boundingBoxes);

  int mNumAgents{0};

  bool isFileLoaded{ false };

  std::vector<AgentGroup*> mAgentGroups;
  std::vector<Collider*> mColliders;
  SizeType getNumAgents() const;


};
