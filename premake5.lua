workspace "prefixCalculator"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

project "prefixCalculator"
	kind "ConsoleApp"
	language "C++"
	location "prefixCalculator"

	targetdir ("bin/%{cfg.buildcfg}")
	objdir ("bin-int/%{cfg.buildcfg}")

	defines
	{
		"_CRT_NO_SECURE_WARNINGS"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter "Configurations:Debug"
		cppdialect "C++20"
		defines  { "DEBUG" }
		symbols "On"

	filter "Configurations:Release"
		cppdialect "C++20"
		defines { "RELEASE" }
		optimize "On"