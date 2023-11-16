#include <iostream>

#include "Npc.hpp"
#include "NpcFactory.hpp"

int main()
{
    NpcFactory npcFactory = NpcFactory();

    Npc* farmerElf = npcFactory.GetElf(false, true, false);
    farmerElf->Render();

    Npc* shamanBuilderOrc = npcFactory.GetOrc(true, false, true);
    shamanBuilderOrc->Render();

    Npc* shamanFarmerBuilderElf = npcFactory.GetOrc(true, true, true);
    shamanFarmerBuilderElf->Render();
}
