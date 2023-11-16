#pragma once

#include "Npc.hpp"

class Orc : public Npc
{
public:
	Orc() : Npc() {};

	void Render() override;
};