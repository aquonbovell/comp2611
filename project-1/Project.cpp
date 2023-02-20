//
//  Skeleton-01.cpp
//  COMP2611 - Project #1
//
//  Created by Aquon Bovell on 02/15/2023.
//  Copyright (c) 2023 University of the West Indies. All rights reserved.
//

// ==============================================================================
/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// the ADTs header files
#include "Queue.h"
#include "Deque.h"
#include "PQueue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>

using std::fstream;

// using namespace std;

// Global pointers for the ADT containers
Queue *q = new Queue();
Deque *d = new Deque();
PriorityQueue *pq = new PriorityQueue();
Stack *s = new Stack();

// Other miscellaneous functions' protypes, if required

// Include the ADTs header files

// Global pointers for the ADT containers

/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with
    the function to execute the program
*************************************************************************************
*************************************************************************************/
class ProjectApp : public wxApp
{
  virtual bool OnInit();
};

/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class
     also will ALL the events handlers be declared
*************************************************************************************
*************************************************************************************/
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

  // Function for Queue Menu Item
  void OnCreateQueue(wxCommandEvent &event);
  void OnDisplayAllQueue(wxCommandEvent &event);
  void OnShowHeadQueue(wxCommandEvent &event);
  void OnShowTailQueue(wxCommandEvent &event);
  void OnDequeueQueue(wxCommandEvent &event);

  // Function for Deque Menu Item
  void OnCreateDeque(wxCommandEvent &event);
  void OnDisplayAllDeque(wxCommandEvent &event);
  void OnShowHeadDeque(wxCommandEvent &event);
  void OnShowTailDeque(wxCommandEvent &event);
  void OnDequeueHeadDeque(wxCommandEvent &event);
  void OnDequeueTailDeque(wxCommandEvent &event);

  // Function for Priority Queue Menu Item
  void OnCreatePriorityQueue(wxCommandEvent &event);
  void OnDisplayAllPriorityQueue(wxCommandEvent &event);
  void OnShowHeadPriorityQueue(wxCommandEvent &event);
  void OnShowTailPriorityQueue(wxCommandEvent &event);
  void OnDequeuePriorityQueue(wxCommandEvent &event);

  // Function for Stack Menu Item
  void OnCreateStack(wxCommandEvent &event);
  void OnDisplayAllStack(wxCommandEvent &event);
  void OnShowHeadStack(wxCommandEvent &event);
  void OnShowTailStack(wxCommandEvent &event);
  void OnPopStack(wxCommandEvent &event);

  // Public attributes
  wxTextCtrl *MainEditBox;
  wxTextCtrl *filenameTextBox;
  wxString CurrentDocPath; // The Path to the file we have open
};

/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives
*************************************************************************************
*************************************************************************************/
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
  ID_CreateQueue,
  ID_DisplayAllQueue,
  ID_ShowHeadQueue,
  ID_ShowTailQueue,
  ID_DequeueQueue,
  ID_CreateDeque,
  ID_DisplayAllDeque,
  ID_ShowHeadDeque,
  ID_ShowTailDeque,
  ID_DequeueHeadDeque,
  ID_DequeueTailDeque,
  ID_CreatePriorityQueue,
  ID_DisplayAllPriorityQueue,
  ID_ShowHeadPriorityQueue,
  ID_ShowTailPriorityQueue,
  ID_DequeuePriorityQueue,
  ID_CreateStack,
  ID_DisplayAllStack,
  ID_ShowHeadStack,
  ID_ShowTailStack,
  ID_PopStack,
};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile) // File Menu
EVT_MENU(ID_Display, ProjectFrame::OnDisplay)
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)

// Events for the Queue
EVT_MENU(ID_CreateQueue, ProjectFrame::OnCreateQueue)
EVT_MENU(ID_DisplayAllQueue, ProjectFrame::OnDisplayAllQueue)
EVT_MENU(ID_ShowHeadQueue, ProjectFrame::OnShowHeadQueue)
EVT_MENU(ID_ShowTailQueue, ProjectFrame::OnShowTailQueue)
EVT_MENU(ID_DequeueQueue, ProjectFrame::OnDequeueQueue)

