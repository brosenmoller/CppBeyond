#include "NpcDecorator.hpp"

void NpcDecorator::Render()
{
	DecoraterRender();
	encapsulatedNPC->Render();
}
