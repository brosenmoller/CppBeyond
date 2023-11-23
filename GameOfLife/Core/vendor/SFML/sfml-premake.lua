project "SFML"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"**.cpp"
	}

	defines
	{
		"SFML_STATIC"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

		defines 
		{ 
			"DEBUG" 
		}

	filter "configurations:Release"
		runtime "Release"
        	optimize "on"
		defines 
		{ 
			"NDEBUG" 
		}
