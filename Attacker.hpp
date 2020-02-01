#pragma once
#include "skills.h"

namespace MyStrategy
{
  // Naive example for attacker
	void attacker(BeliefState* state, int botID)
	{
		print("Attacker\n");
		Vec2D fpoint(HALF_FIELD_MAXX, 0);
		Vec2D ballPoint(state->ballPos.x, state->ballPos.y);

		int otherbot = 1;
		if (botID == 1)
			int otherbot = 2;

		bool bot_in_opp_dbox = false;


		if (state->homePos[otherbot].x > (HALF_FIELD_MAXX - DBOX_WIDTH) &&
			state->homePos[otherbot].y < OUR_GOAL_MAXY &&
			state->homePos[otherbot].y > OUR_GOAL_MINY)
			bot_in_opp_dbox = true;

		if (!state->pr_ball_in_opp_dbox && !bot_in_opp_dbox && !(state->pr_ourBall && state->ourBotNearestToBall != otherbot))
		{
			// Go to ball if ball is far
			// Take ball to the goal
			
			Vec2D naya;
	
			naya.x = HALF_FIELD_MAXX - 2 * GOAL_DEPTH;
			naya.y = -ballPoint.y;
			
			



			if (state->ballPos.x > HALF_FIELD_MAXX - 500)
				GoToPoint(botID, state, ballPoint, PI / 2, true, true);
			else
			{
				if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 3 * BOT_BALL_THRESH)
					GoToPoint(botID, state, fpoint, PI / 2, true, true);
				else
					GoToPoint(botID, state, naya, 0, false, true);
			}
		}
	}
  
}
