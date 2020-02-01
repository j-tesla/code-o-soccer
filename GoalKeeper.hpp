#pragma once
#include "skills.h"
#include "Core/beliefState.h"

/*
	Vec2D can be used to make variables that can store points as (x,y) and provide utility functions.
	Vec2D point1;
	Vec2D point2;
	point1.x = HALF_FIELD_MAXX;
	point1.y = 0;
	similarly for point2 can be specified
	Some utility functions:
	These will appear automatically as you type Vec2D::
	float angle = Vec2D::angle(point1,point2);
	int distance = Vec2D::distSq(point1,point2);
*/

namespace MyStrategy
{
	// Naive Example for GoalKeeper
	void goalkeeper(BeliefState* state, int botID)
	{
		//print("GoalKeeper\n");

		Vec2D dpoint;

		dpoint.x = OUR_GOAL_X + DBOX_HEIGHT;
		if (state->ballVel.x < 0)
		{
			dpoint.y = (int)rayCastY(state, botID);
		}
		else
		{
			dpoint.y = state->ballPos.y;
		}

		if (dpoint.y > OUR_GOAL_MAXY)
			dpoint.y = OUR_GOAL_MAXY;
		if (dpoint.y < OUR_GOAL_MINY)
			dpoint.y = OUR_GOAL_MINY;
		/*if (state->ballPos.x < -HALF_FIELD_MAXX + 300)
		{
			dpoint y 
		}
		*/


		GoToPoint(botID, state, dpoint, PI / 2, false, false);

		if (state->pr_ball_in_our_dbox)
		{
			if (state->ballPos.y < state->homePos[botID].y)
				Spin(botID, -MAX_BOT_OMEGA);
			if (state->ballPos.y > state->homePos[botID].y)
				Spin(botID, MAX_BOT_OMEGA);

		}
		
		

		
	}
}
