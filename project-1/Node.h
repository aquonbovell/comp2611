#ifndef NODE_H
#define NODE_H
#include <string>

using std::string;
using std::to_string;

class Node
{
private:
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
    month = value;
  }
  void setYear(int value)
  {
    year = value;
  }
  void setSongTitle(string value)
  {
    songTitle = value;
  }
  void setRecordLabel(string value)
  {
    recordLabel = value;
  }
  void setWeeksAtNumberOne(int value)
  {
    weeksAtNumberOne = value;
  }
  void setNext(Node *ptr)
  {
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
  month = "";
  year = -9999;
  artist = "";
  songTitle = "";
  recordLabel = "";
  weeksAtNumberOne = 0;
  next = NULL;
};

Node::Node(string Month, int Year, string Artist, string SongTitle, string RecordLabel, int WeeksAtNumberOne)
{
  month = Month;
  year = Year;
  artist = Artist;
  songTitle = SongTitle;
  recordLabel = RecordLabel;
  weeksAtNumberOne = WeeksAtNumberOne;
  next = NULL;
};

string Node::getData()
{
  string str = "";
  str.append(month + ", ");
  str.append(to_string(year) + ", ");
  str.append(artist + ", ");
  str.append(songTitle + ", ");
  str.append(recordLabel + " ");
  str.append(to_string(weeksAtNumberOne));
  return (str);
};
#endif
