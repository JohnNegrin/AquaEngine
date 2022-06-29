workspace "Aqua"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Aqua"
	location "Aqua"
	kind "SharedLib"
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
	"%{prj.name}/src",
	"%{prj.name}/vendor/spdlog/include/"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"AQ_PLATFORM_WINDOWS",
			"AQ_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AQ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AQ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AQ_DIST"
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
	"Aqua/vendor/spdlog/include/",
	"Aqua/src"
	}

	links 
	{
		"Aqua"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"AQ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AQ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AQ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AQ_DIST"
		optimize "On"
