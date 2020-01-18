// For adding header files define your includes here and add the headers in Game folder.
// For example, You may see these files - Attacker.hpp,Defender.hpp and Goalkeeper.hpp
// For checking out the skills you may see skills.h placed in Skills folder.
#pragma once
#include "skills.h"
#include "Attacker.hpp"
#include "Defender.hpp"
#include "GoalKeeper.hpp"

// Change your team color here (BLUE_TEAM/YELLOW_TEAM)face

Simulator::TeamColor teamColor = Simulator::BLUE_TEAM;

// Make usingDebugger is false when playing against an opponent
bool usingDebugger = true;

namespace MyStrategy
{
  // Write your strategy here in game function.
  // You can also make new functions and call them from game function.
  void game(BeliefState *state)
  {
      int a, d, g = 0;

      if (state->homePos[1].x > state->homePos[2].x)
      {
          a = 1;
          d = 2;
      }
      else
      {
          a = 2;
          d = 1;
      }

	  attacker(state,a);
	  
      if (state->ballPos.x < -HALF_FIELD_MAXX/2) attacker(state, d);
      else defender(state, d);

      /*if (state->pr_ball_in_our_dbox) attacker(state, 0);
      else*/ goalkeeper(state,g);
  }
}
