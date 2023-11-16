#include "NpcFactory.hpp"

#include "Elf.hpp"
#include "Orc.hpp"

#include "NpcDecorators/BuilderNpcDecorator.hpp"
#include "NpcDecorators/FarmerNpcDecorator.hpp"
#include "NpcDecorators/ShamanNpcDecorator.hpp"

Npc* NpcFactory::GetElf(bool shaman, bool farmer, bool builder)
{
    Npc* npc = new Elf();

    if (shaman)
    {
        npc = new ShamanNpcDecorator(npc);
    }
    if (farmer)
    {
        npc = new FarmerNpcDecorator(npc);
    }
    if (builder)
    {
        npc = new BuilderNpcDecorator(npc);
    }

    return npc;
}

Npc* NpcFactory::GetOrc(bool shaman, bool farmer, bool builder)
{
    Npc* npc = new Orc();

    if (shaman)
    {
        npc = new ShamanNpcDecorator(npc);
    }
    if (farmer)
    {
        npc = new FarmerNpcDecorator(npc);
    }
    if (builder)
    {
        npc = new BuilderNpcDecorator(npc);
    }

    return npc;
}