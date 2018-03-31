#pragma once

#include <stdio.h>
#include <vector>
#include "Scene.h"

namespace scene {
	class Scene;
}

namespace core {


	class Engine
	{

	private:
		void update();
		void draw() const;
		int shutdown();


		bool isRunning;
		std::vector<class Manager*> managers;

		scene::Scene* Scene1;

		

	public:
		Engine(scene::Scene *s);
		~Engine();

		

		int init();
		void print();
		int Run();




	};

};

