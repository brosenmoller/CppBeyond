#pragma once

#include "../NpcDecorator.hpp"
#include "../Npc.hpp"

class ShamanNpcDecorator : public NpcDecorator
{
public:
	ShamanNpcDecorator(Npc* npc) : NpcDecorator(npc) {};

	void DecoraterRender() override;
};