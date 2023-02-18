// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <fstream>
#include <string>

using namespace std;

#include "Deque.h"

Deque *dp = new Deque();

class ProjectApp : public wxApp
{
public:
  virtual bool OnInit();
};

class ProjectFrame : public wxFrame
{
public:
  ProjectFrame(const wxString &title);

private:
  void OnHello(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);
};

enum
{
  ID_Hello = 1
};

wxIMPLEMENT_APP(ProjectApp);

bool ProjectApp::OnInit()
{
  ProjectFrame *frame = new ProjectFrame(wxT("Minimal wxWidgets App"));
  frame->Show(true);
  return true;
}

ProjectFrame::ProjectFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{

  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                   "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  SetMenuBar(menuBar);

  CreateStatusBar();
  SetStatusText("Welcome to wxWidgets!");

  Bind(wxEVT_MENU, &ProjectFrame::OnHello, this, ID_Hello);
  Bind(wxEVT_MENU, &ProjectFrame::OnAbout, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &ProjectFrame::OnExit, this, wxID_EXIT);
}

void ProjectFrame::OnExit(wxCommandEvent &event)
{
  Close(true);
}

void ProjectFrame::OnAbout(wxCommandEvent &event)
{
  wxMessageBox("This is a wxWidgets Hello World example",
               "About Hello World", wxOK | wxICON_INFORMATION);
}

void ProjectFrame::OnHello(wxCommandEvent &event)
{
  wxLogMessage("Hello world from wxWidgets!");
}
