-- Beyond-The-Basics
workspace "GameOfLife"
	architecture "x64"
	startproject "GameOfLife"

	configurations
	{
		"Debug",
		"Release"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SFML"] = "vendor/SFML/include"

-- Projects
group "Dependencies"
include "Core/vendor/SFML/sfml-premake.lua"
group ""

include "Core/core-premake.lua"
include "GameOfLife/GameOfLife-premake.lua"
