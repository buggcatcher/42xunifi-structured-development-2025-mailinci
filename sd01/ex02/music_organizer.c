#include "music_organizer.h"

struct MusicLibrary	*organize_music_library(const char *directory_path)
{
	struct MusicLibrary	*lib;
	struct MusicFile	*song;
	const char			**list;
	int					i;

	lib = create_music_library();
	if (lib == NULL)
		return (NULL);
	list = scan_directory(directory_path);
	if (list == NULL)
		return (lib);
	i = 0;
	while (list[i] != NULL)
	{
		song = process_music_file(directory_path, list[i]);
		if (song != NULL)
			update_music_library(lib, song);
		i++;
	}
	return (lib);
}
// // Creates and returns a new music library. Returns NULL on fail
// struct MusicLibrary	*create_music_library();
// // Scans a directory for music files. Returns a NULL terminated array of filenames.
// const char	**scan_directory(const char *directory_path);
// // Processes a single music file. Returns a data structure representing the processed file.
// struct MusicFile	*process_music_file(const char *directory_path, const char *filename);
// // Updates the music library with the processed music file information.
// void	update_music_library(struct MusicLibrary *library, struct MusicFile *song);