// Events for the Deque
EVT_MENU(ID_CreateDeque, ProjectFrame::OnCreateDeque)
EVT_MENU(ID_DisplayAllDeque, ProjectFrame::OnDisplayAllDeque)
EVT_MENU(ID_ShowHeadDeque, ProjectFrame::OnShowHeadDeque)
EVT_MENU(ID_ShowTailDeque, ProjectFrame::OnShowTailDeque)
EVT_MENU(ID_DequeueHeadDeque, ProjectFrame::OnDequeueHeadDeque)
EVT_MENU(ID_DequeueTailDeque, ProjectFrame::OnDequeueTailDeque)

// Events for the Priority Queue
EVT_MENU(ID_CreatePriorityQueue, ProjectFrame::OnCreatePriorityQueue)
EVT_MENU(ID_DisplayAllPriorityQueue, ProjectFrame::OnDisplayAllPriorityQueue)
EVT_MENU(ID_ShowHeadPriorityQueue, ProjectFrame::OnShowHeadPriorityQueue)
EVT_MENU(ID_ShowTailPriorityQueue, ProjectFrame::OnShowTailPriorityQueue)
EVT_MENU(ID_DequeuePriorityQueue, ProjectFrame::OnDequeuePriorityQueue)

// Events for the Stack
EVT_MENU(ID_CreateStack, ProjectFrame::OnCreateStack)
EVT_MENU(ID_DisplayAllStack, ProjectFrame::OnDisplayAllStack)
EVT_MENU(ID_ShowHeadStack, ProjectFrame::OnShowHeadStack)
EVT_MENU(ID_ShowTailStack, ProjectFrame::OnShowTailStack)
EVT_MENU(ID_PopStack, ProjectFrame::OnPopStack)

END_EVENT_TABLE()

/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool ProjectApp::OnInit()
{
  // Create the main application window
  ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures"),
                                         wxPoint(50, 50),
                                         wxSize(840, 600));

  // Display the window
  frame->Show(TRUE);
  SetTopWindow(frame);

  return TRUE;
}

