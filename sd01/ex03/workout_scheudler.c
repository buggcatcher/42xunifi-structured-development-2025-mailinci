#include "workout_scheduler.h"

struct WorkoutPlan	*create_workout_schedule(char *username)
{
	struct UserData *userdata;
	struct WorkoutPlan *baseplan;
	struct WorkoutPlan *refineplan;
	int	duration;
	int	day;

	userdata = get_user_data(username);
	baseplan = build_base_plan(userdata);
	if (baseplan == NULL)
	{
		free_user_data(userdata);
		return (NULL);
	}
	refineplan = refine_plan(baseplan, userdata);
	if (refineplan == NULL)
	{
		free_user_data(userdata);
		return (NULL);
	}
	duration = determine_duration(refineplan);

	day = 0;
	while (day < duration)
	{
		assign_daily_exercises(refineplan, day);
		assign_daily_tips(refineplan, day);
		day++;
	}
	free_user_data(userdata);
	free_workout_plan(efineplan);
}

// // Returns a new UserData (mocked). Returns NULL on failure.
// struct UserData *get_user_data(char *username);
// // Build a base WorkoutPlan from raw user data. Returns NULL on failure.
// struct WorkoutPlan *build_base_plan(struct UserData *data);
// // Optionally refine an existing plan. Returns the same pointer (or a new one) or NULL on failure.
// struct WorkoutPlan *refine_plan(struct WorkoutPlan *plan, struct UserData *data);
// // Determine how many days the workout schedule should span. Returns positive int, or <=0 on failure.
// int determine_duration(struct WorkoutPlan *plan);
// // Assign daily exercises for the next day into the plan.
// void assign_daily_exercises(struct WorkoutPlan *plan, int day);
// // Assign daily tips for the next day into the plan.
// void assign_daily_tips(struct WorkoutPlan *plan, int day);
// // Free functions for cleanup.
// void free_user_data(struct UserData *data);
// void free_workout_plan(struct WorkoutPlan *plan);