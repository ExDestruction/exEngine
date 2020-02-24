workspace "exEngine"
	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "exEngine"
	location "exEngine"
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
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EX_PLATFORM_WINDOWS",
			"EX_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EX_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "EX_DIST"
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

	links 
	{
		"exEngine"
	}


	includedirs 
	{
		"exEngine/vendor/spdlog/include",
		"exEngine/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EX_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "EX_DIST"
		optimize "On"