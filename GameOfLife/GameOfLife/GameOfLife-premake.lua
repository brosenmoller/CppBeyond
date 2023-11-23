project "GameOfLife"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src",
		"../Core/src",
		"../Core/vendor",
		"../Core/%{IncludeDir.SFML}"
	}

	links
	{
		"Core"
	}

	defines
	{
		"SFML",
		"SFML_STATIC" 
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		kind "ConsoleApp"

		defines 
		{ 
			"DEBUG" 
		}

	filter "configurations:Release"
		runtime "Release"
        optimize "on"
		kind "WindowedApp"

		defines 
		{ 
			"NDEBUG" 
		}