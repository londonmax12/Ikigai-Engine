#pragma once
#include "Platforms/Platform.h"

namespace Ikigai {
	struct ApplicationConfig {
		int PositionY;
		int PositionX;

		int Width;
		int Height;

		const char* ApplicationName;

		static ApplicationConfig createConfig();
	};

	class Application {
	public:
		bool Init(ApplicationConfig config);
		void Run();

		static Application* GetInstance() { return m_Instance; }
	private:
		inline static Application* m_Instance = nullptr;

		bool m_Running = false;

		bool m_Suspended = false;

		Platform::PlatformState* m_State;

		int m_Width;
		int m_Height;
	};
}