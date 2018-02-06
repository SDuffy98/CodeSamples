using Microsoft.Win32;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace MovieDatabase.Models
{
    public class Database
    {
        // list of movies in the database
        private List<Movie> db;

        // position of movie in the database 
        private int _index;

        public Database()
        {
            db = new List<Movie>();
            //resets index to -1
            _index = -1;
        }

        //count function
        //using Get to return the database count
        public int Count
        {
            get { return db.Count; }
        }

        //returns the value of index set by each function in which its used
        public int Index
        {
            get { return _index; }
        }

        //adds movies to the database
        //increments index to move through the database and adds the movie m to this position
        public void Add(Movie m)
        {
            //increment the index by 1
            _index++;
            db.Insert(_index, m); //inserts the movie m 
        }

        //used to return the current movie, else, if the database is empty it will return null
        public Movie Get()
        {
            if (db.Count > 0) //if there is a movie within the database
            {
                return db.ElementAt(_index); //returns the movie at the position at which index is located
            }
            else
            {
                return null;
            }
        }

        //this will check if there is a movie to delete, if so it will remove the movie at position index 
        public void Delete()
        {
            if (this._index >= 0 && this._index <= this.Count)
            {
                //remove the movie currently at this position
                db.RemoveAt(_index);
                _index--;
                if (db.Count > 0 && _index == -1)
                {
                    //resets the index to 0
                    _index = 0;
                }
            }
        }
        //loops through to check if there is a movie, if so it will delete the movie at this position
        public void Update(Movie m)
        {
            //makes sure you do not go outside the size of the database
            if (_index <= db.Count)
            {
                //overwrites the current movie with movie m
                db[_index] = m;
            }
        }

        public void Clear()
        {
            //using a clear function to wipe the database
            db.Clear();
            //resets the index to -1
            _index = -1;
        }

        //sets the position of index to the first movie within the database 
        public bool First()
        {
            if (db == null || db.Count < 0)
            {
                return true;
            }
            //return true if the update was successful
            _index = 0;
            return true;
        }

        //sets index to the position of the last movie within the database 
        public bool Last()
        {
            //if the database if empty, ie no last movie there, return false
            if (db == null || db.Count < 0)
            {
                return false;
            }
            //else if there is a movie there return true
            _index = db.Count - 1;
            return true;
        }

        //checks if index is not already at the last movie, if it isnt then will move the index position to next movie
        public bool Next()
        {
            //return false if there is no next movie, ie index is already at the last movie
            if (_index == db.Count - 1)
            {
                return false;
            }
            //else if there is another movie there, return true
            _index++;
            return true;
        }

        //moves index position to previous movie, if its not already the the first movie
        public bool Prev()
        {
            //if index is already at the first movie, return false
            if (_index == 0) //|| db.Count <= 0)
            {
                return false;
            }
            //else if index is able to be decremented, ie there is another movie before it, return true
            _index--;
            return true;
        }

        //reading movies from a text file 
        public void Load(string file) //file is the name of the file to load the movies from
        {
            var dialog = new OpenFileDialog()
            {
                Filter = "json files|*.json",
                Title = "Enter name of movie database file to load"
            };

            //if the user enters a filename and clicks save
            if (dialog.ShowDialog() == true)
            {
                file = dialog.FileName;
                string json = File.ReadAllText(file);
                db = JsonConvert.DeserializeObject<List<Movie>>(json);
            }

            _index = db.Count() - 1;
        }

        public void Save(string file)
        {
            var dialog = new SaveFileDialog()
            {
                Filter = "json files|*.json",
                Title = "Enter name of movie database file to save"
            };

            //if the user enters a filename and clicks save
            if (dialog.ShowDialog() == true)
            {
                file = dialog.FileName;
                string json = JsonConvert.SerializeObject(db);
                File.WriteAllText(file, json);
            }
        }

        public void OrderByYear()
        {
            var MovieYear = db.OrderBy(m => m.Year).ToList();
            db = MovieYear;
        }

        public void OrderByTitle()
        {
            var MovieTit = db.OrderBy(m => m.Title).ToList();
            db = MovieTit;
        }

        public void OrderByDuration()
        {
            var MovieDurat = db.OrderBy(m => m.Duration).ToList();
            db = MovieDurat;
        }
    }
}
