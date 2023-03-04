// ==================================================================================
//
//  Project-01.cpp
//  COMP2611 - Project #1 - 417002714
//
//  Created by Aquon Bovell on 02/15/2023
//  © 2023 Aquon Bovell. All rights reserved
//
// ==================================================================================
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// the ADTs header files
#include "Queue.h"
#include "Deque.h"
#include "PQueue.h"
#include "Stack.h"

// Global pointers for all the ADT containers
Queue *q = new Queue();
Deque *d = new Deque();
PriorityQueue *pq = new PriorityQueue();
Stack *s = new Stack();

// Name an inherited application class from wxApp and declare it
// with the function to execute the program
class ProjectApp : public wxApp
{
  virtual bool OnInit();
};

// Declare the inherited main frame class from wxFrame. In this class
// also will ALL the events handlers be declared
class ProjectFrame : public wxFrame
{
private:
  DECLARE_EVENT_TABLE() // To declare events items
public:
  ProjectFrame(const wxString &title, const wxPoint &pos,
               const wxSize &size);
  // Functions for File Menu Items
  void OnOpenFile(wxCommandEvent &event);
  void OnDisplay(wxCommandEvent &event);
  void OnSave(wxCommandEvent &event);
  void OnSaveAs(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event); // handle for Quit function

  // Functions for Queue Menu Items
  void OnCreateQueue(wxCommandEvent &event);
  void OnDisplayAllQueue(wxCommandEvent &event);
  void OnShowHeadQueue(wxCommandEvent &event);
  void OnShowTailQueue(wxCommandEvent &event);
  void OnDequeueQueue(wxCommandEvent &event);

  // Functions for Deque Menu Items
  void OnCreateDeque(wxCommandEvent &event);
  void OnDisplayAllDeque(wxCommandEvent &event);
  void OnShowHeadDeque(wxCommandEvent &event);
  void OnShowTailDeque(wxCommandEvent &event);
  void OnDequeueHeadDeque(wxCommandEvent &event);
  void OnDequeueTailDeque(wxCommandEvent &event);

  // Functions for Priority Queue Menu Items
  void OnCreatePriorityQueue(wxCommandEvent &event);
  void OnDisplayAllPriorityQueue(wxCommandEvent &event);
  void OnShowHeadPriorityQueue(wxCommandEvent &event);
  void OnShowTailPriorityQueue(wxCommandEvent &event);
  void OnDequeuePriorityQueue(wxCommandEvent &event);

  // Functions for Stack Menu Items
  void OnCreateStack(wxCommandEvent &event);
  void OnDisplayAllStack(wxCommandEvent &event);
  void OnShowHeadStack(wxCommandEvent &event);
  void OnShowTailStack(wxCommandEvent &event);
  void OnPopStack(wxCommandEvent &event);

  // Functions for Help Menu Item
  void OnAbout(wxCommandEvent &event);

  // Public attributes
  wxTextCtrl *MainEditBox;
  wxTextCtrl *filenameTextBox;
  wxString CurrentDocPath; // The Path to the file we have open
};

// Declare the compiler directives
DECLARE_APP(ProjectApp)   // Declare Application class
IMPLEMENT_APP(ProjectApp) // Create Application class object

