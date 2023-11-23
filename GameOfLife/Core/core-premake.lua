project "Core"
	kind "StaticLib"
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
		"vendor",
		"%{IncludeDir.SFML}"
	}

	links
	{
		"SFML",
	}

	libdirs 
	{
		"vendor/SFML/extlibs/libs-msvc-universal/x64"
	}

	defines
	{
		"SFML_STATIC"
	}

	links
		{
			"opengl32",
			"freetype",
			"winmm",
			"gdi32",
			"flac",
			"vorbisenc",
			"vorbisfile",
			"vorbis",
			"ogg",
			"ws2_32"
		}		

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

		defines 
		{ 
			"DEBUG" 
		}

		links
		{	
			"sfml-graphics-s-d",
			"sfml-window-s-d",
			"sfml-system-s-d",
			"sfml-audio-s-d",
			"sfml-network-s-d"
		}

		libdirs
		{
			"vendor/SFML/lib/Debug"
		}

	filter "configurations:Release"
		runtime "Release"
        	optimize "on"
		defines 
		{ 
			"NDEBUG" 
		}

		links
		{	
			"sfml-graphics-s",
			"sfml-window-s",
			"sfml-system-s",
			"sfml-audio-s",
			"sfml-network-s"
		}

		libdirs
		{
			"vendor/SFML/lib/Release"
		}
