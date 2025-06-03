#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <fstream>
using namespace std;

class Movie {
    public:
        Movie(string movieName, string rating, string showtime);
        vector<string> getTimes();
        string getTimesWithSpaces();
        string getMovieName() { return movieName; }
        string getTruncatedMovieName() { return movieName.substr(0, 44); }
        string getRating() { return rating; }
        void addTime(string time);
    private:
        string movieName;
        string rating;
        vector<string> times;
};

Movie::Movie(string movieName, string rating, string showtime) {
    this->movieName = movieName;
    this->rating = rating;
    times.push_back(showtime);
}

string Movie::getTimesWithSpaces() {
    string timesWithSpaces = times.at(0); //assumes there is at least one time
    for (int i = 1; i < times.size(); i++) {
        timesWithSpaces += " " + times.at(i);
    }
    return timesWithSpaces;
}

void Movie::addTime(string time) {
    times.push_back(time);
}

vector<string> Movie::getTimes() {
    return times;
}

class Showtimes {
public:
    void addShowtime(string movieName, string rating, string showtime);
    vector<string> getShowtimes(string movieName);
    vector<Movie> getMovies();
    void printShowtimes();
private:
    vector<Movie> movies;
};

void Showtimes::printShowtimes() {
    for (int i = 0; i < movies.size(); i++) {
        cout << setw(44) << left << movies[i].getTruncatedMovieName() << " | "; 
        cout << setw(5) << right << movies[i].getRating() << " | ";
        cout << left << movies[i].getTimesWithSpaces() << endl;
    }
}

vector<Movie> Showtimes::getMovies() {
    return movies;
}

vector<string> Showtimes::getShowtimes(string movieName) {
    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].getMovieName() == movieName) {
            return movies[i].getTimes();
        }
    }
    return vector<string>();
}

void Showtimes::addShowtime(string movieName, string rating, string showtime) {
    bool found = false;
    for (int i = 0; i < movies.size(); i++) {
        if (movies[i].getMovieName() == movieName) {
            found = true;
            movies[i].addTime(showtime);
        }
    }
    if (!found) {
        Movie movie = Movie(movieName, rating, showtime);
        movies.push_back(movie);
    }
}

void runtests();

int main() {
    ifstream MovieFS;
    string filename;
    string movieName, rating, time;
    
    runtests();

    // cout << "Enter the name of the file: ";
    // cin >> filename;
    filename = "module9/movies.csv";
    
    MovieFS.open(filename);
    if (!MovieFS.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    Showtimes showtimes = Showtimes();
    getline(MovieFS, time, ',');    // read until comma
    getline(MovieFS, movieName, ',');        // read until comma
    getline(MovieFS, rating); 
    while(MovieFS) {
        showtimes.addShowtime(movieName, rating, time);

        getline(MovieFS, time, ',');    // read until comma
        getline(MovieFS, movieName, ',');        // read until comma
        getline(MovieFS, rating);
    }

    MovieFS.close();
    
    showtimes.printShowtimes();

    return 0;
}


void runtests() {
    Showtimes testShowtimes = Showtimes();
    testShowtimes.addShowtime("The Matrix", "R", "10:30");
    testShowtimes.addShowtime("The Matrix", "R", "1:30");
    testShowtimes.addShowtime("Wicked", "PG-13", "4:30");

    assert(testShowtimes.getShowtimes("Wicked").at(0) == "4:30");
    
    assert(testShowtimes.getMovies().size() == 2);
    assert(testShowtimes.getMovies().at(0).getMovieName() == "The Matrix");
    assert(testShowtimes.getMovies().at(1).getMovieName() == "Wicked");
}



