workspace "PaveboEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "PaveboEngine/vendor/GLFW/include"

include "PaveboEngine/vendor/GLFW"

project "PaveboEngine"
	location "PaveboEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pvpch.h"
	pchsource "PaveboEngine/src/pvpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	links
	{
		"GLFW",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PV_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PV_DIST"
		buildoptions "/MD"
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
	includedirs
	{
		"PaveboEngine/vendor/spdlog/include",
		"PaveboEngine/src"
	}
	links
	{
		"PaveboEngine"
	}
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"PAVEBO_PLATFORM_WINDOWS"
	}
	
		

	filter "configurations:Debug"
		defines "PV_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PV_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PV_DIST"
		buildoptions "/MD"
		optimize "On"
