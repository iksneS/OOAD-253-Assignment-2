// SampleGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Engine.h>
#include <iostream>
#include "Scene1.h"

int main(int argc, char* args[])
{

	using  namespace core;
	Engine e(new Scene1());

	if (e.init() == 0) {
		//return e.Run();
		
	}


	return 0;

	//-1
}

