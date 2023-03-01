#ifndef NODE_H
#define NODE_H
#include <string>
using std::string;

class Node
{
private:
  // define all the attributes of each Node for each ADT
  string month_;
  int year_;
  string artist_;
  string song_title_;
  string record_label_;
  int weeks_at_number_one_;
  Node *next_;

public:
  // Constructors
  Node() : month_(""), year_(-9999), artist_(""), song_title_(""), record_label_(""), weeks_at_number_one_(-9999), next_(NULL) {}
  Node(const std::string &month, int year, const std::string &artist, const std::string &song_title, const std::string &record_label, int weeks_at_number_one)
      : month_(month), year_(year), artist_(artist), song_title_(song_title), record_label_(record_label), weeks_at_number_one_(weeks_at_number_one), next_(NULL) {}
  // mutator functions
  void set_month(const std::string &month) { month_ = month; }                                          // set the month_ attribute to the parameter value of month
  void set_year(int year) { year_ = year; }                                                             // set the year_ attribute to the parameter value of year
  void set_artist(const std::string &artist) { artist_ = artist; }                                      // set the artist_ attribute to the parameter value of artist
  void set_song_title(const std::string &song_title) { song_title_ = song_title; }                      // set the song_title_ attribute to the parameter value of song_title
  void set_record_label(const std::string &record_label) { record_label_ = record_label; }              // set the record_label_ attribute to the parameter value of record_label
  void set_weeks_at_number_one(int weeks_at_number_one) { weeks_at_number_one_ = weeks_at_number_one; } // set the weeks_at_number_one_ attribute to the parameter value of weeks_at_number_one
  void set_next(Node *next) { next_ = next; }                                                           // set the next_ attribute to the Node parameter next

  // accessor functions
  const std::string &get_month() const { return (month_); }
  int get_year() const { return (year_); }
  const std::string &get_artist() const { return (artist_); }
  const std::string &get_song_title() const { return (song_title_); }
  const std::string &get_record_label() const { return (record_label_); }
  int get_weeks_at_number_one() const { return (weeks_at_number_one_); }
  Node *get_next() const { return (next_); }
  std::string get_data() const; // returns the attributes of the Node as a string separated by a comma
};

std::string Node::get_data() const
{
  // Return a string containing all the attribute values of the Node
  std::string str = "";
  str.append(get_month() + ", ");
  str.append(std::to_string(get_year()) + ", ");
  str.append(get_artist() + ", ");
  str.append(get_song_title() + ", ");
  str.append(get_record_label() + ", ");
  str.append(std::to_string(get_weeks_at_number_one()));
  return (str);
}
#endif
