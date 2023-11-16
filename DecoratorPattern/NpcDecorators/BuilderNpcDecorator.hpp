#pragma once

#include "../NpcDecorator.hpp"
#include "../Npc.hpp"

class BuilderNpcDecorator : public NpcDecorator
{
public:
	BuilderNpcDecorator(Npc* npc) : NpcDecorator(npc) {};

	void DecoraterRender() override;
};