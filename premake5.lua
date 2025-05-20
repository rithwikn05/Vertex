workspace "Vertex"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
outputBaseDir = "."

project "Vertex"
	kind "SharedLib"
	language "C++"
	location "."
		
	targetdir  (outputBaseDir .. "/bin/" .. outputDir .. "/%{prj.name}")
	objdir (outputBaseDir .. "/bin-int/" .. outputDir .. "/%{prj.name}")

	pchheader "vxpch.h"
	pchsource "src/vxpch.cpp"

	files {
		"src/**.h", 
		"src/**.cpp"
	}

	includedirs {
		"vendor/spdlog/include",
		"src/"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		characterset "Unicode"
		buildoptions { "/utf-8" }

		defines {
			"VX_PLATFORM_WINDOWS",
			"VX_BUILD_DLL"
		}

		postbuildcommands {
			'{COPY} "%{cfg.buildtarget.relpath}" "./bin/' .. outputDir .. '/Sandbox/"'
		}

	filter "configurations:Debug"
		defines "VX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VX_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
		
	targetdir  (outputBaseDir .. "/bin/" .. outputDir .. "/%{prj.name}")
	objdir (outputBaseDir .. "/bin-int/" .. outputDir .. "/%{prj.name}")


	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"vendor/spdlog/include",
		"%{prj.name}/src",
		"src"
	}

	links {
		"Vertex"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		characterset "Unicode"
		buildoptions { "/utf-8" }

		defines {
			"VX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VX_DIST"
		optimize "On"