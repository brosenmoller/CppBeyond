#pragma once

#include "NPC.hpp"

class NpcDecorator : public Npc
{
public:
	NpcDecorator(Npc* npc) { encapsulatedNPC = npc; }
	~NpcDecorator() = default;

	void Render() final;
	virtual void DecoraterRender() = 0;

private:
	Npc* encapsulatedNPC;
};