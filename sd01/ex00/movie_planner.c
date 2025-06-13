#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
	struct Preferences *prefs = get_user_preferences();
	if (prefs == NULL)
		return (NULL);
	struct MovieList *movies = find_movies(prefs);
	if (movies == NULL)
	{
		free(prefs);
		return (NULL);
	}
	struct Plan *plan = build_plan(movies);
	if (plan == NULL)
	{
		free(movies);
		free(prefs);
		return (NULL);
	}
	return (plan)
}

// // Returns user preferences. Returns NULL on failure.
// struct Preferences *get_user_preferences(void);
// // Returns a list of movies matching the given preferences. Returns NULL on failure.
// struct MovieList *find_movies(struct Preferences *prefs);
// // Returns a movie night plan from the given list. Returns NULL on failure.
// struct Plan *build_plan(struct MovieList *list);