#pragma once

#include "Npc.hpp"

class NpcFactory
{
public:
	NpcFactory() = default;
	~NpcFactory() = default;

	Npc* GetElf(bool shaman, bool farmer, bool builder);
	Npc* GetOrc(bool shaman, bool farmer, bool builder);
};