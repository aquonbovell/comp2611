/************************************************************************************
 * Step 1: Always include the header file wx.h
 ************************************************************************************/

#include <wx/wx.h>

/************************************************************************************
 * Step 2: Name an inherited application class from wxApp and declare it with the
 * function to execute the program
 ************************************************************************************/

class TestApp : public wxApp
{
  virtual bool OnInit();
};

/************************************************************************************
 * Step 3: Declare the inherited main frame class from wxFrame. In this class
 * also will ALL the events handlers be declared
 ************************************************************************************/

class TestFrame : public wxFrame
{
private:
  DECLARE_EVENT_TABLE() // To declare events items
public:
  TestFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
  // Functions for Menu Items
  void OnQuit(wxCommandEvent &event);
};

/************************************************************************************
 * Step 4. Declare the compiler directives
 ************************************************************************************/

DECLARE_APP(TestApp)   // Declare Application class
IMPLEMENT_APP(TestApp) // Create Application class object

enum
{
  // Sub-menu items
  ID_Exit = wxID_HIGHEST + 1,
};

BEGIN_EVENT_TABLE(TestFrame, wxFrame)
EVT_MENU(ID_Exit, TestFrame::OnQuit)
END_EVENT_TABLE()

/************************************************************************************
 * Step 5. Define the Application class function to initialize the application
 ************************************************************************************/

bool TestApp::OnInit()
{
  // Create the main application window
  TestFrame *frame = new TestFrame(wxT("COMP2611 – Data Structures"), wxPoint(50, 50), wxSize(920, 600));
  // Display the window
  frame->Show(TRUE);
  SetTopWindow(frame);
  return TRUE;
};

/************************************************************************************
 * Step 6: Define the Constructor functions for the Frame class
 ************************************************************************************/

TestFrame::TestFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
  // Set the frame icon - optional
  SetIcon(wxIcon(wxT("uwiIcon.xpm")));
  // Create the main-menu item
  wxMenu *menuFile = new wxMenu;
  // Create a Main menu bar
  wxMenuBar *menuBar = new wxMenuBar;
  // Append the main menu item ("File") to it
  menuBar->Append(menuFile, wxT("&File"));
  // Append the sub-menu item (“Exit) to the File Main Menu item
  menuFile->Append(ID_Exit, wxT("E&xit"));
  // ... and now... attach this main menu bar to the frame
  SetMenuBar(menuBar);
  // Create a status bar just for fun
  CreateStatusBar(3);
  // Put something in the first section of the status bar
  SetStatusText(wxT("Ready..."));
  // Put something in the second section of the status bar
  SetStatusText(wxT("Captain Jack Sparrow"), 1);
  // Put something in the third section of the status bar
  SetStatusText(wxT("1234567890"), 2);
};

/************************************************************************************
 * Step 7: Define member functions for the Frame class
 ************************************************************************************/

void TestFrame::OnQuit(wxCommandEvent &event)
{
  wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxICON_INFORMATION , this);
  Close(TRUE); // Close the window
};