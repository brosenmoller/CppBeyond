#pragma once

#include "../NpcDecorator.hpp"
#include "../Npc.hpp"

class FarmerNpcDecorator : public NpcDecorator
{
public:
	FarmerNpcDecorator(Npc* npc) : NpcDecorator(npc) {};

	void DecoraterRender() override;
};