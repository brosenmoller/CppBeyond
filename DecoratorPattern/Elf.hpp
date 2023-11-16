#pragma once

#include "Npc.hpp"

class Elf : public Npc
{
public:
	Elf() : Npc() {};

	void Render() override;
};