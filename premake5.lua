workspace "Vertex"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
outputBaseDir = "."

IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["ImGui"] = "vendor/imgui"
include "vendor/GLFW"
include "vendor/Glad"
include "vendor/imgui"


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
		"src/",
		IncludeDir.GLFW,
		IncludeDir.Glad,
		IncludeDir.ImGui
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"
		characterset "Unicode"
		buildoptions { "/utf-8" }

		defines {
			"VX_PLATFORM_WINDOWS",
			"VX_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands {
			'{COPY} "%{cfg.buildtarget.relpath}" "./bin/' .. outputDir .. '/Sandbox/"'
		}

	filter "configurations:Debug"
		defines "VX_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "VX_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "VX_DIST"
		buildoptions "/MDd"
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
		staticruntime "Off"
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