/************************************************************************************
*************************************************************************************
  Step 6:   Define the Constructor functions for the Frame class
*************************************************************************************
*************************************************************************************/
ProjectFrame::ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
  // Set the frame icon - optional
  // SetIcon(wxIcon(wxT("Icon.xpm")));

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
  menuFile->Append(ID_OpenFile, wxT("&Open File..."), wxT("Open an Existing file"));
  menuFile->Append(ID_Display, wxT("&Display File..."), wxT("Display contents of opened file"));
  menuFile->Append(ID_Save, wxT("&Save"), wxT("Save opened file"));
  menuFile->Append(ID_SaveAs, wxT("Save &As..."), wxT("Save display as a new file"));
  menuFile->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

  // Append the sub-menu items to the Queue Main Menu item
  menuQueue->Append(ID_CreateQueue, wxT("Create &Queue"), wxT("Create a Queue"));
  menuQueue->Append(ID_DisplayAllQueue, wxT("&Display All"), wxT("Display contents of the Queue"));
  menuQueue->Append(ID_ShowHeadQueue, wxT("Show &Head"), wxT("Show the first element"));
  menuQueue->Append(ID_ShowTailQueue, wxT("Show &Tail"), wxT("Show the last element"));
  menuQueue->Append(ID_DequeueQueue, wxT("&Dequeue"), wxT("Remove the first item"));

  // Append the sub-menu items to the Deque Main Menu item
  menuDeque->Append(ID_CreateDeque, wxT("Create &Deque"), wxT("Create a Deque"));
  menuDeque->Append(ID_DisplayAllDeque, wxT("&Display All"), wxT("Display contents of the Deque"));
  menuDeque->Append(ID_ShowHeadDeque, wxT("Show &Head"), wxT("Show the first element"));
  menuDeque->Append(ID_ShowTailDeque, wxT("Show &Tail"), wxT("Show the last element"));
  menuDeque->Append(ID_DequeueHeadDeque, wxT("&Dequeue Head"), wxT("Remove the first item"));
  menuDeque->Append(ID_DequeueTailDeque, wxT("&Dequeue Tail"), wxT("Remove the last item"));

  // Append the sub-menu items to the Queue Main Menu item
  menuPQueue->Append(ID_CreatePriorityQueue, wxT("Create &PQueue"), wxT("Create a PQueue"));
  menuPQueue->Append(ID_DisplayAllPriorityQueue, wxT("&Display All"), wxT("Display contents of the Queue"));
  menuPQueue->Append(ID_ShowHeadPriorityQueue, wxT("Show &Head"), wxT("Show the first element"));
  menuPQueue->Append(ID_ShowTailPriorityQueue, wxT("Show &Tail"), wxT("Show the last element"));
  menuPQueue->Append(ID_DequeuePriorityQueue, wxT("&Dequeue"), wxT("Remove the first item"));

  // Append the sub-menu items to the Queue Main Menu item
  menuStack->Append(ID_CreateStack, wxT("Create &Stack"), wxT("Create a Stack"));
  menuStack->Append(ID_DisplayAllStack, wxT("&Display All"), wxT("Display contents of the Queue"));
  menuStack->Append(ID_ShowHeadStack, wxT("Show &Head"), wxT("Show the first element"));
  menuStack->Append(ID_ShowTailStack, wxT("Show &Tail"), wxT("Show the last element"));
  menuStack->Append(ID_PopStack, wxT("&Pop"), wxT("Remove the first item"));

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
  //=========================================================================================
  //=========================== DO NOT CHANGE THE CODE IN THIS SECTION ======================
  //=========================================================================================

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
}

/************************************************************************************
*************************************************************************************
  Step 7:  Define member functions for the Frame class
*************************************************************************************
*************************************************************************************/

//===================================================================================
//=========== Definition for the File Functions =====================================
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

    // Set the Title
    SetTitle(wxString(wxT("COMP2611 - Data Structures : 417002714")));
  }
}

void ProjectFrame::OnSave(wxCommandEvent &event)
{
  // Save to the already-set path for the document
  MainEditBox->SaveFile(CurrentDocPath);
}

void ProjectFrame::OnSaveAs(wxCommandEvent &event)
{
  wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")),
                                              wxEmptyString, wxEmptyString,
                                              (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
                                              wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

  // Creates a Save Dialog with 4 file types
  if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
  {
    CurrentDocPath = SaveDialog->GetPath();

    // set the path of our current document to the file the user chose to save under
    MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

    // Set the Title to reflect the file open
    SetTitle(wxString(wxT("COMP2611 - Data Structures : 417002714")));
  }
}

void ProjectFrame::OnDisplay(wxCommandEvent &event)
{
  // Creates a "open file" dialog with 4 file types
  wxFileDialog *OpenDialog = new wxFileDialog(this, (wxT("Choose a file to open")),
                                              wxEmptyString, wxEmptyString,
                                              (wxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat|All files (*.*)|*.*")),
                                              wxFD_OPEN, wxDefaultPosition);

  MainEditBox->Clear();

  MainEditBox->LoadFile(CurrentDocPath);
}

void ProjectFrame::OnExit(wxCommandEvent &event)
{
  wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
  Close(TRUE); // Close the window
}

//===================================================================================
//=========== Definition for the Queue Functions ====================================
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

    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);

    q->createQueue(string(CurrentDocPath)); // Add the data to the Queue

    MainEditBox->LoadFile(CurrentDocPath); // Opens that file in the MainEditBox

    // Set the Title
    SetTitle(wxString(wxT("COMP2611 - Data Structures : 417002714")));
  }
}

void ProjectFrame::OnShowHeadQueue(wxCommandEvent &event)
{
  string value = q->showHead();

  filenameTextBox->Clear();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxValue);
}

