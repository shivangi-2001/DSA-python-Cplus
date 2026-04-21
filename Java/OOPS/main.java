public class Artist{
    private String name;

    public String getName(){
        return name;
    }
}

public class Song{
    private String title;
    main artist;
    private int duration;

    public String getTitle(){
        return title;
    }

    public main getArtist(){
        return artist;
    }

    public int getDuration(){
        return duration;
    }
}
public class main{
    public static void main(String[] args) {
        // Create artists and songs (independent of any playlist)
        Artist coldplay = new Artist("Coldplay");
        Artist adele = new Artist("Adele");
    
        Song yellow = new Song("Yellow", coldplay, 269);
        Song clocks = new Song("Clocks", coldplay, 307);
        Song hello = new Song("Hello", adele, 295);
        Song someone = new Song("Someone Like You", adele, 285);
    
        // Add all songs to the master library
        Library library = new Library();
        library.addSong(yellow);
        library.addSong(clocks);
        library.addSong(hello);
        library.addSong(someone);
    
        // User creates playlists and adds songs
        User alice = new User("Alice");
        Playlist workout = alice.createPlaylist("Workout Mix");
        Playlist chill = alice.createPlaylist("Chill Vibes");
    
        // Same songs shared across playlists
        workout.addSong(yellow);
        workout.addSong(clocks);
        workout.addSong(hello);
    
        chill.addSong(hello);
        chill.addSong(someone);
    
        System.out.println("Library has " + library.getSongCount() + " songs");
        System.out.println();
    
        System.out.println(workout.getName() + " (" + workout.getSongCount() + " songs, "
            + workout.getTotalDuration() + "s):");
        for (Song s : workout.getSongs()) {
            System.out.println("  - " + s);
        }
        System.out.println();
    
        System.out.println(chill.getName() + " (" + chill.getSongCount() + " songs, "
            + chill.getTotalDuration() + "s):");
        for (Song s : chill.getSongs()) {
            System.out.println("  - " + s);
        }
        System.out.println();
    
        // Delete a playlist - songs survive
        alice.deletePlaylist(workout);
        System.out.println("After deleting '" + workout.getName() + "':");
        System.out.println("  Library still has " + library.getSongCount() + " songs");
        System.out.println("  '" + chill.getName() + "' still has " + chill.getSongCount() + " songs");
        System.out.println("  'Yellow' still exists: " + yellow.getTitle());
    }
}
