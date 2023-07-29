workspace "PaveboEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "PaveboEngine"
	location "PaveboEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	include
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "sytem:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"PAVEBO_PLATFORM_WINDOWS", 
			"PV_BUILD_DLL"
		}
	
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PV_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	include
	{
		"%{prj.name}/vendor/spdlog/include"
		"PaveboEngine/PaveboEngine/src"
	}
	links
	{
		"PaveboEngine"
	}
	filter "sytem:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"PAVEBO_PLATFORM_WINDOWS"
		}
	
		

	filter "configurations:Debug"
		defines "PV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PV_DIST"
		optimize "On"
