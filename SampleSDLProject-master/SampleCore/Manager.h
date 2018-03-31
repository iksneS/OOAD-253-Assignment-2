#pragma once


#include <SDL\SDL.h>

namespace core
{


	class Manager
	{
	public:

		Manager();
		~Manager();

		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();

	};

}