enum
{
  // File menu items
  ID_OpenFile = wxID_HIGHEST + 1, // File menu item
  ID_Display,
  ID_Save,
  ID_SaveAs,
  ID_Exit,
  // Queue menu items
  ID_CreateQueue,
  ID_DisplayAllQueue,
  ID_ShowHeadQueue,
  ID_ShowTailQueue,
  ID_DequeueQueue,
  // Deque menu items
  ID_CreateDeque,
  ID_DisplayAllDeque,
  ID_ShowHeadDeque,
  ID_ShowTailDeque,
  ID_DequeueHeadDeque,
  ID_DequeueTailDeque,
  // Priority Queue menu items
  ID_CreatePriorityQueue,
  ID_DisplayAllPriorityQueue,
  ID_ShowHeadPriorityQueue,
  ID_ShowTailPriorityQueue,
  ID_DequeuePriorityQueue,
  // Stack menu items
  ID_CreateStack,
  ID_DisplayAllStack,
  ID_ShowHeadStack,
  ID_ShowTailStack,
  ID_PopStack,
};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile) // File Menu Open
EVT_MENU(ID_Display, ProjectFrame::OnDisplay)   // File Menu Display
EVT_MENU(ID_Save, ProjectFrame::OnSave)         // File Menu Save
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)     // File Menu Save As
EVT_MENU(ID_Exit, ProjectFrame::OnExit)         // File Menu Exit
// Events for the Queue
EVT_MENU(ID_CreateQueue, ProjectFrame::OnCreateQueue)         // Queue Menu Create Queue
EVT_MENU(ID_DisplayAllQueue, ProjectFrame::OnDisplayAllQueue) // Queue Menu Display All
EVT_MENU(ID_ShowHeadQueue, ProjectFrame::OnShowHeadQueue)     // Queue Menu Show Head
EVT_MENU(ID_ShowTailQueue, ProjectFrame::OnShowTailQueue)     // Queue Menu Show Tail
EVT_MENU(ID_DequeueQueue, ProjectFrame::OnDequeueQueue)       // Queue Menu Dequeue
// Events for the Deque
EVT_MENU(ID_CreateDeque, ProjectFrame::OnCreateDeque)           // Deque Menu Create Deque
EVT_MENU(ID_DisplayAllDeque, ProjectFrame::OnDisplayAllDeque)   // Deque Menu Display All
EVT_MENU(ID_ShowHeadDeque, ProjectFrame::OnShowHeadDeque)       // Deque Menu Show Head
EVT_MENU(ID_ShowTailDeque, ProjectFrame::OnShowTailDeque)       // Deque Menu Show Tail
EVT_MENU(ID_DequeueHeadDeque, ProjectFrame::OnDequeueHeadDeque) // Deque Menu Dequeue Head
EVT_MENU(ID_DequeueTailDeque, ProjectFrame::OnDequeueTailDeque) // Deque Menu Dequeue Tail
// Events for the Priority Queue
EVT_MENU(ID_CreatePriorityQueue, ProjectFrame::OnCreatePriorityQueue)         // Priority Queue Menu Create Priority Queue
EVT_MENU(ID_DisplayAllPriorityQueue, ProjectFrame::OnDisplayAllPriorityQueue) // Priority Queue Menu Display All
EVT_MENU(ID_ShowHeadPriorityQueue, ProjectFrame::OnShowHeadPriorityQueue)     // Priority Queue Menu Show Head
EVT_MENU(ID_ShowTailPriorityQueue, ProjectFrame::OnShowTailPriorityQueue)     // Priority Queue Menu Show Tail
EVT_MENU(ID_DequeuePriorityQueue, ProjectFrame::OnDequeuePriorityQueue)       // Priority Queue Menu Dequeue
// Events for the Stack
EVT_MENU(ID_CreateStack, ProjectFrame::OnCreateStack)         // Stack Menu Create Stack
EVT_MENU(ID_DisplayAllStack, ProjectFrame::OnDisplayAllStack) // Stack Menu Display
EVT_MENU(ID_ShowHeadStack, ProjectFrame::OnShowHeadStack)     // Stack Menu Show Head
EVT_MENU(ID_ShowTailStack, ProjectFrame::OnShowTailStack)     // Stack Menu Show Tail
EVT_MENU(ID_PopStack, ProjectFrame::OnPopStack)               // Stack Menu Pop
// Events for the "Help" menu items
EVT_MENU(wxID_ABOUT, ProjectFrame::OnAbout) // Help Menu About

END_EVENT_TABLE()

