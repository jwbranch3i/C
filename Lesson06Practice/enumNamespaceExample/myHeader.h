#pragma once
#include <string>
using std::string;

namespace anything
{
	enum color { BROWN, BLACK, GREEN };

	string convertToString(color x)
	{
		string result = "";
		switch (x)
		{
		case BROWN:
			result = "Brown";
			break;
		case BLACK:
			result = "Black";
			break;
		case GREEN:
			result = "Green";
			break;
		}
		return result;
	}

	color deriveFavoriteColor(string y)
	{
		color result;
		if (y.compare("Brown") == 0)
			result = BROWN;
		else
			if (y.compare("Black") == 0)
				result = BLACK;
			else
				result = GREEN;
		return result;
	}

} //End of namespace anything
