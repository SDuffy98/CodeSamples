using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using MovieDatabase.Models;
using System.Collections.Generic;

namespace MovieDatabaseTestProject
{
    [TestClass]
    public class MovieUnitTest
    {
        // test movie
        private Movie m;

        [TestInitialize]
        public void SetUp()
        {
            m = new Movie()
            {
                // add properties
                Title = "TestMovie",
                Year = 2000,
                Director = "TestDirector",
                Duration = 120,
                Budget = 12.5,
                Rating = 3, 
                Genres = new List<Genre> { Genre.Comedy},
            };
        }

        [TestMethod]
        public void TestCreateMovie()
        {
            // verify the movie was created by checking that each attribute value was set
            // e.g.   Assert.AreEqual(m.Title, "The title of the test movie");

            Assert.AreEqual("TestMovie", m.Title);
            Assert.AreEqual(2000, m.Year);
            Assert.AreEqual("TestDirector", m.Director);
            Assert.AreEqual(120, m.Duration);
            Assert.AreEqual(12.5, m.Budget);
           // Assert.AreEqual(3, m.Rating);
           // Assert.AreEqual(Genre.Comedy, m.Genres);

        }

        [TestMethod]
        public void TestUpdateMovie()
        {
            // make changes to the test movie m            

            // Check if changes were accepted
            m.Title = "TestMovie123";
            m.Year = 2005;
            m.Director = "TestDirector123";
            m.Duration = 120;
            m.Budget = 13;
            //m.Rating = 2;
            //m.Genres = new List<Genre> { Genre.Comedy };

            Assert.AreEqual("TestMovie123", m.Title);
            Assert.AreEqual(2005, m.Year);
            Assert.AreEqual("TestDirector123", m.Director);
            Assert.AreEqual(120, m.Duration);
            Assert.AreEqual(13, m.Budget);
            //Assert.AreEqual(2, m.Rating);
            //Assert.AreEqual(Genre.Comedy, m.Genres);


        }
    }
}
