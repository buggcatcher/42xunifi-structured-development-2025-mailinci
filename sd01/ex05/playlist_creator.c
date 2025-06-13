#include "playlist_creator.h"

struct Playlist	*create_playlist(void)
{
	struct MoodSettings		*mood;
	struct FilterSettings	*filters;
	struct SongData		*song;
	struct Playlist		*playlist;
	int					variations;
	int					i;
	int					is_popular;

	mood = analyze_user_mood();
	if (mood == NULL)
		return (NULL);
	filters = default_filters();
	if (filters == NULL)
	{
		free_mood_settings(mood);
		return (NULL);
	}
	variations = get_mood_variations(mood);
	i = 0;
	while (i < variations)
	{
		filters = refine_filters(filters);
		if (filters == NULL)
		{
			free_mood_settings(mood);
			return (NULL);
		}
		i++;
	}
	is_popular = filters_require_popular_song(filters);
	if (is_popular != 0)
		song = fetch_popular_song();
	else
		song = fetch_niche_song();
	if (song == NULL)
	{
		free_mood_settings(mood);
		free_filter_settings(filters);
		return (NULL);
	}
	playlist = combine_with_mood_playlist(song, mood);
	if (playlist == NULL)
	{
		free_mood_settings(mood);
		free_filter_settings(filters);
		free_song_data(song);
		return (NULL);
	}
	free_mood_settings(mood);
	free_filter_settings(filters);
	free_song_data(song);
	return (playlist);
}
// // Analyze user mood. Returns a new MoodSettings or NULL on failure.
// struct MoodSettings *analyze_user_mood(void);
// // Return default filter settings. Returns a new FilterSettings or NULL on failure.
// struct FilterSettings *default_filters(void);
// // Return the number of mood variations for refinement.
// int get_mood_variations(struct MoodSettings *mood);
// // Refine the current filter settings. Returns the same or a new FilterSettings, or NULL on failure.
// struct FilterSettings *refine_filters(struct FilterSettings *current);
// // Check if filters require a popular or niche song. Returns nonzero if popular.
// int filters_require_popular_song(struct FilterSettings *filters);
// // Fetch a popular song. Returns a new SongData or NULL on failure.
// struct SongData *fetch_popular_song(void);
// // Fetch a niche song. Returns a new SongData or NULL on failure.
// struct SongData *fetch_niche_song(void);
// // Combine a song into a playlist given mood settings. Returns a new Playlist or NULL on failure.
// struct Playlist *combine_with_mood_playlist(struct SongData *song, struct MoodSettings *mood);
// // Free functions for cleanup
// void free_mood_settings(struct MoodSettings *mood);
// void free_filter_settings(struct FilterSettings *filters);
// void free_song_data(struct SongData *song);
// void free_playlist(struct Playlist *playlist);