// Define the Application class function to initialize the application
bool ProjectApp::OnInit()
{
  // Create the main application window
  ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures Project #1"),
                                         wxPoint(50, 50),
                                         wxSize(840, 600));
  // Display the window
  frame->Show(TRUE);
  SetTopWindow(frame);
  return TRUE;
};

// Define the Constructor functions for the Frame class
ProjectFrame::ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
  // Create the main-menu items
  wxMenu *menuFile = new wxMenu;
  wxMenu *menuQueue = new wxMenu;
  wxMenu *menuDeque = new wxMenu;
  wxMenu *menuPQueue = new wxMenu;
  wxMenu *menuStack = new wxMenu;
  wxMenu *menuHelp = new wxMenu;

  // Create a Main menu bar
  wxMenuBar *menuBar = new wxMenuBar;

  // Append the main menu items to the Menu Bar
  menuBar->Append(menuFile, wxT("File"));
  menuBar->Append(menuQueue, wxT("Queue"));
  menuBar->Append(menuDeque, wxT("Deque"));
  menuBar->Append(menuPQueue, wxT("Priority Queue"));
  menuBar->Append(menuStack, wxT("Stack"));
  menuBar->Append(menuHelp, wxT("Help"));

  // Append the sub-menu items to the File Main Menu item
  menuFile->Append(ID_OpenFile, wxT("Open File..."), wxT("Open an Existing file"));
  menuFile->Append(ID_Display, wxT("Display File..."), wxT("Display contents of opened file"));
  menuFile->Append(ID_Save, wxT("Save"), wxT("Save opened file"));
  menuFile->Append(ID_SaveAs, wxT("Save As..."), wxT("Save display as a new file"));
  menuFile->Append(ID_Exit, wxT("Exit"), wxT("Close and EXIT Program"));

  // Append the sub-menu items to the Queue Main Menu item
  menuQueue->Append(ID_CreateQueue, wxT("Create Queue"), wxT("Create a Queue"));
  menuQueue->Append(ID_DisplayAllQueue, wxT("Display All"), wxT("Display contents of the Queue"));
  menuQueue->Append(ID_ShowHeadQueue, wxT("Show Head"), wxT("Show the first item of the Queue"));
  menuQueue->Append(ID_ShowTailQueue, wxT("Show Tail"), wxT("Show the last item of the Queue"));
  menuQueue->Append(ID_DequeueQueue, wxT("Dequeue"), wxT("Dequeue the first item from the Queue"));

  // Append the sub-menu items to the Deque Main Menu item
  menuDeque->Append(ID_CreateDeque, wxT("Create Deque"), wxT("Create a Deque"));
  menuDeque->Append(ID_DisplayAllDeque, wxT("Display All"), wxT("Display contents of the Deque"));
  menuDeque->Append(ID_ShowHeadDeque, wxT("Show Head"), wxT("Show the first item of the Deque"));
  menuDeque->Append(ID_ShowTailDeque, wxT("Show Tail"), wxT("Show the last item of the Deque"));
  menuDeque->Append(ID_DequeueHeadDeque, wxT("Dequeue Head"), wxT("Dequeue the first item from the Deque"));
  menuDeque->Append(ID_DequeueTailDeque, wxT("Dequeue Tail"), wxT("Dequeue the last item from the Deque"));

  // Append the sub-menu items to the Queue Main Menu item
  menuPQueue->Append(ID_CreatePriorityQueue, wxT("Create Priority Queue"), wxT("Create a Priority Queue"));
  menuPQueue->Append(ID_DisplayAllPriorityQueue, wxT("Display All"), wxT("Display contents of the Priority Queue"));
  menuPQueue->Append(ID_ShowHeadPriorityQueue, wxT("Show Head"), wxT("Show the first item of the Priority Queue"));
  menuPQueue->Append(ID_ShowTailPriorityQueue, wxT("Show Tail"), wxT("Show the last item of the Priority Queue"));
  menuPQueue->Append(ID_DequeuePriorityQueue, wxT("Dequeue"), wxT("Dequeue the first item from the Priority Queue"));

  // Append the sub-menu items to the Queue Main Menu item
  menuStack->Append(ID_CreateStack, wxT("Create Stack"), wxT("Create a Stack"));
  menuStack->Append(ID_DisplayAllStack, wxT("Display All"), wxT("Display contents of the Stack"));
  menuStack->Append(ID_ShowHeadStack, wxT("Show Head"), wxT("Show the first item of the Stack"));
  menuStack->Append(ID_ShowTailStack, wxT("Show Tail"), wxT("Show the last item of the Stack"));
  menuStack->Append(ID_PopStack, wxT("Pop"), wxT("Pop the first item from the Stack"));

  // Append the sub-menu items to the Help Main Menu item
  menuHelp->Append(wxID_ABOUT, wxT("About"), wxT("Shows the details of the program"));
  // ... and now... attach this main menu bar to the frame
  SetMenuBar(menuBar);
  // Create a status bar just for fun
  CreateStatusBar(3);
  // Put something in the first section of the status bar
  SetStatusText(wxT("Ready..."));
  // Put something in the Second section of the status bar
  SetStatusText(wxT("    Aquon Bovell"), 1);
  // Put something in the Third section of the status bar
  SetStatusText(wxT("    417002714"), 2);
  // Set up the panel for data display
  //=================================================================================
  //======================= DO NOT CHANGE THE CODE IN THIS SECTION ==================
  //=================================================================================
  wxPanel *panel = new wxPanel(this, -1);
  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);    // Vertical sizer for main window
  wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for main window
  // Add two textboxes to the panel for data display
  wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for filename window
  wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for display window
  wxStaticText *fileLabel = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
  wxStaticText *displayLabel = new wxStaticText(panel, wxID_ANY, wxT("Display"));
  // Initialize the filename textbox window
  filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));
  // Initialize the display window
  MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."),
                               wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);
  // Position the labels and textboxes in the panel
  hbox1->Add(fileLabel, 0, wxRIGHT, 8);
  hbox1->Add(filenameTextBox, 1);
  vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
  vbox->Add(-1, 10);
  hbox2->Add(displayLabel, 0);
  vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
  vbox->Add(-1, 10);
  hbox3->Add(MainEditBox, 1, wxEXPAND);
  vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);
  vbox->Add(-1, 25);
  panel->SetSizer(vbox);
  Centre();
};