void ProjectFrame::OnShowTailQueue(wxCommandEvent &event)
{
  string value = q->showTail();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxValue);
}

void ProjectFrame::OnDisplayAllQueue(wxCommandEvent &event)
{
  string records = q->displayAll();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxRecords);
}

void ProjectFrame::OnDequeueQueue(wxCommandEvent &)
{
  filenameTextBox->Clear();
  MainEditBox->Clear();
  q->dequeue();
}

//===================================================================================
//=========== Definition for the Deque Functions ====================================
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

    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);

    d->createDeque(string(CurrentDocPath)); // Add the data to the Queue

    MainEditBox->LoadFile(CurrentDocPath); // Opens that file in the MainEditBox

    // Set the Title
    SetTitle(wxString(wxT("COMP2611 - Data Structures : 417002714")));
  }
}

void ProjectFrame::OnShowHeadDeque(wxCommandEvent &event)
{
  string value = d->showHead();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxValue);
}

void ProjectFrame::OnShowTailDeque(wxCommandEvent &event)
{
  string value = d->showTail();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxValue);
}

void ProjectFrame::OnDisplayAllDeque(wxCommandEvent &event)
{
  string records = d->displayAll();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxRecords);
}

void ProjectFrame::OnDequeueHeadDeque(wxCommandEvent &)
{
  filenameTextBox->Clear();
  MainEditBox->Clear();
  d->dequeueHead();
}

void ProjectFrame::OnDequeueTailDeque(wxCommandEvent &)
{
  filenameTextBox->Clear();
  MainEditBox->Clear();
  d->dequeueTail();
}

//===================================================================================
//=========== Definition for the Priority Queue Functions ====================================
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

    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);

    pq->createPriorityQueue(string(CurrentDocPath)); // Add the data to the PriorityQueue

    MainEditBox->LoadFile(CurrentDocPath); // Opens that file in the MainEditBox

    // Set the Title
    SetTitle(wxString(wxT("COMP2611 - Data Structures : 417002714")));
  }
}

void ProjectFrame::OnShowHeadPriorityQueue(wxCommandEvent &event)
{
  string value = pq->showHead();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxValue);
}

void ProjectFrame::OnShowTailPriorityQueue(wxCommandEvent &event)
{
  string value = pq->showTail();

  filenameTextBox->Clear();
  MainEditBox->Clear();
  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxValue);
}

void ProjectFrame::OnDisplayAllPriorityQueue(wxCommandEvent &event)
{
  string records = pq->displayAll();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxRecords);
}

void ProjectFrame::OnDequeuePriorityQueue(wxCommandEvent &)
{
  filenameTextBox->Clear();
  MainEditBox->Clear();
  pq->dequeue();
}

//===================================================================================
//=========== Definition for the Priority Queue Functions ====================================
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

    // Clean up filename textbox and Display file name in filename textbox
    filenameTextBox->Clear();
    filenameTextBox->AppendText(CurrentDocPath);

    s->createStack(string(CurrentDocPath)); // Add the data to the Stack

    MainEditBox->LoadFile(CurrentDocPath); // Opens that file in the MainEditBox

    // Set the Title
    SetTitle(wxString(wxT("COMP2611 - Data Structures : 417002714")));
  }
}

void ProjectFrame::OnShowHeadStack(wxCommandEvent &event)
{
  string value = s->showHead();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxValue);
}

void ProjectFrame::OnShowTailStack(wxCommandEvent &event)
{
  string value = s->showTail();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxValue(value.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxValue);
}

void ProjectFrame::OnDisplayAllStack(wxCommandEvent &event)
{
  string records = s->displayAll();

  filenameTextBox->Clear();
  MainEditBox->Clear();

  // Display the string in the MainEditBox
  wxString wxRecords(records.c_str(), wxConvUTF8);

  MainEditBox->AppendText(wxRecords);
}

void ProjectFrame::OnPopStack(wxCommandEvent &)
{
  filenameTextBox->Clear();
  MainEditBox->Clear();
  s->pop();
}
