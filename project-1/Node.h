// ==================================================================================
//
//  Node.h
//  COMP2611 - Project #1 - 417002714
//
//  Created by Aquon Bovell on 02/15/2023
//  © 2023 Aquon Bovell. All rights reserved
//
// ==================================================================================
#ifndef NODE_H
#define NODE_H
#include <string>

using std::string;

// defines the blueprint of the elements of the Linear ADTs
class Node
{
private:
  // all the attributes of each Node for each ADT
  string month_;
  int year_;
  string artist_;
  string song_title_;
  string record_label_;
  int weeks_at_number_one_;
  Node *next_;

public:
  // Constructors

  // default constructor - set attributes values to their default values
  Node() : month_(""), year_(-9999), artist_(""), song_title_(""), record_label_(""), weeks_at_number_one_(-9999), next_(NULL) {}
  // general constructor - set attributes values to those from the parameter list
  Node(const std::string &month, int year, const std::string &artist, const std::string &song_title, const std::string &record_label, int weeks_at_number_one)
      : month_(month), year_(year), artist_(artist), song_title_(song_title), record_label_(record_label), weeks_at_number_one_(weeks_at_number_one), next_(NULL) {}

  // mutator functions

  // set the month_ attribute to the parameter value of month
  void set_month(const std::string &month) { month_ = month; }
  // set the year_ attribute to the parameter value of year
  void set_year(int year) { year_ = year; }
  // set the artist_ attribute to the parameter value of artist
  void set_artist(const std::string &artist) { artist_ = artist; }
  // set the song_title_ attribute to the parameter value of song_title
  void set_song_title(const std::string &song_title) { song_title_ = song_title; }
  // set the record_label_ attribute to the parameter value of record_label
  void set_record_label(const std::string &record_label) { record_label_ = record_label; }
  // set the weeks_at_number_one_ attribute to the parameter value of weeks_at_number_one
  void set_weeks_at_number_one(int weeks_at_number_one) { weeks_at_number_one_ = weeks_at_number_one; }
  // set the next_ attribute to the Node parameter next
  void set_next(Node *next) { next_ = next; }

  // accessor functions

  // returns the value of month_
  const std::string &get_month() const { return (month_); }
  // returns the value of year_
  int get_year() const { return (year_); }
  // returns the value of artist_
  const std::string &get_artist() const { return (artist_); }
  // returns the value of song_title_
  const std::string &get_song_title() const { return (song_title_); }
  // returns the value of record_label_
  const std::string &get_record_label() const { return (record_label_); }
  // returns the value of weeks_at_number_one_
  int get_weeks_at_number_one() const { return (weeks_at_number_one_); }
  // returns the value of next_
  Node *get_next() const { return (next_); }
  // returns all the attributes of the Node as a string separated by a comma
  std::string get_data() const;
};

// Return a string containing all the attribute values of the Node
std::string Node::get_data() const
{
  // a container to hold the attributes of the Node
  std::string str = "";
  // add the attributes to the container
  str.append(get_month() + ", ");
  str.append(std::to_string(get_year()) + ", ");
  str.append(get_artist() + ", ");
  str.append(get_song_title() + ", ");
  str.append(get_record_label() + ", ");
  str.append(std::to_string(get_weeks_at_number_one()));
  return (str);
}
#endif
