// For adding header files define your includes here and add the headers in Game folder.
// For example, You may see these files - Attacker.hpp,Defender.hpp and Goalkeeper.hpp
// For checking out the skills you may see skills.h placed in Skills folder.
#pragma once
#include "skills.h"
#include "Attacker.hpp"
#include "Defender.hpp"
#include "GoalKeeper.hpp"
#include "striker.hpp"

// Change your team color here (BLUE_TEAM/YELLOW_TEAM)face

Simulator::TeamColor teamColor = Simulator::BLUE_TEAM;

// Make usingDebugger is false when playing against an opponent
bool usingDebugger = false;

namespace MyStrategy
{
  // Write your strategy here in game function.
  // You can also make new functions and call them from game function.
  void game(BeliefState *state)
  {
      int a=1, d=2, g = 0;

      if (state->pr_ballOppSide )
      {
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
      }
	  striker(state,a);
	  
      if (state->ballPos.x < HALF_FIELD_MAXX/2 && state->ballPos.x > -HALF_FIELD_MAXX/2) defender(state, d);

      else if(state->ballPos.x <= -HALF_FIELD_MAXX / 2)  striker(state, d);

      else attacker(state, d);

      /*if (state->pr_ball_in_our_dbox) attacker(state, 0);
      else*/ goalkeeper(state,g);
  }
}							
