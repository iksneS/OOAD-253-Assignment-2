#pragma once
#include "System.h"
#include "Manager.h"
#include <vector>

namespace core
{


	class SystemManager : public Manager
	{
	public:
		SystemManager();
		~SystemManager();

		System* getSystem(SystemType type);

	};

}