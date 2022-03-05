#include "pch.h"
#include "r2_Director.h"

#include <conio.h>
#include <utility>

#include "r2_eTestResult.h"

namespace r2cm
{
	Director::Director() : mMenu()
	{}

	void Director::Setup( MenuUp menu )
	{
		mMenu = std::move( menu );
	}

	void Director::Update()
	{
		int input = 0;
		while( true )
		{
			mMenu->ShowMenu();
			input = _getch();

			system( "cls" );

			switch( mMenu->Do( input ) )
			{
			case eTestEndAction::None:
				std::cout << r2::linefeed;
				system( "pause" );

				system( "cls" );
				break;

			case eTestEndAction::Pause:
				system( "cls" );
				break;

			case eTestEndAction::Exit:
				return;
			}
		}
	}
}