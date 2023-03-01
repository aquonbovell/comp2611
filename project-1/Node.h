#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node
{
private:
  // define all the attributes of each Node in the ADT
  string month;
  int year;
  string artist, songTitle, recordLabel;
  int weeksAtNumberOne;
  Node *next;
public:
  // Constructors
  Node();
  Node(string, int, string, string, string, int);
  // mutator functions
  void setMonth(string value)
  {
   // set the month attribute to the parameter value
    month = value;
  }
  void setYear(int value)
  {
    // set the year attribute to the parameter value
    year = value;
  }
  void setArtist(string value)
  {
    // set the songTitle attribute to the parameter value
    artist = value;
  }
  void setSongTitle(string value)
  {
    // set the songTitle attribute to the parameter value
    songTitle = value;
  }
  void setRecordLabel(string value)
  {
    // set the recordLabel attribute to the parameter value
    recordLabel = value;
  }
  void setWeeksAtNumberOne(int value)
  {
    // set the weeksAtNumberOne attribute to the parameter value
    weeksAtNumberOne = value;
  }
  void setNext(Node *ptr)
  {
    // set the next attribute to the parameter Node pointer ptr
    next = ptr;
  }
  // accessor functions
  string getMonth()
  {
    return month;
  }
  int getYear()
  {
    return year;
  }
  string getArtist()
  {
    return artist;
  }
  string getSongTitle()
  {
    return songTitle;
  }
  string getRecordLabel()
  {
    return recordLabel;
  }
  int getWeeksAtNumberOne()
  {
    return weeksAtNumberOne;
  }
  Node *getNext()
  {
    return next;
  }
  string getData();
};

Node::Node()
{
  // set all the attributes of the Node to their default values
  month = "";
  year = -9999;
  artist = "";
  songTitle = "";
  recordLabel = "";
  weeksAtNumberOne = -9999;
  next = NULL;
}

Node::Node(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  // set all the attributes of the Node to the values from the parameter list
  month = Month;
  year = Year;
  artist = Artist;
  songTitle = SongTitle;
  recordLabel = RecordLabel;
  weeksAtNumberOne = WeeksAtNumberOne;
  next = NULL;
}

string Node::getData()
{
  // return a string containing all the attribute values
  // of the Node
  string str = "";
  str.append(getMonth() + ", ");
  str.append(to_string(getYear()) + ", ");
  str.append(getArtist() + ", ");
  str.append(getSongTitle() + ", ");
  str.append(getRecordLabel() + " ");
  str.append(to_string(getWeeksAtNumberOne()));
  return (str);
}
#endif