// Define member functions for the Frame class
//===================================================================================
//=========== Definitions for the File Functions ====================================
//===================================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent &event)
{
  // Creates a "open file" dialog with 3 file types
  wxFileDialog *OpenDialog = new wxFileDialog(this,
                                              (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
                                              (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
                                              wxFD_OPEN, wxDefaultPosition);
  if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
  {
    // Sets our current document to the file the user selected
    CurrentDocPath = OpenDialog->GetPath();
    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);
    MainEditBox->LoadFile(CurrentDocPath); // Opens that file in the MainEditBox
  }
};

void ProjectFrame::OnSave(wxCommandEvent &event)
{
  // Save to the already-set path for the document
  MainEditBox->SaveFile(CurrentDocPath);
};

void ProjectFrame::OnSaveAs(wxCommandEvent &event)
{
  wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")),
                                              wxEmptyString, wxEmptyString,
                                              (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt")),
                                              wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
  // Creates a Save Dialog with 4 file types
  if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
  {
    wxString SavePath = SaveDialog->GetPath();
    // set the path of our current document to the file the user chose to save under
    MainEditBox->SaveFile(SavePath); // Save the file to the selected path
  }
};

void ProjectFrame::OnDisplay(wxCommandEvent &event)
{
  MainEditBox->Clear();
  // if  CurrentDocPath is not valid show a error message dialog box
  if (!CurrentDocPath)
    wxMessageBox(wxT("No file can be displayed"), wxT("About"), wxOK | wxICON_INFORMATION, this);
  // if CurrentDocPath is valid add the file text to the MainEdit box
  else
    MainEditBox->LoadFile(CurrentDocPath);
};

void ProjectFrame::OnExit(wxCommandEvent &event)
{
  // Present a GoodBye message and close the program
  wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
  Close(TRUE); // Close the window
};

//===================================================================================
//=========== Definitions for the Queue Functions ===================================
//===================================================================================
void ProjectFrame::OnCreateQueue(wxCommandEvent &event)
{
  // Creates a "open file" dialog with 3 file types
  wxFileDialog *OpenDialog = new wxFileDialog(this,
                                              (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
                                              (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
                                              wxFD_OPEN, wxDefaultPosition);
  if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
  {
    // Sets our current document to the file the user selected
    CurrentDocPath = OpenDialog->GetPath();
    // Add the data to the Queue from the file opened and grab the resulting message
    string value = q->createQueue(string(CurrentDocPath));
    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    MainEditBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);
    // Display the string in the MainEditBox
    wxString wxValue(value.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxValue); // Loads the contents of the Queue into the MainEditBox
  }
};

void ProjectFrame::OnShowHeadQueue(wxCommandEvent &event)
{
  // grabs the data from the showHead operation from the Queue
  string value = q->showHead();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxValue);
};

void ProjectFrame::OnShowTailQueue(wxCommandEvent &event)
{
  // grabs the data from the showTail operation from the Queue
  string value = q->showTail();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxValue);
};

void ProjectFrame::OnDisplayAllQueue(wxCommandEvent &event)
{
  // grabs the data from the displayAll operation from the Queue
  string records = q->displayAll();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

void ProjectFrame::OnDequeueQueue(wxCommandEvent &)
{
  // grabs the data from the dequeue operation from the Queue
  string records = q->dequeue();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

//===================================================================================
//=========== Definitions for the Deque Functions ===================================
//===================================================================================
void ProjectFrame::OnCreateDeque(wxCommandEvent &event)
{
  // Creates a "open file" dialog with 3 file types
  wxFileDialog *OpenDialog = new wxFileDialog(this,
                                              (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
                                              (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
                                              wxFD_OPEN, wxDefaultPosition);
  if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
  {
    // Sets our current document to the file the user selected
    CurrentDocPath = OpenDialog->GetPath();
    // Add the data to the Deque from the file opened and grab the resulting message
    string value = d->createDeque(string(CurrentDocPath));
    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    MainEditBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);
    // Display the string in the MainEditBox
    wxString wxValue(value.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxValue);
  }
};

void ProjectFrame::OnShowHeadDeque(wxCommandEvent &event)
{
  // grabs the data from the showHead operation from the Deque
  string value = d->showHead();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxValue);
};

void ProjectFrame::OnShowTailDeque(wxCommandEvent &event)
{
  // grabs the data from the showTail operation from the Deque
  string value = d->showTail();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxValue);
};

void ProjectFrame::OnDisplayAllDeque(wxCommandEvent &event)
{
  // grabs the data from the displayAll operation from the Deque
  string records = d->displayAll();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

void ProjectFrame::OnDequeueHeadDeque(wxCommandEvent &)
{
  // grabs the data from the dequeueHead operation from the Deque
  string records = d->dequeueHead();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

void ProjectFrame::OnDequeueTailDeque(wxCommandEvent &)
{
  // grabs the data from the dequeueTail operation from the Deque
  string records = d->dequeueTail();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

//===================================================================================
//=========== Definitions for the Priority Queue Functions ==========================
//===================================================================================
void ProjectFrame::OnCreatePriorityQueue(wxCommandEvent &event)
{
  // Creates a "open file" dialog with 3 file types
  wxFileDialog *OpenDialog = new wxFileDialog(this,
                                              (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
                                              (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
                                              wxFD_OPEN, wxDefaultPosition);
  if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
  {
    // Sets our current document to the file the user selected
    CurrentDocPath = OpenDialog->GetPath();
    // Add the data to the Priority Queue from the file opened and grab the resulting message
    string value = pq->createPriorityQueue(string(CurrentDocPath));
    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    MainEditBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);
    // Display the string in the MainEditBox
    wxString wxValue(value.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxValue);
  }
};

void ProjectFrame::OnShowHeadPriorityQueue(wxCommandEvent &event)
{
  // grabs the data from the showHead operation from the Priority Queue
  string value = pq->showHead();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxValue);
};

void ProjectFrame::OnShowTailPriorityQueue(wxCommandEvent &event)
{
  // grabs the data from the showTail operation from the Priority Queue
  string value = pq->showTail();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxValue);
};

void ProjectFrame::OnDisplayAllPriorityQueue(wxCommandEvent &event)
{
  // grabs the data from the displayAll operation from the Priority Queue
  string records = pq->displayAll();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

void ProjectFrame::OnDequeuePriorityQueue(wxCommandEvent &)
{
  // grabs the data from the dequeue operation from the Priority Queue
  string records = pq->dequeue();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

//===================================================================================
//=================== Definitions for the Stack Functions ===========================
//===================================================================================
void ProjectFrame::OnCreateStack(wxCommandEvent &event)
{
  // Creates a "open file" dialog with 3 file types
  wxFileDialog *OpenDialog = new wxFileDialog(this,
                                              (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
                                              (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
                                              wxFD_OPEN, wxDefaultPosition);
  if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
  {
    // Sets our current document to the file the user selected
    CurrentDocPath = OpenDialog->GetPath();
    // Add the data to the Stack from the file opened and grab the resulting message
    string value = s->createStack(string(CurrentDocPath));
    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    MainEditBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);
    // Display the string in the MainEditBox
    wxString wxValue(value.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxValue);
  }
};

void ProjectFrame::OnShowHeadStack(wxCommandEvent &event)
{
  // grabs the data from the showHead operation from the Stack
  string value = s->showHead();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxValue);
};

void ProjectFrame::OnShowTailStack(wxCommandEvent &event)
{
  // grabs the data from the showTail operation from the Stack
  string value = s->showTail();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxValue);
};

void ProjectFrame::OnDisplayAllStack(wxCommandEvent &event)
{
  // grabs the data from the displayAll operation from the Stack
  string records = s->displayAll();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

void ProjectFrame::OnPopStack(wxCommandEvent &)
{
  // grabs the data from the pop operation from the Stack
  string records = s->pop();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);
  MainEditBox->AppendText(wxRecords);
};

//===================================================================================
//=================== Definitions for the Help Functions ============================
//===================================================================================
void ProjectFrame::OnAbout(wxCommandEvent &)
{
  // define the information for the user to read and to know what the program
  // consists of, how to use the program and libraries used
  string abouttext = "The author, Aquon Bovell, is a computer science and mathematics student with skills in Java, Python, C++, HTML, CSS, and JavaScript. They have completed programming projects including a website for a local business and a mobile app for a hypothetical non-profit organization. They are the lead programmer for a program designed to help users understand and appreciate different types of Linear Abstract Data Types (ADTs). The program allows users to load, display, and remove records from any Linear ADT and supports any file format for compatibility. The program uses C++, wxWidgets, and runs on Linux OpenSUSE 15.4. The program has features to add and remove data, view data, and save and load data, with a graphical user interface and a menu bar. The architecture of OpenSUSE 15.4 includes the latest Linux kernel, Xfce 4.14 desktop environment, and support for containerization and virtualization technologies.";
  // Convert the information to a wxString object to be displayed in the message box.
  wxString wxText(abouttext.c_str(), wxConvUTF8);
  // Display the information in a message box with the title "About".
  // The message box has an OK button and an information icon.
  // The message box is displayed within the current window.
  wxMessageBox(wxText, wxT("About"), wxOK | wxICON_INFORMATION, this);
};
