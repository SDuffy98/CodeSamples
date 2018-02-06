using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace MovieDatabase.Models
{
    // An enumeration is a set of named integer constants
    public enum Genre { Comedy, Drama, Action, Fiction, Horror, Romance, Sci_Fi, Western, Family, Thriller, War }

    public class Movie
    {
        public List<Genre> Genres { get; set; }   // create a list of genres object 
        public List<string> Actors { set; get; }// initialising the Actor List

        // intialise getters/setters for Movie Properties
        public string Title { get; set; }
        public int Year { get; set; }
        public string Director { get; set; }
        public int Duration { get; set; }
        public double Budget { get; set; }
        public int Rating { get; set; }
        public string PosterUrl { get; set; }


        public Movie()//Default constructor
        {
            Title = "";
            Year = 0;
            Director = "";
            Duration = 0;
            Budget = 0;
            PosterUrl = "";
            Actors = new List<string>();
            Genres = new List<Genre>();
            Rating = 0;
        }

    }

}

